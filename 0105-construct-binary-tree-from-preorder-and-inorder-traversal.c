/**
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 */

#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    if (preorderSize == 0) return NULL;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = preorder[0];
    int leftSize = -1;
    while (inorder[++leftSize] != preorder[0]) {
    }
    int rightSize = preorderSize - leftSize - 1;
    root->left = buildTree(preorder + 1, leftSize, inorder, leftSize);
    root->right = buildTree(preorder + 1 + leftSize, rightSize, inorder + 1 + leftSize, rightSize);
    return root;
}