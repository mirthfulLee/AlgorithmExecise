// 1074 Reversing Linked List
#include <iostream>
#include <vector>
using namespace std;

struct node
{
    int val, next;
};
vector<node> info(100010);
vector<int> list(100010), result(100010);
int n, k, cur, s, p, q, v, cnt;

int main()
{
    // FIXME：输入的节点不一定都在链表中
    cin >> s >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> p >> v >> q;
        info[p].val = v;
        info[p].next = q;
    }
    list[0] = s;
    cnt = 1;
    while (info[list[cnt-1]].next>=0){
        list[cnt] = info[list[cnt-1]].next;
        cnt++;
    }
    

    for (int i = 0; i < cnt / k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            result[k * i + j] = list[k * i + k - j - 1];
        }
    }
    for (int i = cnt / k * k; i < cnt;i++)
        result[i] = list[i];
    printf("%05d %d", result[0], info[result[0]].val);
    for (int i = 1; i < cnt;i++){
        printf(" %05d\n%05d %d", result[i], result[i], info[result[i]].val);
    }
    printf(" -1");
}
