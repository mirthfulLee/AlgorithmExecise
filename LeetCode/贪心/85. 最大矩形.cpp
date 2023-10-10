// 85. 最大矩形
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
    for (int col = 0; col < cols; ++col) mat[0][col] = matrix[0][col] - '0';
    for (int row = 1; row < rows; ++row) {
      for (int col = 0; col < cols; ++col) {
        if (matrix[row][col] == '1') {
          mat[row][col] = mat[row - 1][col] + 1;
        }
      }
    }
    int row = 0, col = 0;
    while (row < rows) {
      if (mat[row][col] > 0) {
        int height = rows, len = 1;
        while (len <= cols - col && mat[row][col + len - 1]) {
          height = min(height, mat[row][col + len - 1]);
          result = max(result, height * len);
          ++len;
        }
        ++col;
      } else {
        while (col < cols && mat[row][col] == 0) {
          ++col;
        }
      }
      if (col >= cols) {
        ++row;
        col = 0;
      }
    }
    return result;
  }
};