// 852. 山脉数组的峰顶索引
#include<iostream>
#include<vector>
using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {
  int l=0, r= arr.size();
  while (l < r) {
    int m = (l + r) / 2;
    if (arr[m] < arr[m + 1]) l = m + 1;
    else r = m;
  }
  return l;
}