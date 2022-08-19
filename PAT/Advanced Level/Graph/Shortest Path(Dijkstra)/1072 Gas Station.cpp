// 1072 Gas Station
// 整合了minheap的Dijkstra算法
#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

struct node
{
    int id;
    vector<int> adj, cost;
};

const int inf = 0x0fffffff;
vector<int> dist(1100);
vector<node> graph(1100);
int n, m, D, k, l, t, x, y, bestSolution=-1;
double bestMinDist = -1, bestAvgDist = inf;
string p, q;

// stl中的有限队列默认为最大堆
bool operator<(node a, node b)
{
    return dist[a.id] > dist[b.id];
}

int point(string p)
{
    return p[0] == 'G' ? stoi(&p[1]) + n : stoi(p);
}

void Dijkstra(node s)
{
    // 若dist改变则将node传入minheap，即minheap中可能有重复的node
    // 插入minheap的次数 < 图中边的个数
    priority_queue<node> minheap;
    vector<bool> visted(1100, false);
    double curMinDist = inf, curAvgDist;

    minheap.push(s);
    while (!minheap.empty())
    {
        node cur = minheap.top();
        minheap.pop();
        if (visted[cur.id])
            continue;
        visted[cur.id] = true;
        if (cur.id <= n)
        {
            if (dist[cur.id] < curMinDist){
                curMinDist = dist[cur.id];
            }
            if (dist[cur.id] > D)
                return;
        }
        for (int i = 0; i < cur.adj.size(); i++)
        {
            int target = cur.adj[i];
            if (dist[target] > dist[cur.id] + cur.cost[i])
            {
                dist[target] = dist[cur.id] + cur.cost[i];
                minheap.push(graph[target]);
            }
        }
    }
    curAvgDist = 0;
    for (int i = 1; i <= n; i++)
    {
        // minheap 的形式可能会忽略 s没有和所有点都连通的情况
        if (dist[i] > D)
            return;
        curAvgDist += dist[i];
    }
    curAvgDist /= n;
    if ((curMinDist > bestMinDist) || (curMinDist == bestMinDist && curAvgDist < bestAvgDist))
    {
        bestSolution = s.id - n;
        bestMinDist = curMinDist;
        bestAvgDist = curAvgDist;
    }
}

int main()
{
    cin >> n >> m >> k >> D;
    for (int i = 0; i < k; i++)
    {
        cin >> p >> q >> l;
        x = point(p);
        y = point(q);
        graph[x].adj.push_back(y);
        graph[y].adj.push_back(x);
        graph[x].cost.push_back(l);
        graph[y].cost.push_back(l);
    }
    for (int i = 1; i <= n + m; i++)
        graph[i].id = i;
    for (int i = n + 1; i <= n + m; i++)
    {
        fill(dist.begin(), dist.end(), inf);
        dist[i] = 0;
        Dijkstra(graph[i]);
    }
    if (bestSolution > 0){
        // printf的保留位数采用的是截断；若要四舍五入，只需+0.05
        // printf("G%d\n%.1f %.1f", bestSolution, bestMinDist+0.05, bestAvgDist+0.05);
        // FIXME：奇怪的是，样例中采用的是四舍五入，但是实际数据若采用四舍五入最后一个点会得到错误答案
        printf("G%d\n%.1f %.1f", bestSolution, bestMinDist, bestAvgDist);
    }
    else
        printf("No Solution");
}
