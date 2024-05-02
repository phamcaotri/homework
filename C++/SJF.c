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
 
void calculateAWT(int n, PCB P[]) {
    int iSum = 0;
    for (int i = 0; i < n; i++) {
        iSum += P[i].iWaiting;
    }
    printf("Average Waiting Time: %.2f\n", (float)iSum / n);
}
 
void calculateATaT(int n, PCB P[]) {
    int iSum = 0;
    for (int i = 0; i < n; i++) {
        iSum += P[i].iTaT;
    }
    printf("Average Turnaround Time: %.2f\n", (float)iSum / n);
}
 
int main() { 
    PCB Input[10]; 
    PCB ReadyQueue[10]; 
    PCB TerminatedArray[10]; 
 
    int iNumberOfProcess; 
    printf("Please input number of Process: "); 
    scanf("%d", &iNumberOfProcess); 
    int iRemain = iNumberOfProcess, iReady = 0, iTerminated = 
0; 
 
    inputProcess(iNumberOfProcess, Input); 
    quickSort(Input, 0, iNumberOfProcess - 1, 
SORT_BY_ARRIVAL); 

    pushProcess(&iReady, ReadyQueue, Input[0]); 
    removeProcess(&iRemain, 0, Input); 
    ReadyQueue[0].iStart = ReadyQueue[0].iArrival; 
    ReadyQueue[0].iFinish = ReadyQueue[0].iStart + ReadyQueue[0].iBurst; 
    ReadyQueue[0].iResponse = ReadyQueue[0].iStart - ReadyQueue[0].iArrival; 
    ReadyQueue[0].iWaiting = ReadyQueue[0].iResponse; 
    ReadyQueue[0].iTaT = ReadyQueue[0].iFinish - ReadyQueue[0].iArrival; 
// nếu đã thực thi hết process thì ngừng
    int index = 0;
    while (iTerminated < iNumberOfProcess) {
        
        if (iReady > 0) {
            pushProcess(&iTerminated, TerminatedArray, ReadyQueue[index]);
            removeProcess(&iReady, index, ReadyQueue);
        } else {
            pushProcess(&iReady, ReadyQueue, Input[0]);
            removeProcess(&iRemain, 0, Input);
            continue;
        }
        if (iRemain > 0) {
            int i = 0;
            while (i < iRemain) {
                if (Input[i].iArrival <= TerminatedArray[iTerminated - 1].iFinish) {
                    pushProcess(&iReady, ReadyQueue, Input[i]);
                    removeProcess(&iRemain, i, Input);
                } else {
                    i++;
                }
            }
            int lowest_burst = ReadyQueue[0].iBurst;
            for (int i = 1; i < iReady; i++) {
                if (ReadyQueue[i].iBurst < lowest_burst) {
                    lowest_burst = ReadyQueue[i].iBurst;
                    index = i;
                }
            }
            ReadyQueue[index].iStart = TerminatedArray[iTerminated - 1].iFinish;
            ReadyQueue[index].iFinish = ReadyQueue[index].iStart + ReadyQueue[index].iBurst;
            ReadyQueue[index].iResponse = ReadyQueue[index].iStart - ReadyQueue[index].iArrival;
            ReadyQueue[index].iWaiting = ReadyQueue[index].iResponse;
            ReadyQueue[index].iTaT = ReadyQueue[index].iFinish - ReadyQueue[index].iArrival;

        }

    }

    printf("\n===== FCFS Scheduling =====\n"); 
    exportGanttChart(iTerminated, TerminatedArray); 
 
    quickSort(TerminatedArray, 0, iTerminated - 1, 
SORT_BY_PID); 
 
    calculateAWT(iTerminated, TerminatedArray); 
    calculateATaT(iTerminated, TerminatedArray); 
     
    return 0; 
} 