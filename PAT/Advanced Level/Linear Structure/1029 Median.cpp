// 1029 Median
// median idx = (len - 1) / 2
#include <iostream>
#include <vector>
using namespace std;

typedef long long LL;

int n, m, p, q, len, v, median;
vector<LL> l1(200010), l2(200010);

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lld", &l1[i]);
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
        scanf("%lld", &l2[i]);
    median = (n + m + 1) / 2;
    p = 0;
    q = 0;
    while (p + q < median)
    {
        if ((q == m) || (l1[p] < l2[q] && p < n))
            p++;
        else
            q++;
    }
    if ((q > 0 && l1[p - 1] < l2[q - 1]) || (p == 0))
        cout << l2[q - 1];
    else
        cout << l1[p - 1];
}
