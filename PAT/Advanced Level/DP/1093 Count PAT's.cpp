// 1093 Count PAT's
#include <iostream>
#include <string>
using namespace std;

int dp[100010][3];
int main()
{
    string s, t = "PAT";
    cin >> s;
    dp[0][0] = s[0] == 'P' ? 1 : 0;
    for (int i = 1; i < s.length(); i++)
        dp[i][0] = s[i] == 'P' ? dp[i - 1][0] + 1 : dp[i - 1][0];
    for (int j = 1; j < 3; j++)
    {
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] == t[j])
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 1000000007;
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[s.length() - 1][2];
}