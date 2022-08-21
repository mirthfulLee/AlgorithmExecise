// 1159 Structure of a Binary Tree
// FIXME: 注意strtok, sstream的用法
// 注意段错误
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
using namespace std;

struct node
{
    int val, level;
    node *left, *right;
};

int n, m, in[50], post[50];
char c_s[500];
string state, tempS;
node *root;

node *buildTree(int inL, int inR, int postL, int postR)
{
    if (inL > inR)
        return NULL;
    node *cur = (node *)malloc(sizeof(node));
    cur->val = post[postR];
    int p = inL;
    while (in[p] != post[postR])
        p++;
    cur->left = buildTree(inL, p - 1, postL, postL + p - inL - 1);
    cur->right = buildTree(p + 1, inR, postR - inR + p, postR - 1);
    return cur;
}

node *find(node *root, int v)
{
    if (root == NULL)
        return NULL;
    if (root->val == v)
        return root;
    else
    {
        node *temp = find(root->left, v);
        if (temp)
            return temp;
        else
            return find(root->right, v);
    }
}

node *findFather(node *root, int v)
{
    if (root == NULL)
        return NULL;
    if ((root->left != NULL && root->left->val == v) || (root->right != NULL && root->right->val == v))
        return root;
    else
    {
        node *temp = findFather(root->left, v);
        if (temp)
            return temp;
        else
            return findFather(root->right, v);
    }
}

void computeLevel(node *root, int l)
{
    if (root == NULL)
        return;
    root->level = l;
    computeLevel(root->left, l + 1);
    computeLevel(root->right, l + 1);
}

bool isFull(node *root)
{
    if (root->left == NULL || root->right == NULL)
    {
        if (root->left || root->right)
            return false;
        return true;
    }
    return isFull(root->left) && isFull(root->right);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> post[i];
    for (int i = 0; i < n; i++)
        cin >> in[i];
    cin >> m;
    root = buildTree(0, n - 1, 0, n - 1);
    getchar();
    computeLevel(root, 0);
    for (int k = 0; k < m; k++)
    {
        bool flag = false;
        // FIXME: 读取一行；字符串分割
        getline(cin, state);
        strcpy(c_s, state.c_str());
        char *p = strtok(c_s, " ");
        for (int i = 0; i < 3; i++)
            p = strtok(NULL, " ");
        if (strcmp(p, "root") == 0)
        {
            // 15 is the root
            int v = stoi(state);
            if (v == root->val)
                flag = true;
        }
        else if (strcmp(p, "parent") == 0)
        {
            // 32 is the parent of 11
            int k = state.find_last_of(' ');
            int a = stoi(state);
            int b = stoi(state.substr(k));
            node *temp = find(root, a);
            if (temp != NULL)
                if ((temp->left != NULL && temp->left->val == b) || (temp->right != NULL && temp->right->val == b))
                    flag = true;
        }
        else if (strcmp(p, "left") == 0)
        {
            // 23 is the left child of 16
            int k = state.find_last_of(' ');
            int a = stoi(state);
            int b = stoi(state.substr(k));
            node *temp = find(root, b);
            if (temp != NULL && temp->left != NULL)
                flag = a == temp->left->val;
        }
        else if (strcmp(p, "right") == 0)
        {
            // 28 is the right child of 2
            int k = state.find_last_of(' ');
            int a = stoi(state);
            int b = stoi(state.substr(k));
            node *temp = find(root, b);
            if (temp != NULL && temp->right != NULL)
                flag = a == temp->right->val;
        }
        else if (strcmp(p, "full") == 0)
        {
            // It is a full tree
            flag = isFull(root);
        }
        else if (strcmp(p, "are") == 0)
        {
            p = strtok(NULL, " ");
            if (strcmp(p, "siblings") == 0)
            {
                // 8 and 2 are siblings
                stringstream ss(state);
                int a, b;
                ss >> a >> tempS >> b;
                node *fa = findFather(root, a), *fb = findFather(root, b);
                flag = fa == fb;
            }
            else
            {
                // 7 and 11 are on the same level
                stringstream ss(state);
                int a, b;
                ss >> a >> tempS >> b;
                node *na = find(root, a), *nb = find(root, b);
                if (na && nb)
                    flag = na->level == nb->level;
            }
        }
        printf("%s\n", flag ? "Yes" : "No");
    }
}
