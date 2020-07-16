/**
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values
 * along the path equals the given sum.
 * 
 * Note: A leaf is a node with no children.
 */

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool hasPathSum(struct TreeNode *root, int sum) {
    if (!root) return false;
    if (!root->left && !root->right) return sum == root->val;
    if (hasPathSum(root->left, sum - root->val)) return true;
    return hasPathSum(root->right, sum - root->val);
}