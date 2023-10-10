// 865. 具有所有最深节点的最小子树
#include <algorithm>
#include <iostream>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  TreeNode *findDeepest(TreeNode *root, int &deepth) {
    if (root == nullptr) {
      deepth = 0;
      return nullptr;
    } else {
      int dl, dr;
      TreeNode *nodel = findDeepest(root->left, dl);
      TreeNode *noder = findDeepest(root->right, dr);
      if (dl == dr) {
        deepth = dl + 1;
        return root;
      } else if (dl > dr) {
        deepth = dl + 1;
        return nodel;
      } else {
        deepth = dr + 1;
        return noder;
      }
    }
  }

  TreeNode *subtreeWithAllDeepest(TreeNode *root) {
    int deepth;
    return findDeepest(root, deepth);
  }
};

int main() {
  TreeNode *root = new TreeNode(0);
  root->left = new TreeNode(1);
  root->left->right = new TreeNode(2);
  root->right = new TreeNode(3);
  Solution sol;
  sol.subtreeWithAllDeepest(root);
}