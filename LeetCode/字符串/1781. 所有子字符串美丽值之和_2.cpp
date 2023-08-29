// 1781. 所有子字符串美丽值之和
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int beautySum(string s) {
    int n = s.size(), sum = 0;
    vector<int> cnt(26);
    for (int start = 0; start < n; ++start) {
      cnt.assign(26, 0);
      int up = -1;
      for (int end = start; end < n; ++end) {
        int lo = n;
        cnt[s[end] - 'a']++;
        up = max(up, cnt[s[end] - 'a']);
        if (end - start < 2) continue;
        for (int i = 0; i < 26; i++) {
          if (cnt[i] > 0 && cnt[i] < lo) lo = cnt[i];
        }
        sum += up - lo;
      }
    }
    return sum;
  }
};