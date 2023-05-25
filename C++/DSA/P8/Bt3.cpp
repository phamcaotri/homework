/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include<iostream>
#include<vector>
using namespace std;

//###INSERT CODE HERE -

void inputGraph(vector<vector<int>>& g, int v, int e) {
    g =  vector<vector<int>>(v, vector<int>(v, 0));
    for (int i = 0; i < e; i++) {
        int x, y; cin >> x >> y;
        g[x-1][y-1] = 1;
    }
}

void process(vector<vector<int>>& g, int v, int n) {
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

int main()
{
	int v, e, n;
	cin >> v >> e >> n; //v: số đỉnh, e: số cạnh, n: số thao tác
	vector<vector<int> > G;

	inputGraph(G,v,e);
    process(G,v,n);

	return 0;
}


