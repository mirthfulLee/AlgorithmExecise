// 115. 不同的子序列
#include <iostream>
#include <string>
#include<vector>
using namespace std;
int numDistinct(string s, string t)
{
    int l1 = s.length(), l2 = t.length();
    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));
    for (int i = 0; i <= l1; i++)
        dp[i][0] = 1;
    for (int j = 1; j <= l2; j++)
    {
        for (int i = j; i <= l1; i++)
        {
            if (s[i - 1] == t[j - 1])
                // FIXME: 防止中间结果越界int
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1])%1000000000;
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[l1][l2];
}

int main()
{
    string s, t;
    cin >> s >> t;
    cout << numDistinct(s, t);
}