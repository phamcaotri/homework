/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include<iostream>
using namespace std;

void inputGraph(bool*[], int);
void process(bool*[], int, int);



int main()
{
	int v, e, n; //v: số đỉnh, e: số cạnh, n: số thao tác
	cin >> v >> e >> n;

	bool **G; // ma trận toàn số 0, 1 nên kiểu bool hay int đều được


//###INSERT CODE HERE -
    G = new bool*[v];
    for (int i = 0; i < v; i++) {
        G[i] = new bool[v];
    }
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            G[i][j] = 0;
        }
    }

    inputGraph(G, e);
    process(G, n, v);

}

void inputGraph(bool* g[], int e) {
    for (int i = 0; i < e; i++) {
        int x, y; cin >> x >> y;
        g[x-1][y-1] = 1;
        g[y-1][x-1] = 1;
    }
}

void process(bool* g[], int n, int v) {
    for (int k = 0; k < n; k++) {
        int num; cin >> num;
        switch (num)
        {
        case 1:
            {
            int u, i; cin >> u >> i;
            if (g[u-1][i-1] == 1) {
                cout << "TRUE";
            } else {
                cout << "FALSE";
            }
            break;
            }
        
        default:
            {
            int u;
            cin >> u;
            bool flag = false;
            for (int i = 0; i < v; i++) {
                if (g[u-1][i] == 1) {
                    cout << i+1 << " ";
                    flag = true;
                }
            }
            if (flag == false) {
                cout << "NONE";
            }
            break;
            }
        }
        cout << '\n';
    }

}