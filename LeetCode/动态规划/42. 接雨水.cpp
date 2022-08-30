// 42. 接雨水 - 逻辑法
#include <vector>
#include <cmath>
using namespace std;
class Solution
{
public:
    int trap(vector<int> &height)
    {
        vector<int> extreme;
        if (height.size() < 2)
            return 0;
        if (height[0] > height[1])
            extreme.push_back(0);
        for (int i = 1; i < height.size() - 1; i++)
        {
            if (height[i] >= height[i - 1] && height[i] >= height[i + 1])
                if (height[i] > height[i - 1] || height[i] > height[i + 1])
                    extreme.push_back(i);
        }
        if (height[height.size() - 1] > height[height.size() - 2])
            extreme.push_back(height.size() - 1);
        int extremeNum = extreme.size();
        if (extremeNum < 2)
            return 0;
        vector<int> increase, decrease;
        increase.push_back(extreme[0]);
        for (int i = 1; i < extremeNum; i++)
        {
            if (height[extreme[i]] >= height[increase.back()])
                increase.push_back(extreme[i]);
        }
        decrease.push_back(extreme[extremeNum - 1]);
        for (int i = extremeNum - 2; i >= 0 && extreme[i] >= increase.back(); i--)
        {
            if (height[extreme[i]] >= height[decrease.back()])
                decrease.push_back(extreme[i]);
        }

        int sum = 0, level;
        for (int i = 0; i < increase.size() - 1; i++)
        {
            level = height[increase[i]];
            for (int j = increase[i] + 1; j < increase[i + 1]; j++)
                sum += max(level - height[j], 0);
        }

        for (int i = 0; i < decrease.size() - 1; i++)
        {
            level = height[decrease[i]];
            for (int j = decrease[i + 1] + 1; j < decrease[i]; j++)
                sum += max(level - height[j], 0);
        }
        return sum;
    }
};