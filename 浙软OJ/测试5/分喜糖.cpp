// 聚类
// 背包 weight=所需糖， value=人数
#include <iostream>
#include <vector>
using namespace std;

vector<int> a(200), p(200), num(200), weight(200), value(200);
int n, m, k, x, y, group, dp[200][200];

int root(int x)
{
    while (x != p[x])
        x = p[x];
    return x;
}

void merge(int x, int y)
{
    int root_x = root(x);
    int root_y = root(y);
    if (root_x == root_y)
        return;
    if (num[root_x] < num[root_y])
    {
        p[root_x] = root_y;
        num[root_y] += num[root_x];
        a[root_y] += a[root_x];
    }
    else
    {
        p[root_y] = root_x;
        num[root_x] += num[root_y];
        a[root_x] += a[root_y];
    }
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        p[i] = i;
        num[i] = 1;
    }

    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> x >> y;
        merge(x - 1, y - 1);
    }
    group = 0;
    for (int i = 0; i < n; i++)
    {
        if (p[i] == i)
        {
            weight[group] = a[i];
            value[group] = num[i];
            group++;
        }
    }

    // 背包
    for (int i = weight[0]; i <= m; i++)
    {
        dp[0][i] = value[0];
    }

    for (int i = 1; i < group; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            if (j >= weight[i]){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - weight[i]] + value[i]);
            }
        }
    }
    cout << dp[group - 1][m];
}