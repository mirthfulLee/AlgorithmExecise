// 202006-1 线性分类器
#include<iostream>
#include<vector>
using namespace std;
struct node
{
    int x, y;
    char type;
};
int n, m, a, b, c;
vector<node> p;

int main()
{
    cin >> n >> m;
    p.resize(n);
    for (int i = 0; i < n;i++)
    {
        cin >> p[i].x >> p[i].y >> p[i].type;
    }
    for (int i = 0; i < m;i++)
    {
        cin >> c >> a >> b;
        bool flag = true;
        int clusterOfNode0 = c + a * p[0].x + b * p[0].y;
        for (int j = 1; j < n;j++){
            int curCluster = c + a * p[j].x + b * p[j].y;
            if (p[j].type == p[0].type)
                flag &= !((clusterOfNode0 > 0) ^ (curCluster > 0));
            else
                flag &= (clusterOfNode0 > 0) ^ (curCluster > 0);
        }
        printf("%s\n", flag ? "Yes" : "No");
    }
}

/* 
9 3
1 1 A
1 0 A
1 -1 A
2 2 B
2 3 B
0 1 A
3 1 B
1 3 B
2 0 A
0 2 -3
-3 0 2
-3 1 1

 */