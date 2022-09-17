// 202006-2 稀疏向量
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct value_pair
{
    long long index, value;
};
bool cmp(value_pair &a, value_pair &b)
{
    return a.index < b.index;
}
int main()
{
    long long n, a, b, result = 0;
    cin >> n >> a >> b;
    vector<value_pair> u(a), v(b);
    for (int i = 0; i < a;i++)
        cin >> u[i].index >> u[i].value;
    for (int i = 0; i < b;i++)
        cin >> v[i].index >> v[i].value;
    sort(u.begin(), u.end(), cmp);
    sort(v.begin(), v.end(), cmp);
    int p = 0, q = 0;
    while (p<a && q<b)
    {
        if (u[p].index == v[q].index)
            result += u[p++].value * v[q++].value;
        else if (u[p].index < v[q].index)
            p++;
        else
            q++;
    }
    cout << result;
}

/* 
10 3 4
4 5
7 -3
10 1
1 10
4 20
5 30
7 40
 */