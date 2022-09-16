// 202012-2 期末预测之最佳阈值
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct student
{
    int y, result;
};
int n;
vector<student> stuList;
vector<int> preSum;
bool cmp(student &a, student &b)
{
    return a.y == b.y ? a.result < b.result : a.y > b.y;
}

int main()
{
    cin >> n;
    stuList.resize(n);
    preSum.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> stuList[i].y >> stuList[i].result;
    }
    sort(stuList.begin(), stuList.end(), cmp);
    int maxMatched = -1, theta;
    preSum[0] = stuList[0].result;
    for (int i = 1; i < n; i++)
    {
        preSum[i] = preSum[i - 1] + stuList[i].result;
    }
    for (int i = 0; i < n; i++)
    {
        int matched = 2 * preSum[i] + n - i - 1 - preSum[n - 1];
        if (matched > maxMatched)
        {
            maxMatched = matched;
            theta = stuList[i].y;
        }
    }
    cout << theta;
}