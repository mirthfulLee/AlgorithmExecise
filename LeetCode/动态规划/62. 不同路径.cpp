// 62. 不同路径
#include <iostream>
using namespace std;

int uniquePaths(int m, int n)
{
    int dp[100][100];
    for (int i = 0; i < n;i++)
        dp[0][i] = 1;
    for (int i = 1; i < m;i++)
    {
        dp[i][0] = 1;
        for (int j = 1; j < n;j++)
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }
    return dp[m - 1][n - 1];
}

int main()
{
    int m, n;
    cin >> m >> n;
    cout << uniquePaths(m, n);
}