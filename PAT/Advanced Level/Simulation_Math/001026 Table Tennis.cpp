// 1026 Table Tennis
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct player
{
    int arriveT, startT, vip, lasting;
    bool operator<(const player &b) const
    {
        return arriveT < b.arriveT;
    }
};
struct table
{
    int id, serveFinishT, vip;
    bool operator<(const table &b) const
    {
        return serveFinishT == b.serveFinishT ? id > b.id : serveFinishT > b.serveFinishT;
    }
};
int n, tableNum, k, m, hh, mm, ss, t, v;
vector<table> tables;
vector<player> info;
vector<int> cnt;

void printT(int t)
{
    printf("%02d:%02d:%02d", t / 3600, t % 3600 / 60, t % 60);
}

int main()
{
    cin >> n;
    info.resize(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &t, &info[i].vip);
        info[i].arriveT = hh * 3600 + mm * 60 + ss;
        info[i].lasting = 60 * t;
    }
    cin >> k >> m;
    tables.resize(k);
    cnt.resize(k);
    for (int i = 0; i < m; i++)
    {
        cin >> t;
        tables[t - 1].vip = 1;
    }

    sort(info.begin(), info.end());
    queue<int> q, vipQ;
    for (int i = 0; i < n; i++)
    {
        if (info[i].vip)
            vipQ.push(i);
        else
            q.push(i);
    }
    priority_queue<table> tableQ;
    priority_queue<table> vipTableQ;
    for (int i = 0; i < k; i++)
    {
        tables[i].id = i;
        if (tables[i].vip)
            vipTableQ.push(tables[i]);
        else
            tableQ.push(tables[i]);
    }
    while (!q.empty() || !vipQ.empty())
    {
        table cur;
        if (min(vipTableQ.top().serveFinishT, tableQ.top().serveFinishT) >
            min(info[q.front()].arriveT, info[vipQ.front()].arriveT))
        {
            // 有队伍
            if (vipTableQ.top().serveFinishT < tableQ.top().serveFinishT)
            {
                cur = vipTableQ.top();
                vipTableQ.pop();
            }
        }

        cnt[cur.id]++;
        int nextP;
        if ((!vipQ.empty()) &&
            (cur.vip || info[vipQ.front()].arriveT < info[q.front()].arriveT))
        {
            nextP = vipQ.front();
            vipQ.pop();
        }
        else
        {
            nextP = q.front();
            q.pop();
        }
        if (info[nextP].arriveT >= cur.serveFinishT)
        {
            info[nextP].startT = info[nextP].arriveT;
            cur.serveFinishT = info[nextP].arriveT + info[nextP].lasting;
        }
        else
        {
            info[nextP].startT = cur.serveFinishT;
            cur.serveFinishT += info[nextP].lasting;
        }
        tableQ.push(cur);
    }

    for (int i = 0; i < n; i++)
    {
        printT(info[0].arriveT);
        cout << ' ';
        printT(info[0].startT);
        printf(" %d\n", (info[0].startT - info[0].arriveT + 30) / 60);
    }
    for (int i = 0; i < k; i++)
    {
        if (i)
            cout << ' ';
        cout << cnt[i];
    }
}