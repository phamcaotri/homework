        if (found) {
            vector<int> path;
            int u = end;
            int length = 0;
            while (u != begin) {
                path.push_back(u);
                length += m[trace[u]][u];
                u = trace[u];
            }
            path.push_back(begin);
            for (int i = path.size() - 1; i >= 0; i--) {
                cout << name[path[i]] << ' ';
            }
            cout << endl;
            cout << close.size() << ' ' << length << endl;
        } else {
            cout << "-unreachable-\n" << close.size() << ' ' << 0 << endl;
        }