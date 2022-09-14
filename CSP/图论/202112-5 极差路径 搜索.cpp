// 	202112-5 极差路径 搜索
// FIXME： 只有12分
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<set<int>> adj;
vector<bool> visited;
int n, k1, k2;
long long cnt = 0;
void tranverse(int start, int cur, int minV, int maxV)
{
    if (start - k1 > minV && start + k2 < maxV)
        return;
    visited[cur] = true;
    if (min(start, cur) - k1 <= minV && maxV <= max(start, cur) + k2 && start<=cur)
        cnt++;
    for (int neib: adj[cur])
        if (!visited[neib])
            tranverse(start, neib, min(neib, minV), max(neib, maxV));
    visited[cur] = false;
}

int main()
{
    cin >> n >> k1 >> k2;
    adj.resize(n + 1);
    visited.resize(n + 1, false);
    for (int i = 1; i < n; i++)
    {
        int p, q;
        scanf("%d %d", &p, &q);
        adj[p].insert(q);
        adj[q].insert(p);
    }
    for (int i = 1; i <= n;i++){
        tranverse(i, i, i, i);
    }
    cout << cnt;
}