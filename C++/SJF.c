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
    int iRemain = iNumberOfProcess, iReady = 0, iTerminated = 
0; inputRandomProcess(iNumberOfProcess, Input);
    // inputProcess(iNumberOfProcess, Input); 
    mergeSort(Input, 0, iNumberOfProcess - 1, 
SORT_BY_ARRIVAL); 

// nếu đã thực thi hết process thì ngừng
    int index = 0; // dùng để lưu vị trí của process có burst time nhỏ nhất
    while (iTerminated < iNumberOfProcess) {
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
        }
        // tìm process có burst time nhỏ nhất
        int lowest_burst = ReadyQueue[0].iBurst;
        index = 0;
        for (int i = 1; i < iReady; i++) {
            if (ReadyQueue[i].iBurst < lowest_burst) {
                lowest_burst = ReadyQueue[i].iBurst;
                index = i;
            }
        }
        // cập nhật thời gian cho process mới đó
        ReadyQueue[index].iStart = TerminatedArray[iTerminated - 1].iFinish;
        ReadyQueue[index].iFinish = ReadyQueue[index].iStart + ReadyQueue[index].iBurst;
        ReadyQueue[index].iResponse = ReadyQueue[index].iStart - ReadyQueue[index].iArrival;
        ReadyQueue[index].iWaiting = ReadyQueue[index].iResponse;
        ReadyQueue[index].iTaT = ReadyQueue[index].iFinish - ReadyQueue[index].iArrival;


    }

    printf("\n===== SJF Scheduling =====\n"); 
    exportGanttChart(iTerminated, TerminatedArray); 
 
    mergeSort(TerminatedArray, 0, iTerminated - 1, 
SORT_BY_PID); 
 
    calculateAWT(iTerminated, TerminatedArray); 
    calculateATaT(iTerminated, TerminatedArray); 
     
    return 0; 
} 