#include <bits/stdc++.h>

using namespace std;

template <typename Type, typename String = string>
class Matrix {
    private:
        vector<vector<Type>> matrix;

        map<String, Type> m; // index string -> type
        vector<String> v; // index type -> string
    public:
        void init(int size, vector<String> characters) {
            matrix = vector<vector<Type>>(size, vector<Type>(size, 0));
            for (int i = 0; i < size; i++) {
                m[characters[i]] = i;
            }
            v = characters;
        }
        int size() {
            return matrix.size();
        }

        vector<Type>& operator[](String x) {
            return matrix[m[x]];
        }

        vector<Type>& operator[](Type x) {
            return matrix[x];
        }
        String operator()(int x) {
            return v[x];
        }
};

template <typename Type, typename String = string>
class Graph {
    private:
        Matrix<Type, String> graph;
    public:
        void Nhap() {
            int vertex;
            cin >> vertex;
            vector<String> characters(vertex);
            for (int i = 0; i < vertex; i++) {
                cin >> characters[i];
            }
            graph.init(vertex, characters);
            for (int i = 0; i < vertex; i++)
                for (int j = 0; j < vertex; j++) {
                    cin >> graph[i][j];
                }
        }
        void DFS(String begin, String end) {
            vector<pair<String, int>> this_vertex = {};
            stack<pair<String, int>> open = {};
            unordered_map<String, bool> close = {};
            bool is_find = false;
            Type length = 0;
            open.push({begin, 0});
            while (!open.empty()) {
                this_vertex.push_back(open.top());
                open.pop();
                String x = p.back().first;
                for (int i = 0; i < graph.Size(); i++) {
                    if (graph[x][i] > 0) {
                        if (close[x] == 0) {
                            open.push({graph[i][0], p.back().first});
                        }
                    }
                }
                if (x == end) {
                    find = true;
                    break;
                }
            }
            if (find) {
                cout << "DFS: ";
                for (int i = 0; i < p.size(); i++) {
                    cout << p[i].first << " ";
                }
                cout << endl;
            }
            else {
                cout << "DFS: Khong tim thay duong di" << endl;
            }
        }
};

int main() {
    Graph<int> graph;
    graph.Nhap();
    // graph.FindPath();
}