/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

//###INSERT CODE HERE -

struct Graph {
    vector<vector<int>> g;
    map<string, int> m;
    vector<string> index;
    
    void nhap(int e) {
        int count = 0;
        for (int i = 0; i < e; i++) {
            string x, y; 
            cin >> x >> y;
            if (m.find(x) == m.end()) {
                m[x] = count;
                index.push_back(x);
                count++;
            }
            if (m.find(y) == m.end()) {
                m[y] = count;
                index.push_back(y);
                count++;
            }
            g.resize(count + 1, vector<int>(count+1));
            g[m[x]][m[y]] = 1;
        }
    }

    void myProcess(int n) {
        for (int k = 0; k < n; k++) {
            int num; cin >> num;
            switch (num)
            {
            case 1:
                {
                string x, y; cin >> x >> y;
                if (m.find(x) == m.end() or m.find(y) == m.end()) {
                    cout << "FALSE";
                    break;
                }
                if (g[m[x]][m[y]] == 1) {
                    cout << "TRUE";
                } else {
                    cout << "FALSE";
                }
                break;
                }
            
            default:
                {
                string x;
                cin >> x;
                if (m.find(x) == m.end()) {
                    cout << 0;
                    break;
                }
                int count = 0;
                for (int i = 0; i < g.size(); i++) {
                    if (g[m[x]][i] == 1) {
                        count ++;
                    }
                }
                cout << count;
                break;
                }
            }
            cout << '\n';
        }
    }
};

int main()
{
    Graph G;
    int e, n; cin >> e >> n;
    G.nhap(e);
    G.myProcess(n);
    return 0;
}

