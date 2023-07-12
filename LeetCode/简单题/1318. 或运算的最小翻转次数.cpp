// 1318. 或运算的最小翻转次数
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
int num2stack(int k, stack<int> &q) {
  while (k) {
    q.push(k % 2);
    k /= 2;
  }
  return q.size();
}
inline int getDigit(stack<int> &q, int cur) {
  if (cur <= q.size()) {
    int k = q.top();
    q.pop();
    return k;
  } else {
    return 0;
  }
}
int minFlips(int a, int b, int c) {
  int valueMap[3][2] = {{0, 1}, {1, 0}, {2, 0}};
  stack<int> qa, qb, qc;
  int cur=0, sum=0;
  cur = num2stack(a, qa);
  cur = max(cur, num2stack(b, qb));
  cur = max(cur, num2stack(c, qc));
  while (cur) {
    int digita = getDigit(qa, cur);
    int digitb = getDigit(qb, cur);
    int digitc = getDigit(qc, cur);
    sum += valueMap[digita + digitb][digitc];
    cur--;
  }
  return sum;
}
int main() {
  cout << minFlips(1, 2, 3);
}