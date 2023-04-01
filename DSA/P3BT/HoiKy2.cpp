#include <iostream>
#include <vector>
using namespace std;

int cumulative_sum(vector<int> a, int x) {
    int sum = 0;
    for (int i = 0; i < x; i++) {
        sum += a[i];
    }
    return sum;
}

void print(vector<int> a) {
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int max(vector<int> a) {
    int max = a[0];
    for (int i = 1; i < a.size(); i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

int main() {
    
    int n, k; cin >> n >> k;
    vector<int> a(n,0);
    vector<int> b(k,0);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    
    for (int i = 0; i < k-1; i++) {
        float old = sum;
        for (int j = 0; j < n; j++) {
            float avg = 1.0*(sum-cumulative_sum(b,i))/(k-i);
            int range = cumulative_sum(a,j) - cumulative_sum(b,i);
            
            if (abs(avg-range) < old) {
                old = abs(avg - range);
                b[i] = range;
                

            } else break;
        }
    }
    b[k-1] = sum - cumulative_sum(b,k-1);
    
    //print(b);
    cout << max(b);
    return 0;
}