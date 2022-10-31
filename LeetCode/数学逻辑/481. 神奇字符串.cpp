// lc481. 神奇字符串
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int main() {
  int n;
  cin >> n;
  int cnt1 = 1, i = 1, curNum = 2, rep = 2;
  queue<int> q;
  while (i < n) {
    for (int t = 0; t < rep && i < n; t++) {
      i++;
      q.push(curNum);
      if (curNum == 1) cnt1++;
    }
    curNum = curNum == 1 ? 2 : 1;
    q.pop();
    rep = q.front();
  }
  cout << cnt1;
  return 0;
}