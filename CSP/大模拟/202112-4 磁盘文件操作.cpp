// 202112-4 磁盘文件操作
#include<fstream>
// FIXME：只拿了60分，超时
#include <iostream>
#include <map>
#include <vector>
using namespace std;
struct info
{
    int r, owner, val;
    bool occupied;
};

int n, m, k, t;
map<int, info> area;

int writeAllowed(int id, int l, int r)
{
    auto it = area.upper_bound(l);
    it--;
    while (it != area.end() && it->first <= r)
    {
        if (it->second.occupied && it->second.owner != id)
            return it->first - 1;
        it++;
    }
    return r;
}
int deleteAllowed(int id, int l, int r)
{
    auto it = area.upper_bound(l);
    it--;
    while (it != area.end() && it->first <= r)
    {
        if (!it->second.occupied || it->second.owner != id)
            return it->first - 1;
        it++;
    }
    return r;
}
int recoverAllowed(int id, int l, int r)
{
    auto it = area.upper_bound(l);
    it--;
    while (it != area.end() && it->first <= r)
    {
        if (it->second.occupied || it->second.owner != id)
            return it->first - 1;
        it++;
    }
    return r;
}
void deleteArea(int id, int l, int r)
{
    auto it = area.upper_bound(l);
    it--;
    if (it->first < l)
    {
        area[l] = it->second;
        it->second.r = l - 1;
        it++;
    }
    while (it->first <= r && it != area.end())
    {
        if (it->second.r > r)
        {
            area[r + 1] = it->second;
            it->second.r = r;
        }
        it->second.occupied = false;
        it++;
    }
}

void recoverArea(int id, int l, int r)
{
    auto it = area.upper_bound(l);
    it--;
    if (it->first < l)
    {
        area[l] = it->second;
        it->second.r = l - 1;
        it++;
    }
    while (it->first <= r && it != area.end())
    {
        if (it->second.r > r)
        {
            area[r + 1] = it->second;
            it->second.r = r;
        }
        it->second.occupied = true;
        it++;
    }
}

void coverArea(int id, int l, int r, int x)
{
    auto it = area.upper_bound(l);
    it--;
    if (it->first < l)
    {
        area[l] = it->second;
        it->second.r = l - 1;
        it++;
    }
    while (it->first <= r && it != area.end())
    {
        if (it->second.r > r)
            area[r + 1] = it->second;
        auto cur = it;
        it++;
        area.erase(cur);
    }
    info newBlock = {r, id, x, true};
    area[l] = newBlock;
}

int main()
{
    // ifstream cin("1.in");
    // ofstream cout("my2.ans");

    cin >> n >> m >> k;
    info emptyBlock = {m, 0, 0, false};
    area[1] = emptyBlock;
    for (int i = 0; i < k; i++)
    {
        int opt, id, l, r, x, p;
        cin >> opt;
        if (opt == 0)
        {
            cin >> id >> l >> r >> x;
            int pos = writeAllowed(id, l, r);
            if (pos < l)
                cout << -1 << endl;
            else
            {
                cout << pos << endl;
                coverArea(id, l, pos, x);
            }
        }
        if (opt == 1)
        {
            cin >> id >> l >> r;
            if (deleteAllowed(id, l, r) < r)
                cout << "FAIL" << endl;
            else
            {
                deleteArea(id, l, r);
                cout << "OK" << endl;
            }
        }
        if (opt == 2)
        {
            cin >> id >> l >> r;
            if (recoverAllowed(id, l, r) < r)
                cout << "FAIL" << endl;
            else
            {
                recoverArea(id, l, r);
                cout << "OK" << endl;
            }
        }
        if (opt == 3)
        {
            cin >> p;
            auto it = area.upper_bound(p);
            it--;
            if (!it->second.occupied)
                cout << "0 0" << endl;
            else
                cout << it->second.owner << ' ' << it->second.val << endl;
        }
    }
}