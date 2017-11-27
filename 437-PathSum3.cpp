/*
You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards 
(traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11
            1
             \
              2
               \
                3
                 \
                  4
                   \
                    5
*/
#include <LeetCodeUtil.h>
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (root == nullptr) return 0;
        return DFS(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
private:
    int DFS(TreeNode* root, int remain) {
        if (root == nullptr) return 0;
        return (root->val == remain ? 1 : 0) + DFS(root->left, remain-root->val) + DFS(root->right, remain-root->val);
    }
};
int main(int argc, char const *argv[]) {
    TreeNode* tree = createTree({10, 5, -3, 3, 2, (int)('#'), 11, 3, -2, (int)('#'), 1});
    cout << Solution().pathSum(tree, 8) << endl;
    return 0;
}
