//	202109-4 收集卡牌
// 状压DP：https://blog.csdn.net/LarsGyonX/article/details/122845329
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, k;
    double expect = 0;
    cin >> n >> k;
    int stateNum = 1 << n;
    vector<int> cnt(stateNum);
    vector<double> p(n);
    vector<vector<double>> dp(110, vector<double>(stateNum));
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    for (int i = 0; i < stateNum; i++)
    {
        int j = i;
        while (j)
            cnt[i]++, j &= j - 1;
    }
    dp[0][0] = 1;
    // FIXME: 必须先遍历状态，再遍历抽牌次数，否则只能90分？why？
    for (int j = 0; j < stateNum; j++)
    {
        for (int i = 0; i < 99; i++)
        {
            if (cnt[j] > i || cnt[j] + (i - cnt[j]) / k > n)
                continue;
            if (cnt[j] + (i - cnt[j]) / k == n)
            {
                expect += dp[i][j] * i;
                continue;
            }
            for (int cd = 0; cd < n; cd++)
            {
                if (j & (1 << cd))
                    dp[i + 1][j] += dp[i][j] * p[cd];
                else
                    dp[i + 1][j | (1 << cd)] += dp[i][j] * p[cd];
            }
        }
    }
    printf("%.10lf", expect);
}