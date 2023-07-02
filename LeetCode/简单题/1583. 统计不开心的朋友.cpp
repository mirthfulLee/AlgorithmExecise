// 1583. 统计不开心的朋友
#include <iostream>
#include <vector>
using namespace std;
int unhappyFriends(int n, vector<vector<int>>& preferences,
                   vector<vector<int>>& pairs) {
  // 每个人的匹配对象
  vector<int> partner(n);
  for (int i = 0; i < n / 2; i++) {
    partner[pairs[i][0]] = pairs[i][1];
    partner[pairs[i][1]] = pairs[i][0];
  }
  // 两两匹配的满意度（优先级）以及每个人的匹配满意度（优先级）
  vector<int> score(n);
  vector<vector<int>> priority(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1; j++) priority[i][preferences[i][j]] = j;
    score[i] = priority[i][partner[i]];
  }
  // 统计
  int sum = 0;
  for (int x = 0; x < n; x++) {
    for (int j = 0; j < score[x]; j++) {
      int u = preferences[x][j];
      if (priority[u][x] < priority[u][partner[u]]) {
        sum++;
        break;
      }
    }
  }
  return sum;
}

int main() {
}