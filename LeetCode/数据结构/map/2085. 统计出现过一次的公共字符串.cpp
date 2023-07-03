// 2085. 统计出现过一次的公共字符串
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int countWords(vector<string>& words1, vector<string>& words2) {
  unordered_map<string, int> map1, map2;
  for (string &s :words1) map1[s]++;
  for (string &s :words2) map2[s]++;
  int cnt = 0;
  for (auto pair : map1) {
    if (pair.second == 1 && map2[pair.first] == 1) cnt++;
  }
  return cnt;
}

int main() {
  vector<string> words1 = {"leetcode", "is", "amazing", "as", "is"};
  vector<string> words2 = {"amazing", "leetcode", "is"};
  cout << countWords(words1, words2);
  return 0;
}