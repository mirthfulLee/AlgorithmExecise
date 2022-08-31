// 91. 解码方法
#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool isLegalTwo(string s, int p){
    return s[p - 1] == '1' || (s[p - 1] == '2' && s[p] <= '6');
}
int numDecodings(string s)
{
    if (s[0] == '0')
        return 0;
    vector<int> dp(s.length(), 0);
    dp[0] = 1;
    if (s.length()== 1)
        return 1;
    if (s[1] != '0')
        dp[1]++;
    if (isLegalTwo(s, 1))
        dp[1]++;
    for (int i = 2; i < s.length();i++){
        if (isLegalTwo(s, i))
            dp[i] += dp[i - 2];
        if (s[i] != '0')
            dp[i] += dp[i - 1];
    }
    return dp.back();
}

int main()
{
    string s;
    cin >> s;
    cout << numDecodings(s);
}