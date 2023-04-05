#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class GameOfLifeMap {
    private:
        vector<vector<bool>> map;
        int m;
        int n;
    public:
        GameOfLifeMap(int m = 0, int n = 0) : m(m), n(n) {
            map.resize(m,vector<bool>(n));
            for (int i = 0; i < m ; i++) {
                for (int j = 0; j < n; j++) {
                    map[i][j] = 0;
                }
            }
        }
        void input(int m, int n) {
            this -> m = m;
            this -> n = n;
            map.resize(m,vector<bool>(n));
            for (int i = 0; i < m ; i++) {
                for (int j = 0; j < n; j++) {
                    int x; cin >> x;
                    map[i][j] = x;
                }
            }
        }
        void output() {
            for (int i = 0; i < m ; i++) {
                for (int j = 0; j < n; j++) {
                    cout << map[i][j] << ' ';
                }
                cout << '\n';
            }
        }
    private:
        bool isTrue(int i, int j) {
            if (i < 0 or i >= m) {
                return 0;
            }
            if (j < 0 or j >= n) {
                return 0;
            }
            return map[i][j];
        }
    
        int nB(int i, int j) {
            int nB = 0;
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    if (isTrue(i+x,j+y) and (x!= 0 or y != 0)) {
                        nB++;
                    }
                }
            }
            return nB;
        }
    public:
        void Generation(int life_time = 1) {
            vector<vector<bool>> next(map);
            for (int k = 0; k < life_time; k++) {
                for (int i = 0; i < m ; i++) {
                    for (int j = 0; j < n; j++) {
                        if (nB(i,j) < 2 or nB(i,j) > 3) {
                            next[i][j] =0;
                        }
                        if (map[i][j] == 0 and nB(i,j) == 3) {
                            next[i][j]=1;
                        }
                    }
                }
                map = next;
            }
            

        }



};

int main() {
    int m, n, k;
    cin >> m >> n;
    GameOfLifeMap game;
    game.input(m,n);
    cin >> k;
    game.Generation(k);
    game.output();

    return 0;
}
