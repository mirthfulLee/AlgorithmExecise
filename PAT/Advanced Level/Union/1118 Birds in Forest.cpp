// 1118 Birds in Forest
// 并查集，统计集合数量和元素总数
#include <iostream>
#include <vector>
using namespace std;
vector<int> group(10010);
int n, m, p, q, k, t;

int findGroup(int k)
{
    int p = k, t;
    while (k != group[k])
        k = group[k];
    while (p != k)
    {
        t = group[p];
        group[p] = k;
        p = t;
    }
    return k;
}

void merge(int a, int b)
{
    int ga = findGroup(a), gb = findGroup(b);
    if (ga != gb)
        group[ga] = gb;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> t;
            if (!group[t])
                group[t] = t;
            if (j > 0)
            {
                merge(p, t);
            }
            p = t;
        }
    }
    int cntBird = 0, cntGroup = 0;
    for (int i = 1; i <= 10000; i++)
    {
        if (group[i] > 0)
        {
            cntBird++;
            if (group[i] == i)
                cntGroup++;
        }
    }
    printf("%d %d\n", cntGroup, cntBird);
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> p >> q;
        printf("%s\n", findGroup(p) == findGroup(q) ? "Yes" : "No");
    }
}