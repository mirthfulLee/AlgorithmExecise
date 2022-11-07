// 1678. 设计 Goal 解析器
#include <iostream>
#include <string>
using namespace std;
string interpret(string command) {
  string result;
  int cur = 0;
  while (cur < command.length()) {
    if (command[cur] == 'G') {
      result += "G";
      cur++;
    } else if (command[cur + 1] == ')') {
      result += "o";
      cur += 2;
    } else {
      result += "al";
      cur += 4;
    }
  }
  return result;
}

int main() {
  string command;
  cin >> command;
  cout << interpret(command);
}