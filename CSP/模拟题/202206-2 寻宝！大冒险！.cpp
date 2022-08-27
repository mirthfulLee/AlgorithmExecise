// 202206-2 寻宝！大冒险！
#include <iostream>
#include <set>
using namespace std;
struct point
{
    int x, y;
    // FIXME: 这里需要两个const
    bool operator < (const point & b) const{
        return x == b.x ? y < b.y : x < b.x;
    }
};
int n, l, s, cnt = 0, p, q;
set<point> tree_set;
int treasure[55][55];
point tmp;

int main()
{

    cin >> n >> l >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp.x >> tmp.y;
        tree_set.insert(tmp);
    }
    for (int i = s; i >= 0; i--)
        for (int j = 0; j <= s; j++)
            cin >> treasure[i][j];
    for (point tree : tree_set)
    {
        int x = tree.x, y = tree.y;
        if (x > l - s || y > l - s)
            continue;
        int flag = 1;
        for (int i = 0; i <= s; i++)
            for (int j = 0; j <= s; j++)
            {
                tmp.x = x + i;
                tmp.y = y + j;
                if (tree_set.find(tmp)!=tree_set.end())
                {
                    if (!treasure[i][j])
                        flag = 0;
                }
                else
                {
                    if (treasure[i][j])
                        flag = 0;
                }
            }
        cnt += flag;
    }
    cout << cnt;
}