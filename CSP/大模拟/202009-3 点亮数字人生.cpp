// 	202009-3 点亮数字人生
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
struct gate
{
    int type;
    int out;
    vector<int> in;
    vector<int> kid;
};
vector<gate> cycle;
int input[10000][2510], targetO[500];
map<string, int> typeMap = {{"NOT", 0}, {"AND", 1}, {"OR", 2}, {"XOR", 3}, {"NAND", 4}, {"NOR", 5}};
int n, m, k, q, s, outputNum;
bool legal;

bool judge()
{
    vector<int> inDegree(n + 1);
    queue<int> gateQ;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        inDegree[i] = cycle[i].in.size();
    for (int i = n + 1; i <= n + m; i++)
        gateQ.push(i);
    while (!gateQ.empty())
    {
        int cur = gateQ.front();
        gateQ.pop();
        cnt++;
        for (int kid : cycle[cur].kid)
        {
            inDegree[kid]--;
            if (!inDegree[kid])
                gateQ.push(kid);
        }
    }
    return cnt == n + m;
}
void compute(int cur)
{
    if (cycle[cur].type < 0)
        return;
    int result;
    if (cycle[cur].type == 0)
    {
        // NOT
        cycle[cur].out = !cycle[cycle[cur].in[0]].out;
    }
    if (cycle[cur].type == 1)
    {
        // AND
        for (int i : cycle[cur].in)
        {
            if (cycle[i].out == 0)
            {
                cycle[cur].out = 0;
                return;
            }
        }
        cycle[cur].out = 1;
    }
    if (cycle[cur].type == 2)
    {
        // OR
        for (int i : cycle[cur].in)
        {
            if (cycle[i].out == 1)
            {
                cycle[cur].out = 1;
                return;
            }
        }
        cycle[cur].out = 0;
    }
    if (cycle[cur].type == 3)
    {
        // XOR
        result = cycle[cycle[cur].in[0]].out;
        for (int i = 1; i < cycle[cur].in.size(); i++)
            result ^= cycle[cycle[cur].in[i]].out;
        cycle[cur].out = result;
    }
    if (cycle[cur].type == 4)
    {
        // NAND
        for (int i : cycle[cur].in)
        {
            if (cycle[i].out == 0)
            {
                cycle[cur].out = 1;
                return;
            }
        }
        cycle[cur].out = 0;
    }
    if (cycle[cur].type == 5)
    {
        for (int i : cycle[cur].in)
        {
            if (cycle[i].out == 1)
            {
                cycle[cur].out = 0;
                return;
            }
        }
        cycle[cur].out = 1;
    }
}

void Topologic()
{
    vector<int> inDegree(n + 1);
    queue<int> gateQ;
    for (int i = 1; i <= n; i++)
        inDegree[i] = cycle[i].in.size();
    for (int i = n + 1; i <= n + m; i++)
        gateQ.push(i);
    while (!gateQ.empty())
    {
        int cur = gateQ.front();
        gateQ.pop();
        compute(cur);
        for (int kid : cycle[cur].kid)
        {
            inDegree[kid]--;
            if (!inDegree[kid])
                gateQ.push(kid);
        }
    }
}
int main()
{
    cin >> q;
    while (q--)
    {
        cin >> m >> n;
        cycle.clear();
        cycle.resize(n + m + 1);
        // input
        for (int i = 1; i <= n; i++)
        {
            string type;
            int id;
            char c;
            cin >> type >> k;
            cycle[i].type = typeMap[type];
            // cycle[i].in.reserve(k);
            for (int j = 0; j < k; j++)
            {
                scanf(" %c%d", &c, &id);
                if (c == 'I')
                    id += n;
                cycle[i].in.push_back(id);
                cycle[id].kid.push_back(i);
            }
        }
        for (int i = 1; i <= m; i++)
            cycle[n + i].type = -1;

        cin >> s;
        for (int i = 0; i < s; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> input[i][j];
            }
        }
        // judge
        legal = judge();

        for (int curS = 0; curS < s; curS++)
        {
            cin >> outputNum;
            for (int i = 0; i < outputNum; i++)
                cin >> targetO[i];
            if (!legal)
                continue;
            for (int i = 1; i <= m; i++)
                cycle[n + i].out = input[curS][i];

            // compute
            Topologic();
            cout << cycle[targetO[0]].out;
            for (int i = 1; i < outputNum; i++)
            {
                cout << ' ' << cycle[targetO[i]].out;
            }
            cout << endl;
        }
        if (!legal)
            cout << "LOOP" << endl;
    }
}