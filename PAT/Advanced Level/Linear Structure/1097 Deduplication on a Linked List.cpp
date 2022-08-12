// 1097 Deduplication on a Linked List
// 自己创建几个测试样例即可
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node
{
    int val, next;
};

vector<node> linked_list(100010);
vector<int> contains(10010, 0);
queue<int> sep;
int n, s, add, p, q;

int abs(int a)
{
    return a < 0 ? -a : a;
}

int main()
{
    cin >> s >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> add >> p >> q;
        linked_list[add].val = p;
        linked_list[add].next = q;
    }
    printf("%05d %d", s, linked_list[s].val);
    contains[abs(linked_list[s].val)] = 1;
    p = linked_list[s].next;
    while (p != -1)
    {
        if (contains[abs(linked_list[p].val)])
        {
            sep.push(p);
        }
        else
        {
            printf(" %05d\n%05d %d", p, p, linked_list[p].val);
            contains[abs(linked_list[p].val)] = 1;
        }
        p = linked_list[p].next;
    }
    printf(" -1\n");
    if (!sep.empty())
    {
        p = sep.front();
        printf("%05d %d", p, linked_list[p].val);
        sep.pop();
        while (!sep.empty())
        {
            p = sep.front();
            printf(" %05d\n%05d %d", p, p, linked_list[p].val);
            sep.pop();
        }
        printf(" -1\n");
    }
    return 0;
}
