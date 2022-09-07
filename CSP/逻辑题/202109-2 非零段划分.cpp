// 	202109-2 非零段划分
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, minS, maxS, result, maxV = 0;
    cin >> n;
    vector<int> a(n + 2), minCnt(10010), maxCnt(10010);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] > maxV)
            maxV = a[i];
    }
    int p = 1;
    a[0] = 0;
    a[n + 1] = 0;
    while (p < n)
    {
        while (p < n && a[p] <= a[p + 1])
            p++;
        maxCnt[a[p++]]++;

        while (p < n && a[p] >= a[p + 1])
            p++;
        if (p >= n)
            break;
        minCnt[a[p]]++;
    }
    minS = 0, maxS = 0, result = 0;
    for (int i = 0; i < maxV; i++)
    {
        minS += minCnt[i];
        maxS += maxCnt[i];
        if (1 + minS - maxS > result)
            result = 1 + minS - maxS;
    }
    cout << result;
}