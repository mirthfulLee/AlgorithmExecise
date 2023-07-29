// 2140. 解决智力问题
// 简单的递推
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
long long max(long long &a, long long &b) {
  return a < b? b:a;
}
long long mostPoints(vector<vector<int>>& questions) {
  // 题i -》 题n-1 能够得到的最高分
  // 从右往左进行递推
  int n = questions.size();
  vector<long long> score(n, 0);
  score[n - 1] = questions[n-1][0];
  for (int i=n-2;i>=0;i--) {
    if (i + questions[i][1] + 1 < n)
      score[i] = score[i + questions[i][1] + 1] + questions[i][0];
    else score[i] = questions[i][0];
    score[i] = max(score[i], score[i+1]);
  }
  return score[0];
}
