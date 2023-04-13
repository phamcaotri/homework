"""
dịch đoạn code c++ này sang python:
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
"""

import math

#tạo class GameOfLifeMap
class GameOfLifeMap:
    #khởi tạo, tương tự constructor trong c++
    def __init__(self, m = 0, n = 0):
        self.m = m
        self.n = n
        self.map = []
        for i in range(m):
            self.map.append([])
            for j in range(n):
                self.map[i].append(0)
    #nhập
    def input(self, m, n):
        self.m = m
        self.n = n
        self.map = []
        # cho phép nhập trên cùng 1 dòng
        for i in range(m):
            self.map.append(list(map(int, input().split())))
    #xuất
    def output(self):
        for i in range(self.m):
            for j in range(self.n):
                print(self.map[i][j], end = ' ')
            print()
    #kiểm tra
    def isTrue(self, i, j):
        if i < 0 or i >= self.m:
            return 0
        if j < 0 or j >= self.n:
            return 0
        return self.map[i][j]
    #đếm số lượng số 1 xung quanh
    def nB(self, i, j):
        nB = 0
        for x in range(-1,2):
            for y in range(-1,2):
                if self.isTrue(i+x,j+y) and (x!= 0 or y != 0):
                    nB += 1
        return nB
    #tạo thế hệ kế tiếp
    def Generation(self, life_time = 1):
        for k in range(life_time):
            next = []
            for i in range(self.m):
                next.append([])
                for j in range(self.n):
                    if self.nB(i,j) < 2 or self.nB(i,j) > 3:
                        next[i].append(0)
                    elif self.map[i][j] == 0 and self.nB(i,j) == 3:
                        next[i].append(1)
                    else:
                        next[i].append(self.map[i][j])
            self.map = next

#chương trình chính
m, n = map(int, input().split())
game = GameOfLifeMap()
game.input(m,n)
k = int(input())
game.Generation(k)
game.output()

