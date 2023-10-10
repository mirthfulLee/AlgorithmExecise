// 875. 爱吃香蕉的珂珂
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

bool finishable(vector<int>& piles, int h, int k) {
  int sum = 0;
  for (int & p: piles) sum += (p + k - 1) / k;
  return sum <= h;
}

int maxPile(vector<int>& piles) {
  int maxP = piles[0];
  for (int & p:piles) if (p > maxP) {
    maxP = p;
  }
  return maxP;
}

int minEatingSpeed(vector<int>& piles, int h) {
  int l = 1, r = maxPile(piles);
  while (l < r) {
    int mid = (l + r) / 2;
    if (!finishable(piles, h, mid)) {
      l = mid + 1;
    }else {
      r = mid;
    }
  }
  return r;
}

int main() {
  vector<int> piles = {3,6,7,11};
  printf("%d", minEatingSpeed(piles, 8));
}