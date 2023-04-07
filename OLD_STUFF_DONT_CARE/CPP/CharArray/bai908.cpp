#include <bits/stdc++.h>
using namespace std;
#define MAXR 300
#define MAXC 300

void input(float a[][MAXC],int &m, int &n)
{
    cin >> m >> n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    
}
float max_col(float a[][MAXC], int m, int n, int j)
{
    float max_number = 0;
    for (int i = 0; i < m; i++)
        max_number = max(max_number, a[i][j]);
    return max_number;
}

void max_c_array(float a[][MAXC], int m, int n)
{
    for (int j = 0; j < n; j++)
        cout << "Gia tri lon nhat tren cot " << j << " la: " << max_col(a, m, n, j) << "\n";

}


int main() {
    float a[MAXR][MAXC];
    int m = 0, n = 0;

    input(a, m, n);

    max_c_array(a, m, n);
    return 0;
}