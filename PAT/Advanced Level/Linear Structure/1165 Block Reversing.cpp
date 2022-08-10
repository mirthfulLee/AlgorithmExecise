// 1165 Block Reversing
// 坑点：可能输入的node不属于链表
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct node
{
    int data, next;
};

vector<node> list(100000);
stack<int> block_stack;
int n, t, p, q, s, k;

int main()
{
    cin >> s >> n >> k;
    for (int i = 0; i < n;i++)
    {
        cin >> t >> p >> q;
        list[t].data = p;
        list[t].next = q;
    }
    p = s;
    q = 0;
    while (p != -1)
    {
        block_stack.push(p);
        for (int i = 0; i < k && p != -1;i++){
            p = list[p].next;
        }
        q += k;
    }
    while (!block_stack.empty()){
        int cur = block_stack.top();
        block_stack.pop();
        for (int i = 0; i < k-1 && list[cur].next != -1; i++){
            printf("%05d %d %05d\n", cur, list[cur].data, list[cur].next);
            cur = list[cur].next;
        }
        if (block_stack.empty()){
            printf("%05d %d %d\n", cur, list[cur].data, -1);
        }else{
            printf("%05d %d %05d\n", cur, list[cur].data, block_stack.top());
        }
    }
    return 0;
}