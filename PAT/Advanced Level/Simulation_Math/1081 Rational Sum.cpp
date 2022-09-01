// 1081 Rational Sum
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long long maxCommonFactor(long long x, long long y)
{
    x = abs(x);
    y = abs(y);
    if (x <= 1 || y <= 1)
        return 1;
    long long c;
    while (x % y)
    {
        c = x % y;
        x = y;
        y = c;
    }
    return y;
}

int main()
{
    long long n, num, den, mcf;
    cin >> n;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld/%lld", &a[i], &b[i]);
    }
    num = a[0], den = b[0];
    for (int i = 1; i < n; i++)
    {
        mcf = maxCommonFactor(den, b[i]);
        num = b[i] / mcf * num + den / mcf * a[i];
        den = den / mcf * b[i];
        mcf = maxCommonFactor(num, den);
        num /= mcf, den /= mcf;
    }
    if (num < 0)
    {
        cout << "-";
        num = -num;
    }
    // FIXME: num==0的时候，输出0
    if (num >= den || num == 0)
    {
        cout << num / den;
        num %= den;
        if (num > 0)
            cout << ' ';
    }
    if (num > 0)
    {
        cout << num << '/' << den;
    }
}