// 1045 Favorite Color Stripe
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, l;
vector<int> fav(210), stripe(10010);
int dp[10010][210];
int main()
{
    cin >> n;
    cin >> m;
    for (int i = 1; i <= m; i++)
        cin >> fav[i];
    cin >> l;
    for (int i = 1; i <= l; i++)
        cin >> stripe[i];
    for (int i = 1; i <= l; i++)
    {
        for (int j = 1; j <= m; j++)
            if (fav[j] == stripe[i])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + 1;
            else
                dp[i][j] = max(max(dp[i - 1][j], dp[i - 1][j - 1]), dp[i][j-1]);
    }
    cout << dp[l][m];
}