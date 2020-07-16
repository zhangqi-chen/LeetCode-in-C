/**
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 */

#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    if (inorderSize == 0) return NULL;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = postorder[postorderSize - 1];
    int rightStart = inorderSize;
    while (inorder[--rightStart] != postorder[postorderSize - 1]) {
    }
    root->right = buildTree(inorder + rightStart + 1, inorderSize - 1 - rightStart, postorder + rightStart, inorderSize - 1 - rightStart);
    root->left = buildTree(inorder, rightStart, postorder, rightStart);
    return root;
}