/**
 * Given a binary tree, return the inorder traversal of its nodes' values.
 */

#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if (!root) return 0;
    int leftSize, rightSize;
    int* left = inorderTraversal(root->left, &leftSize);
    int* right = inorderTraversal(root->right, &rightSize);
    *returnSize = leftSize + rightSize + 1;
    int* res = (int*)malloc(sizeof(int) * (*returnSize));
    if (left) memcpy(res, left, sizeof(int) * leftSize);
    res[leftSize] = root->val;
    if (right) memcpy(res + leftSize + 1, right, sizeof(int) * rightSize);
    return res;
}