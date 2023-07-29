// 816. 模糊坐标
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 判断在num第k位之后插入小数点, 那么该数字是否合法,
// k==num.length()-1则不插入小数点(小数点隐藏)
bool isLegalNum(string num, int k) {
  if (k == num.length() - 1) {
    return num[0] != '0' || num.length() == 1;
  }
  if (num.back() == '0')
    return false;
  else if (num[0] == '0' && k > 0)
    return false;
  else
    return true;
}

int main() {
  string s;
  cin >> s;
  vector<string> resultList;
  int slen = s.length();
  for (int comma = 1; comma < slen - 2; comma++) {
    string leftNum = s.substr(1, comma),
           rightNum = s.substr(comma + 1, slen - comma - 2);
    for (int leftK = 0; leftK < leftNum.length(); leftK++) {
      if (!isLegalNum(leftNum, leftK)) continue;
      for (int rightK = 0; rightK < rightNum.length(); rightK++)
        if (isLegalNum(rightNum, rightK)) {
          string result = "(";
          result += leftNum.substr(0, leftK + 1);
          if (leftK < leftNum.length() - 1) result += ".";
          result += leftNum.substr(leftK + 1);
          result += ", ";
          result += rightNum.substr(0, rightK + 1);
          if (rightK < rightNum.length() - 1) result += ".";
          result += rightNum.substr(rightK + 1);
          result += ")";
          resultList.push_back(result);
        }
    }
  }
  for (string result : resultList) cout << result << endl;
  // return resultList;
}