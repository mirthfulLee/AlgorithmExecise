// 2657. 找到两个数组的前缀公共数组
#include <iostream>
#include <set>
#include <vector>
using namespace std;
template <typename T>
inline bool contains(set<T>& s, T v) {
  return s.find(v) != s.end();
}

vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
  set<int> cura, curb;
  int n = A.size(), cnt = 0;
  vector<int> result(n, 0);
  for (int i = 0; i < n; i++) {
    if (!contains(cura, A[i]) && contains(curb, A[i])) cnt++;
    if (contains(cura, B[i]) && !contains(curb, B[i])) cnt++;
    if (!contains(cura, A[i]) && !contains(curb, A[i]) &&
        !contains(cura, B[i]) && !contains(curb, B[i]) && 
        A[i] == B[i])
      cnt++;
    cura.insert(A[i]);
    curb.insert(B[i]);
    result[i] = cnt;
  }
  return result;
}

int main() {
  vector<int> A = {1,3,2,4};
  vector<int> B = {3,1,2,4};
  findThePrefixCommonArray(A, B);
}