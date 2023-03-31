#include <bits/stdc++.h>
using namespace std;

int so_sanh = 0;
int so_swap = 0;

int max(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

void draw(int a[], int n, int max_value, int pivot, int i, int j) {
    
    string buffer;
    system("cls");
    for (int k = max_value; k > 0; k--) {
        for (int l = 0; l < n; l++) {
            if (a[l] >= k) {
                if (l == pivot) {
                    if (a[l] < 10)
                        buffer += "\033[32m" + to_string(a[l]) + " " + "\033[0m";
                    else
                        buffer += "\033[32m" + to_string(a[l]) + "\033[0m";
                }
                else if (l == i || l == j) {
                    if (a[l] < 10)
                        buffer += "\033[31m" + to_string(a[l]) + " " + "\033[0m";
                    else
                        buffer += "\033[31m" + to_string(a[l]) + "\033[0m";
                }
                else {
                    if (a[l] < 10)
                        buffer += to_string(a[l]) + " ";
                    else
                        buffer += to_string(a[l]);
                }
            }
            else {
                buffer.append("  ");
            }

            buffer.append(" ");
        }
        buffer.append("\n");

    }
    for (int m = 0; m < n; m++) {
        buffer.append("---");
    }
    buffer += "so so sanh: "+ to_string(so_sanh) + ", so swap: " + to_string(so_swap);
    cout << buffer;
    this_thread::sleep_for(std::chrono::milliseconds(100));
}

void input(int a[], int n) {
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

void output(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
}

void QuickSort(int a[], int n ,int left, int right) {
    int max_value = max(a,n);
    int mid = a[(left+right)/2];
    int i = left, j = right;
    draw(a,n, max_value,(left+right)/2,i,j);
    while (i <= j) {
        so_sanh ++;
        while (a[i] < mid) {
            i ++;
            so_sanh ++;
            draw(a,n, max_value,(left+right)/2,i,j);
            
        }

        while (a[j] > mid) {
            j --;  
            so_sanh ++;
            draw(a,n, max_value,(left+right)/2,i,j);
            
        }

        if (i <= j) {
            so_swap ++;
            so_sanh ++;
            swap(a[i], a[j]);
            draw(a,n,max_value,(left+right)/2,i,j);

              
            i ++; j --;
        }
        
    }
    if (left < j) QuickSort(a,n ,left,j);
    if (right > i) QuickSort(a,n ,i,right);
}

int main() {
    int n;
    cin >> n;
    int *a = new int[n];
    input(a,n);
    QuickSort(a,n,0,n-1);
    //output(a,n);
    cin >> n;
    return 0;
}
