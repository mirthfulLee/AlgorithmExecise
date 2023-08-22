// 816. 模糊坐标
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart,
                                    int cStart) {
  int v[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  int curRow = rStart, curCol = cStart, curV = -1, cnt = 0, total = rows * cols;
  vector<vector<int>> result(total, vector<int>(2));

  int stepSize = 0, leftStep = 0;
  bool largerStep = true;
  while (cnt < total) {
    if (curRow >= 0 && curRow < rows && curCol >= 0 && curCol < cols) {
      result[cnt][0] = curRow;
      result[cnt][1] = curCol;
      ++cnt;
    }
    if (leftStep == 0) {
      if (largerStep) ++stepSize;
      largerStep = !largerStep;
      leftStep = stepSize;
      curV = (curV + 1) % 4;
    }
    curRow += v[curV][0];
    curCol += v[curV][1];
    leftStep--;
  }
  return result;
}

int main() { spiralMatrixIII(5, 6, 1, 4); }