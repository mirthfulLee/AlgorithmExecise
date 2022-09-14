// 奇怪的打印机
// https://blog.muzi.fun/2022/09/14/%e5%8a%a8%e6%80%81%e8%a7%84%e5%88%92-%e5%a5%87%e6%80%aa%e7%9a%84%e6%89%93%e5%8d%b0%e6%9c%ba/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int l = s.length();
    vector<vector<int>> dp(l, vector<int>(l));
    for (int i = 0; i < l;i++)
        dp[i][i] = 1;
    for (int len = 2; len <= l;len++)
    {
        for (int i = 0; i <= l - len;i++)
        {
            int j = i + len - 1;
            dp[i][j] = dp[i + 1][j] + 1;
            for (int k = i + 1; k <= j;k++){
                if (s[i] == s[k])
                    dp[i][j] = min(dp[i][j], dp[i][k - 1] + dp[k][j] - 1);
            }
        }
    }
    cout << dp[0][l - 1];
}