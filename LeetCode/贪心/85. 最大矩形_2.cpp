// 85. 最大矩形
// 将矩形变为柱形图, 然后就可以参考 `84. 柱状图中最大的矩形` 解法
// 如果暴力解法不行, 需要进一步采用单调栈
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    int rows = matrix.size(), cols = matrix[0].size(), result = 0;
    vector<vector<int>> mat(rows, vector<int>(cols, 0));
    for (int row = 0; row < rows; ++row) {
      for (int col = 0; col < cols; ++col) {
        if (matrix[row][col] == '1') {
          mat[row][col] = row == 0 ? 1 : mat[row - 1][col] + 1;
        }
        int height = rows;
        for (int len = 1; len <= col + 1; ++len) {
          if (mat[row][col - len + 1] == 0) break;
          height = min(height, mat[row][col - len + 1]);
          result = max(result, height * len);
        }
      }
    }
    return result;
  }
};