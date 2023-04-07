#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum_left = 0, sum_right = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            sum_right += nums[i];
        }
        if (sum_right == 0)
            return 0;
        for (int i = 1; i < nums.size(); i++)
        {
            sum_left += nums[i-1];
            sum_right -= nums[i];
            if (sum_left == sum_right)
                return i;
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> input;

    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x; input.push_back(x);
    }
    cout << s.pivotIndex(input);

 
    return 0;
}