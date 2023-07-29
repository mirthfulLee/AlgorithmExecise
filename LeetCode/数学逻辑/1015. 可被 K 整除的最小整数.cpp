// 1015. 可被 K 整除的最小整数
// 找规律，逐渐增大规模；
#include <iostream>
#include <vector>
using namespace std;

int smallestRepunitDivByK(int k) {
  int n = 1, div = 9 * k;
  vector<bool> appeared(div, false);
  int tmp = 10;
  while (tmp - 1 < div) {
    tmp *= 10;
    n++;
  }
  int mod = (tmp - 1) % div;
  appeared[mod] = true;
  while (mod != 0) {
    n++;
    mod = (10 * mod + 9) % div;
    if (appeared[mod]) {
      break;
    }
    appeared[mod] = true;
  }
  return mod == 0 ? n : -1;
}

int main() {
  int k = 7;
  cout << smallestRepunitDivByK(k);
  return 0;
}