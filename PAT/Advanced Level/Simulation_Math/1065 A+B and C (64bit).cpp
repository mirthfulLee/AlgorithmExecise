// 1065 A+B and C (64bit)
#include <iostream>
using namespace std;

int main()
{
    int n;
    const long long denom = 0x00ffffff;
    long long a, b, c, sumS, sumL;
    bool result;
    cin >> n;
    for (int i = 1; i <= n;i++){
        scanf("%lld %lld %lld", &a, &b, &c);
        // a+b-c
        sumL = a % denom + b % denom - c % denom;
        sumS = a / denom + b / denom - c / denom + sumL / denom ;
        sumL %= denom;
        result = (sumS > 0) || (sumS == 0 && sumL > 0);
        printf("Case #%d: %s\n", i, result ? "true" : "false");
    }
}