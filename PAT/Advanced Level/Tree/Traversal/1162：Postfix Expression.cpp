// 1162：Postfix Expression 2022/8/10
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

struct node
{
    string data;
    int left, right;
};

vector<node> tree(30);
int n, root;

int findRoot()
{
    bool haveFather[30];
    memset(haveFather, false, n);
    for (int i = 1; i <= n;i++){
        if (tree[i].left > 0)
            haveFather[tree[i].left] = true;
        if (tree[i].right > 0)
            haveFather[tree[i].right] = true;
    }
    for (int i = 1; i <= n;i++)
        if (!haveFather[i])
            return i;
}

void postTransfer(int cur){
    if (cur == -1)
        return;
    cout << '(';
    if (tree[cur].left > 0) 
    {
        postTransfer(tree[cur].left);
        postTransfer(tree[cur].right);
        cout << tree[cur].data;
    }
    else 
    {
        cout << tree[cur].data;
        postTransfer(tree[cur].right);
    }
    cout << ')';

}

int main()
{
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> tree[i].data >> tree[i].left >> tree[i].right;
    }
    root = findRoot();
    postTransfer(root);
    return 0;
}
