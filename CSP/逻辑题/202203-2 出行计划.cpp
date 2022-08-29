// 	202203-2 出行计划
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m, k, t, c, q, passedNum, notDueNum;
    cin >> n >> m >> k;
    vector<int> start(n), due(n);
    for (int i = 0; i < n; i++)
    {
        cin >> t >> c;
        start[i] = t;
        due[i] = t - c;
    }
    sort(due.begin(), due.end());
    passedNum = 0;
    notDueNum = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> q;
        while (passedNum < n && start[passedNum] < q + k)
            passedNum++;
        while (notDueNum < n && due[notDueNum] < q + k)
            notDueNum++;
        cout << notDueNum - passedNum << endl;
    }
}