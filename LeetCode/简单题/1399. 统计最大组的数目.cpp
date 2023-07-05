// 1399. 统计最大组的数目
#include <unordered_map>
using namespace std;
int digitSum(int k) {
  int sum = 0;
  while (k) {
    sum += k % 10;
    k /= 10;
  }
  return sum;
}
int countLargestGroup(int n) {
  unordered_map<int, int> cnt;
  int maxSize = 0, result = 0;
  for (int i = 1; i <= n; i++) {
    cnt[digitSum(i)]++;
  }
  for (auto it : cnt) {
    if (it.second > maxSize) {
      maxSize = it.second;
      result = 1;
    } else if (it.second == maxSize)
      result++;
  }
  return result;
}