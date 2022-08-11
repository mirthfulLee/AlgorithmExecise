// 1161 Merging Linked Lists
#include <iostream>
#include <vector>
#include<stack>
using namespace std;

struct node
{
    int val, next;
};

vector<node> list(100010);
stack<int> short_stack;
int n, s1, s2, p, q, v, address, len1, len2, short_len, cur;

int get_length(int root)
{
    int cnt = 0;
    while (root != -1)
    {
        cnt++;
        root = list[root].next;
    }
    return cnt;
}

int main()
{
    cin >> s1 >> s2 >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> address >> v >> p;
        list[address].val = v;
        list[address].next = p;
    }
    len1 = get_length(s1);
    len2 = get_length(s2);
    // p -> long; q -> short
    if (len2 >= 2 * len1)
    {
        p = s2;
        q = s1;
        short_len = len1;
    }else{
        p = s1;
        q = s2;
        short_len = len2;
    }
    while (q != -1){
        short_stack.push(q);
        q = list[q].next;
    }
    cur = 1;
    while (cur <= len1 + len2)
    {
        if (cur <= 3 * short_len)
        {
            switch (cur % 3)
            {
            case 1:
                printf("%05d %d %05d\n", p, list[p].val, list[p].next);
                cur++;
                p = list[p].next;
                break;
            case 2:
                printf("%05d %d %05d\n", p, list[p].val, short_stack.top());
                cur++;
                p = list[p].next;
                break;

            default:
                q = short_stack.top();
                if (p == -1)
                    printf("%05d %d -1\n", q, list[q].val);
                else
                    printf("%05d %d %05d\n", q, list[q].val, p);
                cur++;
                short_stack.pop();
                break;
            }
        }
        else
        {
            if (list[p].next == -1)
                printf("%05d %d -1\n", p, list[p].val);
            else
                printf("%05d %d %05d\n", p, list[p].val, list[p].next);
            cur++;
            p = list[p].next;
        }
    }
}