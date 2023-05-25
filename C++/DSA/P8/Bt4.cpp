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

// ###INSERT CODE HERE -

struct Graph
{
    vector<vector<int>> g;
    map<string, int> m;
    vector<string> index;

    void nhap(int v, int e)
    {
        g = vector<vector<int>>(v, vector<int>(v, 0));
        for (int i = 0; i < v; i++)
        {
            string c;
            cin >> c;
            m[c] = i;
            index.push_back(c);
        }
        for (int i = 0; i < e; i++)
        {
            string x, y;
            cin >> x >> y;
            g[m[x]][m[y]] = 1;
        }
    }

    void myProcess(int n)
    {
        for (int k = 0; k < n; k++)
        {
            int num;
            cin >> num;
            switch (num)
            {
            case 1:
            {
                string x, y;
                cin >> x >> y;
                if (g[m[x]][m[y]] == 1)
                {
                    cout << "TRUE";
                }
                else
                {
                    cout << "FALSE";
                }
                break;
            }

            default:
            {
                string x;
                cin >> x;
                bool flag = false;
                for (int i = 0; i < g.size(); i++)
                {
                    if (g[m[x]][i] == 1)
                    {
                        cout << index[i] << " ";
                        flag = true;
                    }
                }
                if (flag == false)
                {
                    cout << "NONE";
                }
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
    int v, e, n;
    cin >> v >> e >> n;
    G.nhap(v, e);
    G.myProcess(n);
    return 0;
}
