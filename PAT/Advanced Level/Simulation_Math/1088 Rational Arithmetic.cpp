// 1088 Rational Arithmetic
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

long long maxCommonFactor(long long x, long long y)
{
    // FIXME: 辗转相除法
    long long a = abs(x), b = abs(y);
    while (a%b != 0){
        long long c = a % b;
        a = b;
        b = c;
    }
    return b;
}

string ariString(long long x, long long y)
{
    if (y == 0)
        return "Inf";
    if (x==0)
        return "0";
    if (y < 0)
        x *= -1, y *= -1;

    long long p, q, k, mcf = maxCommonFactor(x, y);
    k = x / y;
    q = y / mcf;
    p = x / mcf % q;
    string result = "";
    if (k)
        result += to_string(k);
    if (p)
        if (k)
            result += ' ' + to_string(abs(p)) + '/' + to_string(q);
        else
            result += to_string(p) + '/' + to_string(q);

    if (k < 0 || x < 0)
        result = '(' + result + ')';
    return result;
}
int main()
{
    long long a[3], b[3], k[3], mcf[3];
    scanf("%lld/%lld %lld/%lld", &a[0], &b[0], &a[1], &b[1]);
    mcf[0] = maxCommonFactor(a[0], b[0]);
    a[0] /= mcf[0], b[0] /= mcf[0];
    mcf[1] = maxCommonFactor(a[1], b[1]);
    a[1] /= mcf[1], b[1] /= mcf[1];
    string num1 = ariString(a[0], b[0]), num2 = ariString(a[1], b[1]);
    // addtion
    a[2] = a[0] * b[1] + a[1] * b[0], b[2] = b[0] * b[1];
    cout << num1 << " + " << num2 << " = " << ariString(a[2], b[2]) << endl;

    // subtract
    a[2] = a[0] * b[1] - a[1] * b[0], b[2] = b[0] * b[1];
    cout << num1 << " - " << num2 << " = " << ariString(a[2], b[2]) << endl;

    // multiple
    a[2] = a[0] * a[1], b[2] = b[0] * b[1];
    cout << num1 << " * " << num2 << " = " << ariString(a[2], b[2]) << endl;

    // division
    a[2] = a[0] * b[1], b[2] = a[1] * b[0];
    cout << num1 << " / " << num2 << " = " << ariString(a[2], b[2]) << endl;
}