// 1040 Longest Symmetric String
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    int l = s.length(), maxL = 0;
    vector<int> dp(l);
    for (int i = 0; i < l;i++){
        dp[i] = 1;
        if (i-dp[i-1] >=0 && s[i] == s[i-dp[i-1]])
            dp[i] = max(dp[i], dp[i - 1] + 1);
        if (i-dp[i-1]-1 >=0 && s[i] == s[i-dp[i-1]-1])
            dp[i] = max(dp[i], dp[i - 1] + 2);
        if (dp[i] > maxL)
            maxL = dp[i];
    }
    cout << maxL;
}