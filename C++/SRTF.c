#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
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

void merge(PCB P[], int l, int m, int r, int iCriteria) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    PCB L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = P[l + i];
    for (j = 0; j < n2; j++)
        R[j] = P[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        int bSwap = 0;
        if (iCriteria == SORT_BY_ARRIVAL) {
            bSwap = L[i].iArrival <= R[j].iArrival;
        } else if (iCriteria == SORT_BY_PID) {
            bSwap = L[i].iPID <= R[j].iPID;
        } else if (iCriteria == SORT_BY_BURST) {
            bSwap = L[i].iBurst <= R[j].iBurst;
        } else if (iCriteria == SORT_BY_START) {
            bSwap = L[i].iStart <= R[j].iStart;
        }
        if (bSwap) {
            P[k] = L[i];
            i++;
        } else {
            P[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        P[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        P[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(PCB P[], int l, int r, int iCriteria) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(P, l, m, iCriteria);
        mergeSort(P, m + 1, r, iCriteria);
        merge(P, l, m, r, iCriteria);
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

void inputRandomProcess(int n, PCB P[]) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        P[i].iPID = i + 1;
        P[i].iArrival = rand() % 21;
        P[i].iBurst = rand() % 11 + 2;
        P[i].iStart = 0;
        P[i].iFinish = 0;
        P[i].iResponse = 0;
        P[i].iWaiting = 0;
        P[i].iTaT = 0;
    }
    printf("\nRandom Process:\n");
    printProcess(n, P);
}


int main() { 
    PCB Input[10]; 
    PCB ReadyQueue[10]; 
    PCB TerminatedArray[10]; 

    int iNumberOfProcess; 
    printf("Please input number of Process: "); 
    scanf("%d", &iNumberOfProcess); 
    int iRemain = iNumberOfProcess, iReady = 0, iTerminated = 0; 
    // inputRandomProcess(iNumberOfProcess, Input);
    inputProcess(iNumberOfProcess, Input); 
    mergeSort(Input, 0, iNumberOfProcess - 1, SORT_BY_ARRIVAL); 

    int index = 0; // lưu vị trí của tiến trình có thời gian chạy ngắn nhất
    // ngừng khi đã thực thi hết tất cả các process và trong ready queue không còn process nào
    // điều kiện ready queue để tránh 1 process thực thi nhiều lần
    // khiến điều kiện trước đó không còn đúng
    while (iTerminated < iNumberOfProcess || iReady > 0) {
        // nếu trong queue có process thì thực thi process đó
        if (iReady > 0) {
            pushProcess(&iTerminated, TerminatedArray, ReadyQueue[index]);
            removeProcess(&iReady, index, ReadyQueue);
        // ngược lại thì thêm process tiếp theo vào queue,
        // điều này giúp tránh bug trường hợp các process có thời gian
        // cách xa nhau
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
        // kiểm tra xem có process mới đến không
        // dùng while để tránh trường hợp có nhiều process mới đến cùng 1 lúc
        while (iRemain > 0 && Input[0].iArrival <= TerminatedArray[iTerminated - 1].iFinish) {
            // thêm process mới đó vào queue
            pushProcess(&iReady, ReadyQueue, Input[0]);
            removeProcess(&iRemain, 0, Input);

            // tìm process có remain time nhỏ nhất
            int lowest_burst = ReadyQueue[0].iBurst;
            index = 0;
            for (int i = 1; i < iReady; i++) {
                if (ReadyQueue[i].iBurst < lowest_burst) {
                    lowest_burst = ReadyQueue[i].iBurst;
                    index = i;
                }
            }
            // nếu process đó có remain time nhỏ hơn remain time của process đang chạy
            // thì thực thi process đó và cập nhật thời gian cho process bị ngắt
            if (lowest_burst < TerminatedArray[iTerminated - 1].iBurst - (ReadyQueue[index].iArrival - TerminatedArray[iTerminated - 1].iStart)) {
                TerminatedArray[iTerminated - 1].iBurst -= ReadyQueue[index].iArrival;
                TerminatedArray[iTerminated - 1].iFinish = ReadyQueue[index].iStart + ReadyQueue[index].iArrival;
                pushProcess(&iReady, ReadyQueue, TerminatedArray[iTerminated - 1]);
                // gọi break khỏi vòng lặp nếu có process mới thay thế
                // để tránh update thời gian dòng dưới sai cho process đó (cập nhật 2 lần)
                break;
            }
            // nếu không có process nào có remain time nhỏ hơn thì cập nhật thời gian cho process tiếp theo
            // như thể SJF
            updateProcessTimes(&ReadyQueue[index], TerminatedArray[iTerminated - 1].iFinish);
        }
        // TH1: nếu process bị ngắt ở trên thì tìm và cập nhật thời gian cho process tiếp theo
        // TH2: nếu không có process nào bị ngắt thì tìm process có remain time nhỏ nhất
        // và xem nó có nhỏ hơn remain time của process đang chạy không
        int lowest_burst = ReadyQueue[0].iBurst;
        index = 0;
        for (int i = 1; i < iReady; i++) {
            if (ReadyQueue[i].iBurst < lowest_burst) {
                lowest_burst = ReadyQueue[i].iBurst;
                index = i;
            }
        }

        if (lowest_burst < TerminatedArray[iTerminated - 1].iBurst - (ReadyQueue[index].iArrival- TerminatedArray[iTerminated - 1].iStart)) {
            TerminatedArray[iTerminated - 1].iBurst -= ReadyQueue[index].iArrival;
            TerminatedArray[iTerminated - 1].iFinish = ReadyQueue[index].iStart + ReadyQueue[index].iArrival;
            pushProcess(&iReady, ReadyQueue, TerminatedArray[iTerminated - 1]);
        }

        updateProcessTimes(&ReadyQueue[index], TerminatedArray[iTerminated - 1].iFinish);
        // cập nhật lại brust cho process bị ngắt để tổng thời gian chạy = burst time
        TerminatedArray[iTerminated - 1].iBurst = ReadyQueue[index].iStart - TerminatedArray[iTerminated - 1].iStart;
    }

    printf("\n===== FCFS Scheduling =====\n"); 
    exportGanttChart(iTerminated, TerminatedArray); 
 
    mergeSort(TerminatedArray, 0, iTerminated - 1, SORT_BY_PID); 
    mergeProcesses(iTerminated, TerminatedArray);
    printProcess(iTerminated, TerminatedArray);
    calculateAverageWTandTaT(iTerminated, TerminatedArray, iNumberOfProcess);
    return 0; 
} 


// int main() { 
//     PCB Input[10]; 
//     PCB ReadyQueue[10]; 
//     PCB TerminatedArray[10]; 

//     int iNumberOfProcess; 
//     printf("Please input number of Process: "); 
//     scanf("%d", &iNumberOfProcess); 

//     int timeQuantum;
//     printf("Please input the time quantum: ");
//     scanf("%d", &timeQuantum);

//     int iRemain = iNumberOfProcess, iReady = 0, iTerminated = 0; 

//     inputProcess(iNumberOfProcess, Input); 
//     quickSort(Input, 0, iNumberOfProcess - 1, SORT_BY_ARRIVAL); 

//     int currentTime = 0;
//     while (iTerminated < iNumberOfProcess) {
//         while (iRemain > 0 && Input[0].iArrival <= currentTime) {
//             pushProcess(&iReady, ReadyQueue, Input[0]);
//             removeProcess(&iRemain, 0, Input);
//         }

//         if (iReady > 0) {
//             if (ReadyQueue[0].iBurst > timeQuantum) {
//                 ReadyQueue[0].iBurst -= timeQuantum;
//                 currentTime += timeQuantum;
//                 pushProcess(&iReady, ReadyQueue, ReadyQueue[0]);
//                 removeProcess(&iReady, 0, ReadyQueue);
//             } else {
//                 currentTime += ReadyQueue[0].iBurst;
//                 ReadyQueue[0].iFinish = currentTime;
//                 pushProcess(&iTerminated, TerminatedArray, ReadyQueue[0]);
//                 removeProcess(&iReady, 0, ReadyQueue);
//             }
//         } else {
//             currentTime++;
//         }
//     }

//     printf("\n===== Round Robin Scheduling =====\n"); 
//     exportGanttChart(iTerminated, TerminatedArray); 

//     quickSort(TerminatedArray, 0, iTerminated - 1, SORT_BY_PID); 
//     mergeProcesses(iTerminated, TerminatedArray);
//     printProcess(iTerminated, TerminatedArray);
//     calculateAverageWTandTaT(iTerminated, TerminatedArray, iNumberOfProcess);
//     return 0; 
// } 