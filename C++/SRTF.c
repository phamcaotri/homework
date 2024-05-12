#include <stdio.h> 
#include <stdlib.h> 
#define SORT_BY_ARRIVAL 0 
#define SORT_BY_PID 1 
#define SORT_BY_BURST 2 
#define SORT_BY_START 3 
 
typedef struct { 
    int iPID; 
    int iArrival, iBurst; 
    int iStart, iFinish, iWaiting, iResponse, iTaT; 
} PCB; 
 
void inputProcess(int n, PCB P[]) {
    for (int i = 0; i < n; i++) {
        printf("input P%d:\n", i + 1);
        P[i].iPID = i + 1;
        printf("input Arrival Time and Burst Time: ");
        scanf("%d %d", &P[i].iArrival, &P[i].iBurst);
    }
}


void printProcess(int n, PCB P[]) {
    printf("\nPID\tArrival\tBurst\tStart\tFinish\tWT\tRT\tTT\n");
    for (int i = 0; i < n; ++i) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", P[i].iPID, P[i].iArrival, P[i].iBurst,
               P[i].iStart, P[i].iFinish, P[i].iWaiting, P[i].iResponse, P[i].iTaT);
    }
}

 
void exportGanttChart (int n, PCB P[]) {
    printf("\nGantt Chart: ");
    for (int i = 0; i < n; i++) {
        printf("| %d P%d %d ", P[i].iStart, P[i].iPID, P[i].iFinish);
    }
    printf("|\n");
}
 
void pushProcess(int *n, PCB P[], PCB Q) {
    P[*n] = Q;
    (*n)++;
}
 
void removeProcess(int *n, int index, PCB P[]) {
    for (int i = index; i < *n - 1; i++) {
        P[i] = P[i + 1];
    }
    (*n)--;
}
 
void swapProcess(PCB *P, PCB *Q) {
    PCB temp = *P;
    *P = *Q;
    *Q = temp;
}

int partition (PCB P[], int low, int high, int iCriteria) {
    int pivot = 0;
    if (iCriteria == SORT_BY_ARRIVAL) {
        pivot = P[high].iArrival;
    } else if (iCriteria == SORT_BY_PID) {
        pivot = P[high].iPID;
    } else if (iCriteria == SORT_BY_BURST) {
        pivot = P[high].iBurst;
    } else if (iCriteria == SORT_BY_START) {
        pivot = P[high].iStart;
    }
    int i = (low - 1);
    for (int j = low; j<=high;j++) {
        int bSwap = 0;
        if (iCriteria == SORT_BY_ARRIVAL) {
            bSwap = P[j].iArrival < pivot;
        } else if (iCriteria == SORT_BY_PID) {
            bSwap = P[j].iPID < pivot;
        } else if (iCriteria == SORT_BY_BURST) {
            bSwap = P[j].iBurst < pivot;
        } else if (iCriteria == SORT_BY_START) {
            bSwap = P[j].iStart < pivot;
        }
        if (bSwap) {
            i++;
            swapProcess(&P[i], &P[j]);
        }
    }
    swapProcess(&P[i+1], &P[high]);
    return (i+1);
}
 
void quickSort(PCB P[], int low, int high, int iCriteria) {
    if (low < high) {
        int pi = partition(P, low, high, iCriteria);
        quickSort(P, low, pi - 1, iCriteria);
        quickSort(P, pi + 1, high, iCriteria);
    }
}

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

void calculateAverageWTandTaT(int n, PCB P[], int iTotalProcess) {
    float fTotalWaiting = 0, fTotalTaT = 0;
    for (int i = 0; i < iTotalProcess; i++) {
        fTotalWaiting += P[i].iWaiting;
        fTotalTaT += P[i].iTaT;
    }
    printf("\nAverage Waiting Time: %.2f\n", fTotalWaiting / iTotalProcess);
    printf("Average Turnaround Time: %.2f\n", fTotalTaT / iTotalProcess);
}

