// 42. 接雨水 - 逻辑法
#include <vector>
#include <cmath>
using namespace std;
class Solution
{
public:
    int trap(vector<int> &height)
    {
        vector<int> leftMax(height.size()), rightMax(height.size());
        int n = height.size(), sum=0;
        leftMax[0] = height[0];
        rightMax[n - 1] = height[n - 1];
        for (int i = 1; i < height.size();i++)
            leftMax[i] = max(leftMax[i - 1], height[i]);
        for (int i = n - 2; i >= 0;i--)
            rightMax[i] = max(rightMax[i + 1], height[i]);
        for (int i = 1; i < n - 1;i++)
            sum += min(leftMax[i], rightMax[i]) - height[i];
        return sum;
    }
};