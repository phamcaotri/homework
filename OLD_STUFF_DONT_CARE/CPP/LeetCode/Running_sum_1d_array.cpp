#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++)
        {
            nums[i] += nums[i-1];
        }
        return nums;
    }
};

int main()
{
    Solution s;
    vector<int> input, output;
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x; input.push_back(x);
    }
    output = s.runningSum(input);
    for (int i = 0; i < n; i++)
    {
        cout << output[i] << ' ';
    };
    return 0;
}