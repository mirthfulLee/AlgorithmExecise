// 1033 To Fill or Not to Fill
// FIXME: 做了好久，这题是贪心不是dp！
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const double INF = 9999999;
struct station
{
    double pos, price;
};
bool cmp(station &a, station &b)
{
    return a.pos < b.pos;
}

int main()
{
    int n;
    double tankSize, dist, avgD, maxL;
    cin >> tankSize >> dist >> avgD >> n;
    maxL = tankSize * avgD;
    vector<station> stts(n);
    for (int i = 0; i < n; i++)
    {
        cin >> stts[i].price >> stts[i].pos;
    }
    sort(stts.begin(), stts.end(), cmp);
    if (stts[0].pos != 0)
    {
        printf("The maximum travel distance = %.2f", 0);
        return 0;
    }

    int cur = 0;
    double totalCost = 0, curTank = 0;
    station destination;
    destination.pos = dist;
    destination.price = 0;
    stts.push_back(destination);
    while (cur < n)
    {
        int next = cur + 1, j = cur + 1;
        while (j <= n && stts[j].pos - stts[cur].pos <= maxL)
        {
            if (stts[j].price < stts[next].price)
                next = j;
            if (stts[j].price < stts[cur].price)
                break;
            j++;
        }
        if (stts[next].pos - stts[cur].pos > maxL)
            break;
        if (stts[cur].price >= stts[next].price)
        {
            totalCost += ((stts[next].pos - stts[cur].pos) / avgD - curTank) * stts[cur].price;
            curTank = 0;
        }
        else
        {
            totalCost += (tankSize - curTank) * stts[cur].price;
            curTank = tankSize - (stts[next].pos - stts[cur].pos) / avgD;
        }
        cur = next;
    }
    if (cur < n)
        printf("The maximum travel distance = %.2f", stts[cur].pos + maxL);
    else
        printf("%.2f", totalCost);
}