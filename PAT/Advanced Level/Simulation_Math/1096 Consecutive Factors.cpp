// 1096 Consecutive Factors
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, maxCnt, maxL, up;

    cin >> n;
    maxCnt = 0;
    // 如果用i*i<n 要超时！？
    up = sqrt(n);
    for (int i = 2; i <= up; i++)
    {
        if (n % i)
            continue;
        int j = i + 1, cur = n / i;
        while (cur % j == 0)
        {
            cur /= j;
            j++;
        }
        if (j - i > maxCnt)
        {
            maxCnt = j - i;
            maxL = i;
        }
        // 早停机制 - （合理，但没啥效果）
        if (cur < i)
            break;
    }
    if (maxCnt == 0)
    {
        maxCnt = 1;
        maxL = n;
    }
    printf("%d\n", maxCnt);
    for (int i = 0; i < maxCnt - 1; i++)
    {
        printf("%d*", maxL + i);
    }
    printf("%d", maxL + maxCnt - 1);
}