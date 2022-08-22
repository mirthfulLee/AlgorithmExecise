// 1121 Damn Single
#include <iostream>
#include <vector>
using namespace std;

vector<int> comp(100010, -1), joined(100010), single;
int N, M, p, q, t;

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> p >> q;
        comp[p] = q;
        comp[q] = p;
    }
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> t;
        joined[t] = 1;
    }
    int cnt = 0;
    for (int i = 0; i < 100000; i++)
    {
        if (joined[i] && !(comp[i] >= 0 && joined[comp[i]]))
            single.push_back(i);
    }
    printf("%d\n", single.size());
    for (int i = 0; i < single.size(); i++)
    {
        printf("%05d", single[i]);
        if (i != single.size() - 1)
            printf(" ");
    }
}