// 1024 Palindromic Number
#include <iostream>
#include <vector>
using namespace std;

int step(int *a, int digits)
{
    int t;
    int b[100] = {0};
    for (int i = 0; i < digits; i++)
    {
        t = a[i] + a[digits - i - 1] + b[i];
        b[i + 1] += t / 10;
        b[i] = t % 10;
    }
    if (b[digits])
        digits++;
    for (int i = 0; i < digits; i++)
        a[i] = b[i];
    return digits;
}

bool isPalind(int *a, int digits)
{
    for (int i = 0; i < digits / 2; i++)
        if (a[i] != a[digits - i - 1])
            return false;
    return true;
}

int toArray(long long k, int *a)
{
    int digits = 0;
    while (k > 0)
    {
        a[digits++] = k % 10;
        k /= 10;
    }
    return digits;
}

int main()
{
    long long num;
    int maxStep, curS = 0, a[100], digits;
    cin >> num >> maxStep;
    digits = toArray(num, a);
    while (!isPalind(a, digits) && curS < maxStep)
    {
        digits = step(a, digits);
        curS++;
    }
    for (int i = digits - 1; i >= 0; i--)
        cout << a[i];
    cout << endl
         << curS;
}