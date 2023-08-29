// 1781. 所有子字符串美丽值之和
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int beautySum(string s) {
    int n=s.size(), sum=0;
    vector<vector<int>> cnt(n);
    cnt[0].assign(26, 0);
    cnt[0][s[0] - 'a'] = 1;
    for (int i=1;i<n;i++) {
      cnt[i] = cnt[i-1];
      cnt[i][s[i] - 'a']++;
    }
    for (int len=3;len<=n;len++) {
      for (int start = 0; start+len-1<n; ++start) {
        int lo=n, up=0, end = start+len-1;
        for (int letter = 0;letter<26;++letter) {
          int freq = cnt[end][letter];
          if (start != 0) freq -= cnt[start - 1][letter];
          if (freq > up) up = freq;
          if (freq < lo && freq > 0) lo = freq;
        }
        sum += up - lo;
      }
    }
    return sum;
  }
};