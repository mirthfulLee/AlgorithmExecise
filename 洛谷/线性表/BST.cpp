//
// Created by 木子又欠 on 2020/9/26.
//



class BST {
private:
    class Node{
    public:
        int value;
        Node *left;
        Node *right;
        int N;
        Node(int a):value(a){
            N = 1;
            left = NULL;
            right = NULL;
        }

        Node(){
            value = 0;
            N = 0;
            left = NULL;
            right = NULL;
        }
    };
//****attributes*****************************//
    Node *root;
//*****methods*****************************//
    int size(Node *x){
        if (x == NULL) return 0;
        else return x->N;
    }

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
        x->N = size(x->left) + size(x->right) + 1;
        return x;
    }

    Node *deleteMin(Node *x){
        if (x->left == NULL) return NULL;
        x->left = deleteMin(x->left);

        return x;
    }

    Node *del(Node *x, int a){
        if (x == NULL) return NULL;
        if (a < x->value) x->left = del(x->left, a);
        else if (a > x->value) x->right = del(x->right, a);
        else{
            if (x->right == NULL) return x->left;
            if (x->left == NULL) return x->right;
            Node *t = x;
            x = min(t->right);
            x->right = deleteMin(t->right);
            x->left = t->left;
            delete (t);
        }
        x->N = size(x->left) + size(x->right) + 1;
        return x;
    }

    Node *min(Node *x){
        Node *tmp = root;
        while (tmp->left != NULL) tmp = tmp->left;
        return tmp;
    }
    Node *max(Node *x){
        Node *tmp = root;
        while (tmp->right != NULL) tmp = tmp->right;
        return tmp;
    }

public:
    BST(int a){
        root = new Node(a);
    }

    int size(){
        return size(root);
    }

    int floor(int a){
        Node *x = floor(root, a);
        if (NULL == x) return NULL;
        else return x->value;
    }

    int ceiling(int a){
        Node *x = ceiling(root, a);
        if (NULL == x) return NULL;
        else return x->value;
    }

    void put(int a){
        root = put(root, a);
    }

    int max(){
        return max(root)->value;
    }

    int min(){
        return min(root)->value;
    }

};
