/**
 * Given a non-empty binary tree, find the maximum path sum.
 * 
 * For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along
 * the parent-child connections. The path must contain at least one node and does not need to go through the root.
 */

#include <stdlib.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int max;

int leafPath(struct TreeNode *root) {
    int sum = root->val;
    int left = root->left ? leafPath(root->left) : 0;
    int right = root->right ? leafPath(root->right) : 0;
    sum = MAX(sum, sum + left);
    sum = MAX(sum, sum + right);
    max = MAX(max, sum);
    return MAX(root->val, MAX(root->val + left, root->val + right));
}

int maxPathSum(struct TreeNode *root) {
    max = INT_MIN;
    leafPath(root);
    return max;
}