// 1068 Find More Coins
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
vector<int> coins, maxCoin, k;
int main()
{
    int n, target, s = 0, up;
    cin >> n >> target;
    coins.resize(n), maxCoin.resize(target + 1), k.resize(target + 1);
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    sort(coins.begin(), coins.end());
    for (int i = 0; i < n; i++)
    {
        s += coins[i];
        up = min(s, target);
        for (int j = up; j >= coins[i]; j--)
        {
            if ((j - coins[i] == 0 || k[j - coins[i]]) && k[j - coins[i]] + 1 >= k[j])
            {
                maxCoin[j] = coins[i];
                k[j] = k[j - coins[i]] + 1;
            }
        }
    }
    if (k[target]){
    stack<int> result;
    int t = target;
    while (t)
    {
        result.push(maxCoin[t]);
        t -= maxCoin[t];
    }
    cout << result.top();
    result.pop();
    while (!result.empty())
    {
        cout << ' ' << result.top();
        result.pop();
    }
    }else{
        printf("No Solution\n");
    }

}