// 1070 Mooncake
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct cake
{
    double num;
    double totalP, avgP;
    bool operator<(const cake &b) const
    {
        return avgP > b.avgP;
    }
};

int main()
{
    int n, targetNum, sum = 0, p = 0;
    double profit = 0;
    cin >> n >> targetNum;
    vector<cake> cakes(n);
    for (int i = 0; i < n; i++)
    {
        cin >> cakes[i].num;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> cakes[i].totalP;
        cakes[i].avgP = cakes[i].totalP / cakes[i].num;
    }
    sort(cakes.begin(), cakes.end());
    while (sum < targetNum && p < n)
    {
        if (sum + cakes[p].num < targetNum)
        {
            sum += cakes[p].num;
            profit += cakes[p].totalP;
        }
        else
        {
            profit += cakes[p].avgP * (targetNum - sum);
            sum += targetNum;
        }
        p++;
    }
    printf("%0.2f", profit);
}
