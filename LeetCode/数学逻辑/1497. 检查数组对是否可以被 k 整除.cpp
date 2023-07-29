// 1497. 检查数组对是否可以被 k 整除
#include <iostream>
#include <vector>
using namespace std;

// 桶排, size=k, bin[i]表示除以k后余数为i的数字个数
// matchable <=> i in [1, k//2] bin[i] = bin[k-i] && bin[0] mod 2 == 0
bool canArrange(vector<int>& arr, int k) {
  vector<int> bin(k, 0);
  for (int a : arr) {
    bin[(a % k + k) % k]++;
  }
  for (int i = 1; i <= k / 2; i++) {
    if (bin[i] != bin[k-i]) return false;
  }
  return bin[0] % 2 == 0; 
}

int main() {
  vector<int> arr = {-1,1,-2,2,-3,3,-4,4};
  int k = 3;
  cout << canArrange(arr, k);
  return 0;
}