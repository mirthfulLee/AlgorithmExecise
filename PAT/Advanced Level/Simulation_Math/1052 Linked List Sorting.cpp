// 1052 Linked List Sorting
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node
{
    int add, key;
    bool operator<(const node &b) const
    {
        return key < b.key;
    }
};

int main()
{
    int source, nodeNum, add;
    cin >> nodeNum >> source;
    vector<int> nxt(100010), key(100010);
    for (int i = 0; i < nodeNum; i++)
    {
        cin >> add;
        cin >> key[add] >> nxt[add];
    }
    vector<node> list;
    int p = source;
    while (p != -1)
    {
        node cur = {p, key[p]};
        list.push_back(cur);
        p = nxt[p];
    }
    sort(list.begin(), list.end());
    if (!list.size()){
        printf("0 -1");
        return 0;
    }
    printf("%d %05d\n", list.size(), list[0].add);
    printf("%05d %d", list[0].add, list[0].key);
    for (int i = 1; i < list.size(); i++)
    {
        printf(" %05d\n%05d %d", list[i].add, list[i].add, list[i].key);
    }
    printf(" -1");
}