#include <iostream>
using namespace std;
#define MAX 100


int main() {
    float A[MAX][MAX], B[MAX][MAX];
    int n, m;
    cin >> n >> m;
    for (int i = 0; i<n ; i++)
        for (int j = 0; j < m; j++)
            cin >> A[i][j];
    int a, b;
    cin >> a >> b;
    for (int i = 0; i<a ; i++)
        for (int j = 0; j < b; j++)
            cin >> B[i][j];

    if (n != a or m != b)
        cout << "Khong the cong duoc!" << '\n';
    else {
        cout << "Tong =" << '\n';
        for (int i = 0; i<n ; i++) {
            for (int j = 0; j < m; j++) {
                cout << A[i][j] + B[i][j] << ' ';
            }
            cout << '\n';
        }
    }
    if (n != a or m != b)
        cout << "Khong the tru duoc!" << '\n';
    else {
        cout << "Hieu =" << '\n';
        for (int i = 0; i<n ; i++) {
            for (int j = 0; j < m; j++) {
                cout << A[i][j] - B[i][j] << ' ';
            }
            cout << '\n';
        }
    }
    float sum = 0;
    if (m != a)
        cout << "Khong the nhan duoc!" << '\n';
    else {
        cout << "Tich =" << '\n';
        for (int i = 0; i<n ; i++) {
            for (int k = 0; k < b; k++) {
                for (int j = 0; j < m; j++) {
                    sum += A[i][j]*B[j][k];
                }
                cout << sum << ' ';
                sum = 0;
            }
            cout << '\n';
            


        }
                
            

    }
    return 0;
}