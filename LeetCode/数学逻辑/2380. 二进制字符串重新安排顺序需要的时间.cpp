// 2380. 二进制字符串重新安排顺序需要的时间
// 递推！！
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int secondsToRemoveOccurrences(string s) {
  int cnt0 = 0, result = 0;
  for (char c:s) {
    if (c == '0') {
      cnt0++;
    } else if (cnt0 != 0) {
      result = max(result + 1, cnt0);
    }
  }
  return result;
}