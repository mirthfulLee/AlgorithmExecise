// 202203-3 计算资源调度器
// 只有75分，可能有一些细节没考虑周全
#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <queue>
using namespace std;

struct node
{
    int block, id;
    multiset<int> tasks;
    bool operator<(const node &b) const
    {
        return tasks.size() == b.tasks.size() ? id > b.id : tasks.size() > b.tasks.size();
    }
};

vector<set<int>> blocks(1010);
vector<node> nodes(1010);

bool containAppInNode(node n, int app)
{
    return n.tasks.find(app) != n.tasks.end();
}

bool containAppInBlock(set<int> s, int app)
{
    for (int i : s)
        if (containAppInNode(nodes[i], app))
            return true;
    return false;
}

int nodeNum, blockNum, g, f, app, closeBlock, closeApp, antiApp, req;
int main()
{
    cin >> nodeNum >> blockNum;
    for (int i = 1; i <= nodeNum; i++)
    {
        cin >> nodes[i].block;
        blocks[nodes[i].block].insert(i);
        nodes[i].id = i;
    }

    cin >> g;
    for (int t = 0; t < g; t++)
    {
        set<int> allowedBlock;
        priority_queue<node> pq;
        cin >> f >> app >> closeBlock >> closeApp >> antiApp >> req;
        if (closeBlock)
        {
            if (closeApp == 0 || containAppInBlock(blocks[closeBlock], closeApp))
                allowedBlock.insert(closeBlock);
        }
        else
        {
            for (int i = 1; i <= blockNum; i++)
                if (closeApp == 0 || containAppInBlock(blocks[i], closeApp))
                    allowedBlock.insert(i);
        }

        for (int block : allowedBlock)
            for (int nodeId : blocks[block])
                if (antiApp == 0 || !containAppInNode(nodes[nodeId], antiApp))
                    pq.push(nodes[nodeId]);

        if (antiApp && req == 0 && pq.empty())
        {
            antiApp = 0;
            for (int block : allowedBlock)
                for (int nodeId : blocks[block])
                    pq.push(nodes[nodeId]);
        }

        if (pq.empty())
        {
            cout << 0;
            for (int i = 1; i < f; i++)
                cout << ' ' << 0;
        }
        else
        {
            for (int i = 0; i < f; i++)
            {
                if (pq.empty())
                {
                    if (req == 1)
                    {
                        cout << 0;
                        continue;
                    }
                    antiApp = 0;
                    for (int block : allowedBlock)
                        for (int nodeId : blocks[block])
                            pq.push(nodes[nodeId]);
                }
                int cur = pq.top().id;
                cout << cur;
                pq.pop();
                nodes[cur].tasks.insert(app);
                if (app != antiApp)
                    pq.push(nodes[cur]);
                if (i != f - 1)
                    cout << ' ';
            }
        }
        cout << endl;
    }
}