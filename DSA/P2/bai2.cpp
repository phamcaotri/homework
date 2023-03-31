#include <iostream>
#include <vector>
using namespace std;

vector<int> merge(vector<int> a, int n, vector<int> b, int m) {
    int i = 0, j = 0, k = 0;
    vector<int> c(n+m);
    while (i < n and j < m) {
        if (a[i] < b[j]) {
            c[k] = a[i];
            k++;
            i++;
        }
        else {
            c[k] = b[j];
            k++;
            j++;
        }
    }
    for (i;i < n; i++) {
        c[k] = a[i];
        k++;
    }
    for (j;j < m; j++) {
        c[k] = b[j];
        k++;
    }
    return c;
        
}

int main() {
    int n, m; 
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++)
        cin >> b[i];
    vector<int> c(n+m);
    c = merge(a, n, b, m);


    for (int i = 0; i < n+m; i++)
        cout << c[i] << " ";

    return 0;
}