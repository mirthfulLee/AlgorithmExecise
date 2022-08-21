// 1107 Social Clusters
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> represent(1010), father(1010), cnt(1010), clusters;
int n, k, h;

int findFather(int a)
{
    while (father[a] != a)
        a = father[a];
    return a;
}

void merge(int a, int b)
{
    int fa = findFather(a), fb = findFather(b);
    if (fa == fb)
        return;
    else
    {
        father[fb] = fa;
        cnt[fa] += cnt[fb];
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d:", &k);
        father[i] = i;
        cnt[i] = 1;
        for (int j = 0; j < k; j++)
        {
            cin >> h;
            if (represent[h] == 0)
            {
                represent[h] = i;
            }
            else
            {
                merge(represent[h], i);
            }
        }
    }
    for (int i = 1; i <= n;i++){
        if (father[i] == i){
            clusters.push_back(cnt[i]);
        }
    }
    sort(clusters.begin(), clusters.end());
    printf("%d\n", clusters.size());
    for (int i = clusters.size() - 1; i > 0;i--)
        printf("%d ", clusters[i]);
    printf("%d", clusters[0]);
}
