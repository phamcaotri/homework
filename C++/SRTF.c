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

// nếu đã thực thi hết process thì ngừng
    int index = 0; // dùng để lưu vị trí của process có burst time nhỏ nhất
    while (iTerminated < iNumberOfProcess || iReady > 0) {
        // nếu trong queue có process thì thực thi
        if (iReady > 0) {
            pushProcess(&iTerminated, TerminatedArray, ReadyQueue[index]);
            removeProcess(&iReady, index, ReadyQueue);
        } else {
        // nếu không có process nào trong queue thì thêm process tiếp theo vào queue
        // cập nhật thời gian và skip bước tìm burst time nhỏ nhất
        // vì không cần và nếu tìm thì sẽ sai kết quả
            pushProcess(&iReady, ReadyQueue, Input[0]);
            removeProcess(&iRemain, 0, Input);
            ReadyQueue[0].iStart = ReadyQueue[0].iArrival; 
            ReadyQueue[0].iFinish = ReadyQueue[0].iStart + ReadyQueue[0].iBurst; 
            ReadyQueue[0].iResponse = ReadyQueue[0].iStart - ReadyQueue[0].iArrival; 
            ReadyQueue[0].iWaiting = ReadyQueue[0].iResponse;
            ReadyQueue[0].iTaT = ReadyQueue[0].iFinish - ReadyQueue[0].iArrival; 
            continue;
        }
        // sau khi process chạy thì kiểm tra xem có process nào mới đến không
        while (iRemain > 0 && Input[0].iArrival <= TerminatedArray[iTerminated - 1].iFinish) {
            pushProcess(&iReady, ReadyQueue, Input[0]);
            removeProcess(&iRemain, 0, Input);
            // tìm process có burst time nhỏ nhất, bao gồm cả process đang chạy
            int lowest_burst = ReadyQueue[0].iBurst;
            index = 0;
            for (int i = 1; i < iReady; i++) {
                if (ReadyQueue[i].iBurst < lowest_burst) {
                    lowest_burst = ReadyQueue[i].iBurst;
                    index = i;
                }
            }
            // nếu process mới đến có burst time nhỏ hơn process đang chạy thì thay thế và cập nhật lại thời gian
            if (lowest_burst < TerminatedArray[iTerminated - 1].iBurst - ReadyQueue[index].iArrival) {
                // // tính thời gian burst còn lại của process đang chạy
                // TerminatedArray[iTerminated - 1].iBurst -= ReadyQueue[index].iArrival;
                // TerminatedArray[iTerminated - 1].iFinish = ReadyQueue[index].iStart + ReadyQueue[index].iArrival;
                // pushProcess(&iReady, ReadyQueue, TerminatedArray[iTerminated - 1]);
                // removeProcess(&iTerminated, iReady - 1, TerminatedArray);
                break;

                // pushProcess(&iTerminated, TerminatedArray, ReadyQueue[index]);
                // removeProcess(&iReady, index, ReadyQueue);
            }
            // cập nhật thời gian cho process mới đó
            ReadyQueue[index].iStart = TerminatedArray[iTerminated - 1].iFinish;
            ReadyQueue[index].iFinish = ReadyQueue[index].iStart + ReadyQueue[index].iBurst;
            ReadyQueue[index].iResponse = ReadyQueue[index].iStart - ReadyQueue[index].iArrival;
            ReadyQueue[index].iWaiting = ReadyQueue[index].iResponse;
            ReadyQueue[index].iTaT = ReadyQueue[index].iFinish - ReadyQueue[index].iArrival;
            
        }
        // tìm process có burst time nhỏ nhất, bao gồm cả process đang chạy
        int lowest_burst = ReadyQueue[0].iBurst;
        index = 0;
        for (int i = 1; i < iReady; i++) {
            if (ReadyQueue[i].iBurst < lowest_burst) {
                lowest_burst = ReadyQueue[i].iBurst;
                index = i;
            }
        }
        // nếu process mới đến có burst time nhỏ hơn process đang chạy thì thay thế và cập nhật lại thời gian
        if (lowest_burst < TerminatedArray[iTerminated - 1].iBurst - ReadyQueue[index].iArrival) {
            // tính thời gian burst còn lại của process đang chạy
            TerminatedArray[iTerminated - 1].iBurst -= ReadyQueue[index].iArrival;
            TerminatedArray[iTerminated - 1].iFinish = ReadyQueue[index].iStart + ReadyQueue[index].iArrival;
            pushProcess(&iReady, ReadyQueue, TerminatedArray[iTerminated - 1]);
            // removeProcess(&iTerminated, iReady - 1, TerminatedArray);


            // pushProcess(&iTerminated, TerminatedArray, ReadyQueue[index]);
            // removeProcess(&iReady, index, ReadyQueue);
        }
        // cập nhật thời gian cho process mới đó
        ReadyQueue[index].iStart = TerminatedArray[iTerminated - 1].iFinish;
        ReadyQueue[index].iFinish = ReadyQueue[index].iStart + ReadyQueue[index].iBurst;
        ReadyQueue[index].iResponse = ReadyQueue[index].iStart - ReadyQueue[index].iArrival;
        ReadyQueue[index].iWaiting = ReadyQueue[index].iResponse;
        ReadyQueue[index].iTaT = ReadyQueue[index].iFinish - ReadyQueue[index].iArrival;

    }

    printf("\n===== FCFS Scheduling =====\n"); 
    exportGanttChart(iTerminated, TerminatedArray); 
 
    quickSort(TerminatedArray, 0, iTerminated - 1, SORT_BY_PID); 

    return 0; 
} 