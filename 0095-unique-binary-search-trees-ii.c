/**
 * Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.
 */

#include <math.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode** tree(int start, int n, int* returnSize) {
    if (n == 0) {
        *returnSize = 1;
        struct TreeNode** res = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
        res[0] = NULL;
        return res;
    }
    int leftSize, rightSize;
    struct TreeNode **left, **right;
    struct TreeNode** res = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * pow(3, n));
    *returnSize = 0;
    for (int s = 0; s < n; ++s) {
        left = tree(start, s, &leftSize);
        right = tree(start + s + 1, n - s - 1, &rightSize);
        for (int i = 0; i < leftSize; ++i) {
            for (int j = 0; j < rightSize; ++j) {
                res[*returnSize] = (struct TreeNode*)malloc(sizeof(struct TreeNode));
                res[*returnSize]->val = start + s;
                res[*returnSize]->left = left[i];
                res[*returnSize]->right = right[j];
                ++*returnSize;
            }
        }
    }
    return res;
}

struct TreeNode** generateTrees(int n, int* returnSize) {
    if (n == 0) {
        *returnSize = 0;
        return 0;
    }
    return tree(1, n, returnSize);
}