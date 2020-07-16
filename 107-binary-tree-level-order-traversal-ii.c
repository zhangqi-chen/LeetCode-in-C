/**
 * Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right,
 * level by level from leaf to root).
 */

#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int maxDepth(struct TreeNode* root) {
    if (!root) return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return left > right ? left + 1 : right + 1;
}

int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = maxDepth(root);
    if (!root) return 0;
    int** res = (int**)malloc(sizeof(int*) * (*returnSize));
    *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
    struct TreeNode** prev = (struct TreeNode**)malloc(sizeof(struct TreeNode) * 100);
    struct TreeNode** curr = (struct TreeNode**)malloc(sizeof(struct TreeNode) * 100);
    int prevNum = 0;
    int currNum = 0;
    curr[currNum++] = root;
    int lvl = *returnSize - 1;
    while (currNum > 0) {
        prevNum = currNum;
        currNum = 0;
        struct TreeNode** tmp = prev;
        prev = curr;
        curr = tmp;
        (*returnColumnSizes)[lvl] = prevNum;
        res[lvl] = (int*)malloc(sizeof(int) * prevNum);
        for (int i = 0; i < prevNum; ++i) {
            res[lvl][i] = prev[i]->val;
            if (prev[i]->left) curr[currNum++] = prev[i]->left;
            if (prev[i]->right) curr[currNum++] = prev[i]->right;
        }
        --lvl;
    }
    return res;
}
