// 5. 最长回文子串
#include <string>
using namespace std;
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int dp[1010][1010] = {0};
        for (int i = 0; i < s.size();i++){
            dp[i][i] = 1;
            for (int j = i - 1; j >= 0;j--){
                dp[j][i] = dp[j + 1][i];
                if (dp[j+1][i-1]==i-j - 1 && s[j]==s[i])
                    dp[j][i] = i - j + 1;
            }
        }
        int maxId = 0;
        for (int i = 1; i < s.size();i++){
            if (dp[0][i] > dp[0][maxId])
                maxId = i;
        }
        return s.substr(maxId - dp[0][maxId] + 1, dp[0][maxId]);
    }
};