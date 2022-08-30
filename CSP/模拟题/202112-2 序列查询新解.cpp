// 202112-2 序列查询新解
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    long long sum = 0;
    int n, up;
    cin >> n >> up;
    vector<int> a(n + 2);
    a[0] = 0;
    a[n + 1] = up;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    long long step = up / (n + 1), f = 0, g = 0, l = 0;
    // FIXME： 这个边界很重要！！！
    while (l < up && f <= n)
    {
        if ((g + 1) * step <= a[f + 1])
        {
            sum += abs(f - g) * ((g + 1) * step - l);
            g++;
            l = step * g;
            if (l == a[f + 1])
                f++;
        }
        else
        {
            sum += abs(f - g) * (a[f + 1] - l);
            f++;
            l = a[f];
        }
    }
    cout << sum;
}