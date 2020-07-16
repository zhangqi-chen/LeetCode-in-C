/**
 * Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then
 * right to left for the next level and alternate between).
 */

#include <stdlib.h>

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (!root) return 0;
    int** res = (int**)malloc(sizeof(int*) * 1000);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 1000);
    struct TreeNode** prev = (struct TreeNode**)malloc(sizeof(struct TreeNode) * 100);
    struct TreeNode** curr = (struct TreeNode**)malloc(sizeof(struct TreeNode) * 100);
    int prevNum = 0;
    int currNum = 0;
    curr[currNum++] = root;
    while (currNum > 0) {
        prevNum = currNum;
        currNum = 0;
        struct TreeNode** tmp = prev;
        prev = curr;
        curr = tmp;
        (*returnColumnSizes)[*returnSize] = prevNum;
        res[*returnSize] = (int*)malloc(sizeof(int) * prevNum);
        for (int i = 0; i < prevNum; ++i) {
            if (*returnSize % 2 == 0)
                res[*returnSize][i] = prev[i]->val;
            else
                res[*returnSize][prevNum - 1 - i] = prev[i]->val;
            if (prev[i]->left) curr[currNum++] = prev[i]->left;
            if (prev[i]->right) curr[currNum++] = prev[i]->right;
        }
        ++(*returnSize);
    }
    return res;
}