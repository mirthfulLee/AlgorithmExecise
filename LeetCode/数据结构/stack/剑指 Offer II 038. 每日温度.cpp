// 剑指 Offer II 038. 每日温度
// 单调栈
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
  stack<int> st;
  vector<int> nextHigher(temperatures.size(), 0);
  int cur = 0;
  while (cur < temperatures.size()) {
    if (st.empty()) {
      st.push(cur);
      cur++;
      continue;
    }
    if (temperatures[cur] > temperatures[st.top()]) {
      nextHigher[st.top()] = cur - st.top();
      st.pop();
    }else {
      st.push(cur);
      cur++;
    }
  }
  return nextHigher;
}

int main() {
   
}