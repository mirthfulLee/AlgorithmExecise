// 202012-1 期末预测之安全指数
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n, w, s, sum=0;
    cin >> n;
    for (int i = 0; i < n;i++)
    {
        cin >> w >> s;
        sum += w * s;
    }
    cout << max(sum, 0);
}