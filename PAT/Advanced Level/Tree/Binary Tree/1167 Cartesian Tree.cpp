// 1167 Cartesian Tree
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct node
{
    int val;
    node *left, *right;
};

vector<int> inorder(50), bfs(50);
int n, p, q, cnt;
node *root, *cur;
queue<node *> node_queue;

node* construct_tree(int l, int r){
    if (l > r)
        return NULL;
    int min_idx = l;
    for (int i = l + 1; i <= r;i++)
        if (inorder[i] < inorder[min_idx])
            min_idx = i;
    node *newNode = new node;
    newNode->val = inorder[min_idx];
    newNode->left = construct_tree(l, min_idx - 1);
    newNode->right = construct_tree(min_idx + 1, r);
    return newNode;
}

int main(){
    cin >> n;
    for (int i = 0; i < n;i++)
        cin >> inorder[i];
    root = construct_tree(0, n - 1);
    node_queue.push(root);
    cnt = 0;
    while (!node_queue.empty())
    {
        cur = node_queue.front();
        node_queue.pop();
        if (cur == NULL)
            continue;
        if (++cnt < n)
            cout << cur->val << ' ';
        else
            cout << cur->val;
        node_queue.push(cur->left);
        node_queue.push(cur->right);
    }
}