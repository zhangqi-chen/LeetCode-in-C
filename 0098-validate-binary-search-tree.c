/**
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 * 
 * Assume a BST is defined as follows:
 * 
 * The left subtree of a node contains only nodes with keys less than the node's key.
 * The right subtree of a node contains only nodes with keys greater than the node's key.
 * Both the left and right subtrees must also be binary search trees.
 */

#include <stdbool.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool bst(struct TreeNode *root, long long min, long long max) {
    if (!root) return true;
    bool res = root->val > min && root->val < max;
    if (res && root->left) res = bst(root->left, min, root->val);
    if (res && root->right) res = bst(root->right, root->val, max);
    return res;
}

bool isValidBST(struct TreeNode *root) {
    return bst(root, (long long)(INT_MIN)*2, (long long)(INT_MAX)*2);
}