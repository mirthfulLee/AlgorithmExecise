// 1727. 重新排列后的最大子矩阵
// 将列中连续的1转换为柱形来优化计算.
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int largestSubmatrix(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size(), result = 0;
    for (int i = 1; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (matrix[i][j] == 1) {
          matrix[i][j] += matrix[i - 1][j];
        }
      }
    }

    for (int row = 0; row < m; ++row) {
      sort(matrix[row].begin(), matrix[row].end(), greater<int>());
      int height = m;
      for (int len = 1; len <= n; ++len) {
        height = min(height, matrix[row][len - 1]);
        result = max(result, height * len);
      }
    }
    return result;
  }
};