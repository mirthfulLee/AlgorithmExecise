// 84. 柱状图中最大的矩形
// 暴力解法
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int largestRectangleArea(vector<int>& heights) {
    int result = 0, n = heights.size();
    for (int left = 0; left < n; ++left) {
      int height = 0x0fffffff;
      for (int right = left; right < n; ++right) {
        height = min(height, heights[right]);
        result = max(result, height * (right - left + 1));
        if (height * (n - left) < result) {
          break;
        }
      }
    }
    return result;
  }
};