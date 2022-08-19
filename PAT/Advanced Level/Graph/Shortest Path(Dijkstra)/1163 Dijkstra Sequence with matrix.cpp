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
    int dist, id;
};
bool operator < (node a, node b){
    return a.dist > b.dist;
}
vector<node> graph(1010);
int n, e, p, q, w, k;
vector<int> seq(1010);
int edge[1010][1010];

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
        for (int i = 1; i <= n;i++){
            if (!visited[i] && graph[i].dist > cur.dist+edge[cur.id][i]){
                graph[i].dist = cur.dist+edge[cur.id][i];
                minheap.push(graph[i]);
            }
        }
    }
    return true;
}

int main(){
    cin >> n >> e;
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= n;j++)
            edge[i][j] = INF;
    for (int i = 0; i < e; i++)
    {
        scanf("%d %d %d", &p, &q, &w);
        edge[p][q] = edge[q][p] = w;
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
