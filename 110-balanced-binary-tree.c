/**
 * Given a binary tree, determine if it is height-balanced.
 * 
 * For this problem, a height-balanced binary tree is defined as:
 * a binary tree in which the left and right subtrees of every node differ in height by no more than 1.
 */

#include <stdbool.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int balance(struct TreeNode *root) {
    if (!root) return 0;
    int left = balance(root->left);
    if (left < 0) return -1;
    int right = balance(root->right);
    if (right < 0) return -1;
    if (abs(left - right) > 1) return -1;
    return left > right ? left + 1 : right + 1;
}

bool isBalanced(struct TreeNode *root) {
    return balance(root) > 0;
}