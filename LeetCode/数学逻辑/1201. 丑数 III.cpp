// 1201. 丑数 III
// 中等题，但思路还挺难想到的
// 二分+集合的容斥原理
// 另外还要考虑大数相乘过程中的溢出和long long，int之间转换的问题。

#include <iostream>
using namespace std;

int min(int a, int b) { return a < b ? a : b; }

int maxCommonFactor(int a, int b) {
    // a, b is positive;
    int k = a, t= b;
    while (t % k != 0) {
        int tmp = t;
        t = k;
        k = tmp % k;
    }
    return k;
}
long long minCommonMultiple(int a, int b) {
    return (long long) a / maxCommonFactor(a, b) * b;
}


int nthUglyNumber(int n, int a, int b, int c) {
    long long ab = minCommonMultiple(a,  b);
    long long ac = minCommonMultiple(a,  c);
    long long bc = minCommonMultiple(c,  b);
    long long abc = minCommonMultiple(ab,  c);

    const auto involvedUglyNumber = [=](long long k) -> int   {
        return k/a + k/b + k/c - k/ab - k/ac - k/bc + k/abc;
    };

    long long l=1, r = 2e9;
    while (l < r){
        long long mid = (l + r) / 2;
        if (involvedUglyNumber(mid) < n) 
            l = mid + 1;
        else r = mid;
    }
    return l;
}


int main() {
  int n=1000000000, a=2, b=217983653, c=336916467;
  cout << nthUglyNumber(n, a, b, c);
  return 0;
}