//
// Created by 木子又欠 on 2020/9/22.
//

#include <iostream>
#include <set>
#include <cmath>
using namespace std;

class BST{
private:
    class Node{
    public:
        int value;
        Node *left;
        Node *right;

        Node(int a):value(a){
            left = NULL;
            right = NULL;
        }

        Node(){
            value = 0;
            left = NULL;
            right = NULL;
        }
    };
//****attributes*****************************//
    Node *root;
//*****methods*****************************//
    //比a大的最小值
    Node *floor(Node *x, int a){
        if (NULL == x) return NULL;
        if (x->value == a) return x;
        if (x->value > a) return floor(x->left, a);
        Node *tmp = floor(x->right, a);
        if (NULL != tmp) return tmp;
        else return x;
    }
    //比a小的最大值
    Node *ceiling(Node *x, int a){
        if (NULL == x) return NULL;
        if (x->value == a) return x;
        if (x->value < a) return ceiling(x->right, a);
        Node *tmp = ceiling(x->left, a);
        if (NULL != tmp) return tmp;
        else return x;
    }

    Node *put(Node *x, int a){
        if (x == NULL) return new Node(a);
        if (a < x->value) x->left = put(x->left, a);
        else if (a > x->value) x->right = put(x->right, a);
        return x;
    }

public:
    BST(int a){
        root = new Node(a);
    }

    int floor(int a){
        Node *x = floor(root, a);
        if (NULL == x) return 1000000;
        else return x->value;
    }

    int ceiling(int a){
        Node *x = ceiling(root, a);
        if (NULL == x) return -1000000;
        else return x->value;
    }

    void put(int a){
        root = put(root, a);
    }

    int max(){
        Node *tmp = root;
        while (tmp->right != NULL) tmp = tmp->right;
        return tmp->value;
    }

    int min(){
        Node *tmp = root;
        while (tmp->left != NULL) tmp = tmp->left;
        return tmp->value;
    }

};

//使用普通二叉树，当输入数据并非无序时，时间代价过大。需要使用平衡二叉树
int main()
{
    int n, a1, tmp, sum;
    cin>>n>>a1;
    BST bst(a1);
    sum = abs(a1);
    for (int i = 0; i < n - 1; i++) {
        cin>>tmp;
        sum += min(abs(tmp - bst.floor(tmp)), abs(tmp - bst.ceiling(tmp)));
        bst.put(tmp);
    }
    cout << sum;
}

//使用stl::set中的lower_bound方法
/*
int main()
{
    int n, a1, tmp, sum;
    cin>>n>>a1;
    std::set<int> myset;
    std::set<int>::iterator itlow, itup;
    myset.insert(a1);
    myset.insert(-10000000);
    myset.insert(10000000);
    sum = a1;
    for (int i = 0; i < n - 1; i++) {
        cin>>tmp;
        itlow = myset.lower_bound(tmp);
        if (*itlow != tmp) {
            itup = itlow;
            itup--;
            sum += min(abs(tmp - *itlow), abs(tmp - *itup));
            myset.insert(tmp);
        }
    }
    cout<<sum;
}*/
