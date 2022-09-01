// 1021 Deepest Root
#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

struct node
{
    vector<int> adj;
};
vector<node> graph;
set<int> result;
vector<bool> visted;
int n, p, q, maxHeight;

int countComponents()
{
    queue<int> nodeQ;
    visted.assign(n + 1, false);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visted[i])
        {
            cnt++;
            nodeQ.push(i);
            while (!nodeQ.empty())
            {
                int cur = nodeQ.front();
                visted[cur] = true;
                nodeQ.pop();
                for (int neib : graph[cur].adj)
                    if (!visted[neib])
                        nodeQ.push(neib);
            }
        }
    }
    return cnt;
}

void dfs(int s, int p, int len)
{
    visted[p] = true;
    for (int neib : graph[p].adj)
        if (!visted[neib])
            dfs(s, neib, len + 1);
    if (len > maxHeight)
    {
        maxHeight = len;
        result.clear();
        result.insert(p);
        result.insert(s);
    }
    if (len == maxHeight)
    {
        result.insert(p);
        result.insert(s);
    }
}

int main()
{
    cin >> n;
    graph.resize(n + 1);
    visted.resize(n + 1);
    for (int i = 1; i < n; i++)
    {
        cin >> p >> q;
        graph[p].adj.push_back(q);
        graph[q].adj.push_back(p);
    }
    int cnt = countComponents();
    if (cnt > 1)
    {
        printf("Error: %d components", cnt);
        return 0;
    }

    maxHeight = 0;
    for (int i = 1; i <= n; i++)
    {
        if (graph[i].adj.size() > 1 || result.find(i) != result.end())
            continue;
        visted.assign(n + 1, false);
        dfs(i, i, 1);
    }

    for (auto it = result.begin(); it != result.end(); it++)
        cout << *it << endl;
}
