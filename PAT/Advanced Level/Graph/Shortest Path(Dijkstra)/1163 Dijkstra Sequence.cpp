// 1163 Dijkstra Sequence
// 使用minheap进行优化
// 思路1：对于每个sequence的第一个vertice作为source进行一次Dijkstra，要求dist单调递增
// 最后一个点仍然超时
// 在Dijkstra的过程中，加入提前退出的判断，
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int INF = 0x0fffffff;
struct node
{
    int dist, id, degree = 0;
};
bool operator < (node a, node b){
    return a.dist > b.dist;
}
vector<node> graph(1010);
int n, e, p, q, w, k;
vector<int> seq(1010);
vector<int> adj[1010], cost[1010];

bool Dijkstra(int s){
    priority_queue<node> minheap;
    vector<bool> visited(1010, false);
    for (int i = 1; i <= n;i++)
        graph[i].dist = INF;
    graph[s].dist = 0;
    minheap.push(graph[s]);
    int cnt = 0;
    while(!minheap.empty()){
        node cur = minheap.top();
        minheap.pop();
        if (visited[cur.id]) continue;
        if (cur.dist < graph[seq[cnt]].dist)
            return false;
        cnt++;
        visited[cur.id] = true;
        for (int i = 0; i < cur.degree;i++){
            int t = adj[cur.id][i];
            if (!visited[t] && graph[t].dist > cur.dist+cost[cur.id][i]){
                graph[t].dist = cur.dist+cost[cur.id][i];
                minheap.push(graph[t]);
            }
        }
    }
    return true;
}

int main(){
    cin >> n >> e;
    for (int i = 1; i <= n;i++){
        adj[i].assign(n, 0);
        cost[i].assign(n, 0);
    }
        for (int i = 0; i < e; i++)
        {
            // FIXME: vector的push_back操作很耗时！！！！
            scanf("%d %d %d", &p, &q, &w);
            adj[p][graph[p].degree] = q;
            cost[p][graph[p].degree] = w;
            graph[p].degree++;
            adj[q][graph[q].degree] = p;
            cost[q][graph[q].degree] = w;
            graph[q].degree++;
        }
    for (int i = 1; i <= n;i++)
        graph[i].id = i;
    cin >> k;
    for (int tempK = 0; tempK < k;tempK++){
        for (int i = 0; i < n;i++)
            scanf("%d", &seq[i]);
        
        bool legal = Dijkstra(seq[0]);
        printf("%s\n", legal ? "Yes" : "No");
    }
}
