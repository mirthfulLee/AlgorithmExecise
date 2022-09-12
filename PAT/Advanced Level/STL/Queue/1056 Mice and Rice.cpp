// 1056 Mice and Rice
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct participant
{
    int id, group, weight, rank, order;
};

vector<participant> list;
bool cmpViaOrder(participant &a, participant &b)
{
    return a.order < b.order;
}

int main()
{
    int n, groupSize, curRank = 1, groupNum, cnt, maxId, curN;
    cin >> n >> groupSize;
    vector<int> w(n);
    list.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    for (int i = 0; i < n; i++)
    {
        list[i].id = i;
        cin >> list[i].order;
        list[i].weight = w[list[i].order];
    }
    queue<participant> q;
    for (int i = 0; i < n; i++)
        q.push(list[i]);
    groupNum = (n + groupSize - 1) / groupSize;
    cnt = 0;
    maxId = 0;
    curN = n;
    while (!q.empty())
    {
        if (q.front().weight > list[maxId].weight)
            maxId = q.front().id;
        list[q.front().id].rank = groupNum + 1;
        q.pop();
        cnt++;
        if (cnt == curN)
        {
            curN = groupNum;
            groupNum = curN > 1?(groupNum + groupSize - 1) / groupSize:0;
            if (groupNum)
            {
                q.push(list[maxId]);
                maxId = q.front().id;
            }else {
                list[maxId].rank = 1;
            }
            cnt = 0;
        }
        else if (cnt % groupSize == 0)
        {
            q.push(list[maxId]);
            maxId = q.front().id;
        }
    }
    sort(list.begin(), list.end(), cmpViaOrder);
    for (int i = 0; i < n; i++)
    {
        if (i)
            cout << ' ';
        cout << list[i].rank;
    }
}