// 1067 Sort with Swap(0, i)
// 规律题，按照回路的顺序进行替换
// 如果回路不包含 0， 则需要额外替换一次。
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, cnt;
    cin >> n;
    vector<int> a(n);
    vector<bool> cor(n, false);
    cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int p = a[0];
    cor[0] = true;
    while (!cor[p])
    {
        cor[p] = true;
        p = a[p];
        cnt++;
    }
    p = 1;
    while (p < n)
    {
        while (p < n && cor[p])
            p++;
        if (p >= n)
            break;
        if (p == a[p])
        {
            cor[p] = true;
            continue;
        }
        int cur = p;
        while (!cor[cur])
        {
            cor[cur] = true;
            cur = a[cur];
            cnt++;
        }
        cnt++;
    }
    cout << cnt;
}