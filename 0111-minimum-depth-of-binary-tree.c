/**
 * Given a binary tree, find its minimum depth.
 * 
 * The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
 */

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int minDepth(struct TreeNode *root) {
    if (!root) return 0;
    if (!root->left) return minDepth(root->right) + 1;
    if (!root->right) return minDepth(root->left) + 1;
    int left = minDepth(root->left);
    int right = minDepth(root->right);
    return left < right ? left + 1 : right + 1;
}