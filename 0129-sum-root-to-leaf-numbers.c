/**
 * Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
 * 
 * An example is the root-to-leaf path 1->2->3 which represents the number 123.
 * 
 * Find the total sum of all root-to-leaf numbers.
 * 
 * Note: A leaf is a node with no children.
 */

#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int search(struct TreeNode *root, int sum) {
    if (!root) return 0;
    sum = sum * 10 + root->val;
    if (!root->left && !root->right) return sum;
    return search(root->left, sum) + search(root->right, sum);
}

int sumNumbers(struct TreeNode *root) {
    return search(root, 0);
}