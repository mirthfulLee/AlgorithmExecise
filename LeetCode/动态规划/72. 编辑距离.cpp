// 72. 编辑距离
#include <iostream>
#include <string>
using namespace std;

int minDistance(string word1, string word2)
{
    int dp[510][510] = {0};
    int l1 = word1.length(), l2 = word2.length();
    for (int i = 0; i <= l2; i++)
        dp[0][i] = i;
    for (int i = 1; i <= l1; i++)
    {
        dp[i][0] = i;
        for (int j = 1; j <= l2; j++)
        {
            if (word1[i - 1] == word2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j - 1] + 1,
                               min(dp[i][j - 1] + 1, dp[i - 1][j] + 1));
            }
        }
    }
    return dp[l1][l2];
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << minDistance(s1, s2);
}