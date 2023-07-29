// 816. 模糊坐标
// 第二次做这题， 虽然做了优化，但写的混乱
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool validSeg(string &s, int comma, int l, int r) {
  if (l < comma && s[comma] == '0') return false;
  if (s[s.size() - 2] == '0' &&  r < s.size() - 2) return false;
  return true;
}
string getString(string &s, int comma, int l, int r) {
  string res = "(";
  if (comma == l)
    res += s.substr(1, comma);
  else
    res += s.substr(1, l) + "." + s.substr(l+1, comma - l);
  res += ", ";
  if (r == s.size() - 2)
    res += s.substr(comma+1);
  else
    res += s.substr(comma+1, r - comma) + "." + s.substr(r+1);
  return res;
}
vector<string> ambiguousCoordinates(string s) {
  vector<string> result;
  int comma, l, r, len = s.size();
  for (comma = 1; comma <= len - 3; comma++) {
    for (l = 1; l <= comma; l++) {
      for (r = comma + 1; r < len - 1; r++) {
        if (validSeg(s, comma, l, r)) 
          result.push_back(getString(s, comma, l, r));
        if (s[comma + 1] == '0') break; // end loop because num b start with '0'
      }
      if (s[1] == '0') break; // end loop because num a start with '0'
    }
    
  }
  return result;
}

int main() {
  ambiguousCoordinates("(10023)");
}
