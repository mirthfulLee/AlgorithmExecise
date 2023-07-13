// 1471. 数组中的 k 个最强值
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> getStrongest(vector<int>& arr, int k) {
  int n = arr.size();
  vector<int> result(k);
  sort(arr.begin(), arr.end(), [](int a, int b) -> bool { return a < b; });
  int l = 0, r = n - 1, m = arr[(n - 1) / 2];

  for (int i = 0; i < k; i++) {
    if (arr[r] - m >= m - arr[l])
      result[i] = arr[r--];
    else
      result[i] = arr[l++];
  }
  return result;
}
int main() {
  vector<int> arr {1,1,3,5,5};
  getStrongest(arr, 2);
}