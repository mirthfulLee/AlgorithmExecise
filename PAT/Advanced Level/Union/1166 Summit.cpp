// 1166 Summit 暴力判断即可
// 注意set的遍历方法
#include<iostream>
#include<set>
using namespace std;

bool adj[250][250];
int n, m, p, q, k, l;

bool isGroup(set<int> area)
{
    int num = area.size();
    for (auto it = area.begin(); it != area.end();it++){
        // 注意next(it, 1)的用法
        for (auto it2 = next(it, 1); it2 != area.end();it2++){
            if (!adj[*it][*it2])
                return false;
        }
    }
    return true;
}

int isMax(set<int> area)
{
    for (int i = 1; i <= n;i++){
        if (area.find(i) == area.end())
        {
            bool connect = true;
            for (auto it = area.begin(); it != area.end();it++)
            {
                connect = connect && adj[i][*it];
            }
            if (connect)
                return i;
        }
    }
    return 0;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m;i++){
        cin >> p >> q;
        adj[p][q] = true;
        adj[q][p] = true;
    }
    cin >> k;
    for (int tempK = 1; tempK <= k;tempK++)
    {
        cin >> l;
        set<int> area;
        for (int i = 0; i < l;i++){
            cin >> p;
            area.insert(p);
        }
        if (!isGroup(area)){
            printf("Area %d needs help.\n", tempK);
        }else{
            p = isMax(area);
            if (p == 0){
                printf("Area %d is OK.\n", tempK);
            }
            else{
                printf("Area %d may invite more people, such as %d.\n", tempK, p);
            }
        }
    }
}