void mergeProcesses(int n, PCB P[]) {
    PCB *mergedProcesses = (PCB *)calloc(n, sizeof(PCB));
    int *count = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        int pid = P[i].iPID - 1; // Adjust for 0-indexed array
        if (count[pid] == 0) {
            mergedProcesses[pid] = P[i];
        } else {
            mergedProcesses[pid].iArrival = min(mergedProcesses[pid].iArrival, P[i].iArrival);
            mergedProcesses[pid].iBurst += P[i].iBurst;
            mergedProcesses[pid].iStart = min(mergedProcesses[pid].iStart, P[i].iStart);
            mergedProcesses[pid].iFinish = max(mergedProcesses[pid].iFinish, P[i].iFinish);
            mergedProcesses[pid].iResponse = min(mergedProcesses[pid].iResponse, P[i].iResponse);
            mergedProcesses[pid].iTaT = max(mergedProcesses[pid].iTaT, P[i].iTaT);
        }
        count[pid]++;
    }

    int j = 0;
    for (int i = 0; i < n; i++) {
        if (count[i] > 0) {
            mergedProcesses[i].iWaiting = mergedProcesses[i].iTaT - mergedProcesses[i].iBurst;
            P[j++] = mergedProcesses[i];
        }
    }

    free(mergedProcesses);
    free(count);
}

void updateProcessTimes(PCB *process, int finishTime) {
    process->iStart = finishTime;
    process->iFinish = process->iStart + process->iBurst;
    process->iResponse = process->iStart - process->iArrival;
    process->iWaiting = process->iResponse;
    process->iTaT = process->iFinish - process->iArrival;
}

int main() { 
    PCB Input[10]; 
    PCB ReadyQueue[10]; 
    PCB TerminatedArray[10]; 

    int iNumberOfProcess; 
    printf("Please input number of Process: "); 
    scanf("%d", &iNumberOfProcess); 
    int iRemain = iNumberOfProcess, iReady = 0, iTerminated = 0; 

    inputProcess(iNumberOfProcess, Input); 
    quickSort(Input, 0, iNumberOfProcess - 1, SORT_BY_ARRIVAL); 

    int index = 0;
    while (iTerminated < iNumberOfProcess || iReady > 0) {
        if (iReady > 0) {
            pushProcess(&iTerminated, TerminatedArray, ReadyQueue[index]);
            removeProcess(&iReady, index, ReadyQueue);
        } else {
            pushProcess(&iReady, ReadyQueue, Input[0]);
            removeProcess(&iRemain, 0, Input);
            ReadyQueue[0].iStart = ReadyQueue[0].iArrival; 
            ReadyQueue[0].iFinish = ReadyQueue[0].iStart + ReadyQueue[0].iBurst; 
            ReadyQueue[0].iResponse = ReadyQueue[0].iStart - ReadyQueue[0].iArrival; 
            ReadyQueue[0].iWaiting = ReadyQueue[0].iResponse;
            ReadyQueue[0].iTaT = ReadyQueue[0].iFinish - ReadyQueue[0].iArrival; 
            continue;
        }

        while (iRemain > 0 && Input[0].iArrival <= TerminatedArray[iTerminated - 1].iFinish) {
            pushProcess(&iReady, ReadyQueue, Input[0]);
            removeProcess(&iRemain, 0, Input);

            int lowest_burst = ReadyQueue[0].iBurst;
            index = 0;
            for (int i = 1; i < iReady; i++) {
                if (ReadyQueue[i].iBurst < lowest_burst) {
                    lowest_burst = ReadyQueue[i].iBurst;
                    index = i;
                }
            }

            if (lowest_burst < TerminatedArray[iTerminated - 1].iBurst - ReadyQueue[index].iArrival) {
                TerminatedArray[iTerminated - 1].iBurst -= ReadyQueue[index].iArrival;
                TerminatedArray[iTerminated - 1].iFinish = ReadyQueue[index].iStart + ReadyQueue[index].iArrival;
                pushProcess(&iReady, ReadyQueue, TerminatedArray[iTerminated - 1]);
                break;
            }

            updateProcessTimes(&ReadyQueue[index], TerminatedArray[iTerminated - 1].iFinish);
        }

        int lowest_burst = ReadyQueue[0].iBurst;
        index = 0;
        for (int i = 1; i < iReady; i++) {
            if (ReadyQueue[i].iBurst < lowest_burst) {
                lowest_burst = ReadyQueue[i].iBurst;
                index = i;
            }
        }

        if (lowest_burst < TerminatedArray[iTerminated - 1].iBurst - ReadyQueue[index].iArrival) {
            TerminatedArray[iTerminated - 1].iBurst -= ReadyQueue[index].iArrival;
            TerminatedArray[iTerminated - 1].iFinish = ReadyQueue[index].iStart + ReadyQueue[index].iArrival;
            pushProcess(&iReady, ReadyQueue, TerminatedArray[iTerminated - 1]);
        }

        updateProcessTimes(&ReadyQueue[index], TerminatedArray[iTerminated - 1].iFinish);
        TerminatedArray[iTerminated - 1].iBurst = ReadyQueue[index].iStart - TerminatedArray[iTerminated - 1].iStart;
    }

    printf("\n===== FCFS Scheduling =====\n"); 
    exportGanttChart(iTerminated, TerminatedArray); 
 
    quickSort(TerminatedArray, 0, iTerminated - 1, SORT_BY_PID); 
    mergeProcesses(iTerminated, TerminatedArray);
    printProcess(iTerminated, TerminatedArray);
    calculateAverageWTandTaT(iTerminated, TerminatedArray, iNumberOfProcess);
    return 0; 
} 


