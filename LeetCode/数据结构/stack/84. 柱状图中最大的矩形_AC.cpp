// 84. 柱状图中最大的矩形
// 单调栈
#include <algorithm>
#include <functional>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
 public:
  int largestRectangleArea(vector<int>& heights) {
    heights.push_back(0);
    int result = 0, n = heights.size(), h, left;
    stack<int> st;
    for (int i = 0; i < n; ++i) {
      if (st.empty()) {
        st.push(i);
      } else {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
          h = heights[st.top()];
          st.pop();
          left = st.empty() ? 0 : st.top() + 1;
          result = max(result, h * (i - left));
        }
        st.push(i);
      }
    }
    return result;
  }
};