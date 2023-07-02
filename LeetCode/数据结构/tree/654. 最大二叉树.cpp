#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
    return construct(nums, 0, nums.size());
  }
  TreeNode *construct(vector<int> &nums, int left, int right) {
    if (left >= right) return nullptr;
    int rootIndex = maximumIndex(nums, left, right);
    TreeNode * rootNode = new TreeNode(nums[rootIndex], construct(nums, left, rootIndex),
                  construct(nums, rootIndex + 1, right));
    return rootNode;
  }

  int maximumIndex(vector<int> &nums, int left, int right) {
    int max = left;
    for (int i = left + 1; i < right; i++) {
      if (nums[i] > nums[max])
        max = i;
    }
    return max;
  }
};

int main() {
  vector<int> nums = {3, 2, 1, 6, 0, 5};
  Solution sol;
  sol.constructMaximumBinaryTree(nums);
  return 0;
}