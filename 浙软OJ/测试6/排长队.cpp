// 排长队
#include <iostream>
#include <vector>
using namespace std;

vector<int> p(100000), num(100000);
int n, m, temp, x, y;
char query;

int root(int x)
{
    while (x != p[x])
        x = p[x];
    return x;
}

void merge(int x, int y)
{
    int root_x = root(x);
    int root_y = root(y);
    if (num[root_x] < num[root_y])
    {
        p[root_x] = root_y;
        num[root_y] += num[root_x];
    }else{
        p[root_y] = root_x;
        num[root_x] += num[root_y];
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
        num[i] = 1;
    }
    for (int k = 0; k < m; k++)
    {
        cin >> query;
        switch (query)
        {
        case 'M':
            cin >> x >> y;
            merge(x, y);
            break;
        case 'S':
            cin >> x;
            cout << num[root(x)] << endl;
            break;
        case 'Q':
            cin >> x >> y;
            cout << (root(x) == root(y) ? "Yes" : "No") << endl;
        }
    }
}