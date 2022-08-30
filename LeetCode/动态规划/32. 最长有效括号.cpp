// 32. 最长有效括号
#include<string>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        int dp[30010] = {0}, maxL=0;
        for (int i = 1; i < s.size();i++){
            if (s[i]==')'){
                if (i-1-dp[i-1] >=0 && s[i-1-dp[i-1]]=='('){
                    dp[i] = dp[i - 1] + 2;
                    if (i-dp[i]>=0 && dp[i-dp[i]])
                        dp[i] += dp[i - dp[i]];
                }
                if (dp[i] > maxL)
                    maxL = dp[i];
            }
        }
        return maxL;
    }
};