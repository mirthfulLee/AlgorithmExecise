// 1076 Forwards on Weibo
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector<set<int>> followers;
vector<bool> visited;
vector<int> dist;
int n, l, k, t, m, s;

int main()
{
    cin >> n >> l;
    followers.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            cin >> t;
            followers[t].insert(i);
        }
    }
    // 多次 BFS
    cin >> k;
    for (int tempK = 0; tempK < k; tempK++)
    {
        int cur, cnt = 0;
        queue<int> q;
        visited.assign(n + 1, false);
        dist.assign(n + 1, 16);
        cin >> s;
        dist[s] = 0;
        q.push(s);
        while (!q.empty() && dist[q.front()] <= l)
        {
            cur = q.front();
            q.pop();
            if (visited[cur]) continue;
            visited[cur] = true;
            cnt++;
            if (dist[cur] == l) continue;
            for (int f : followers[cur])
                if (!visited[f])
                {
                    q.push(f);
                    dist[f] = min(dist[cur] + 1, dist[f]);
                }
        }
        cout << cnt-1 << endl;
    }
}