
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void merge(int* a, int n, int* b, int m, int *c) {
    int i = 0, j = 0, k = 0;
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
}

int main (){
    cin.tie(0);
    std::ios::sync_with_stdio(false);
    int n, m;
    int t; cin >> t;
    while (cin >> n >> m || t > 0){ 
        t--;
        int *a = new int [n], *b = new int[m], *c = new int[n+m];
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];

	merge(a, n, b, m, c);
	int nc = n + m;;
        for(int i = 0; i < nc; i++){
            cout << c[i] << " ";
        }
        delete c;
        cout << endl;
    }
}