int main() { 
    PCB Input[10]; 
    PCB ReadyQueue[10]; 
    PCB TerminatedArray[10]; 

    int iNumberOfProcess; 
    printf("Please input number of Process: "); 
    scanf("%d", &iNumberOfProcess); 

    int timeQuantum;
    printf("Please input the time quantum: ");
    scanf("%d", &timeQuantum);

    int iRemain = iNumberOfProcess, iReady = 0, iTerminated = 0; 

    inputProcess(iNumberOfProcess, Input); 
    quickSort(Input, 0, iNumberOfProcess - 1, SORT_BY_ARRIVAL); 

    int currentTime = 0;
    while (iTerminated < iNumberOfProcess) {
        while (iRemain > 0 && Input[0].iArrival <= currentTime) {
            pushProcess(&iReady, ReadyQueue, Input[0]);
            removeProcess(&iRemain, 0, Input);
        }

        if (iReady > 0) {
            if (ReadyQueue[0].iBurst > timeQuantum) {
                ReadyQueue[0].iBurst -= timeQuantum;
                currentTime += timeQuantum;
                pushProcess(&iReady, ReadyQueue, ReadyQueue[0]);
                removeProcess(&iReady, 0, ReadyQueue);
            } else {
                currentTime += ReadyQueue[0].iBurst;
                ReadyQueue[0].iFinish = currentTime;
                pushProcess(&iTerminated, TerminatedArray, ReadyQueue[0]);
                removeProcess(&iReady, 0, ReadyQueue);
            }
        } else {
            currentTime++;
        }
    }

    printf("\n===== Round Robin Scheduling =====\n"); 
    exportGanttChart(iTerminated, TerminatedArray); 

    quickSort(TerminatedArray, 0, iTerminated - 1, SORT_BY_PID); 
    mergeProcesses(iTerminated, TerminatedArray);
    printProcess(iTerminated, TerminatedArray);
    calculateAverageWTandTaT(iTerminated, TerminatedArray, iNumberOfProcess);
    return 0; 
} 