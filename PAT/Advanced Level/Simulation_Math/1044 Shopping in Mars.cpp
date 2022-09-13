// 1044 Shopping in Mars
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, target, l, r, flag = 0, minDev = 9999999;
    cin >> n >> target;
    vector<int> d(n + 1), sum(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
        sum[i] = sum[i - 1] + d[i];
    }
    l = 1;
    for (int i = 1; i <= n; i++)
    {
        while (sum[i] - sum[l - 1] > target)
        {
            if (sum[i] - sum[l - 1] - target < minDev)
                minDev = sum[i] - sum[l - 1] - target;
            l++;
        }
        if (sum[i] - sum[l - 1] == target)
        {
            flag = 1;
            cout << l << '-' << i << endl;
        }
    }
    if (!flag)
    {
        l = 1;
        for (int i = 1; i <= n; i++)
        {
            while (sum[i] - sum[l - 1] - target > minDev)
                l++;
            if (sum[i] - sum[l - 1] - target == minDev)
            {
                cout << l << '-' << i << endl;
            }
        }
    }
}