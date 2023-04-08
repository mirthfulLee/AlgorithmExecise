#include <iostream>
#include <string>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string> &strs) {
  int maxLen = 0, strNum = strs.size();
  for (int l = 0; l < strs[0].length(); l++) {
    char c = strs[0][l];
    for (int i = 1; i < strNum; i++) {
      if (strs[i].length() < l || strs[i][l] != c)
        return strs[0].substr(0, maxLen);
    }
    maxLen++;
  }
  return strs[0];
}

int main() {
  vector<string> strs = {"flower", "flo", "floght"};
  string output = longestCommonPrefix(strs);
  cout << output << endl;
}