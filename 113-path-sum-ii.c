/**
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
 * 
 * Note: A leaf is a node with no children.
 */

#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int maxDepth(struct TreeNode* root, int* leaves) {
    if (!root) return 0;
    if (!root->left && !root->right) ++(*leaves);
    int left = maxDepth(root->left, leaves);
    int right = maxDepth(root->right, leaves);
    return left > right ? left + 1 : right + 1;
}

void addPath(int** res, struct TreeNode* root, int* curr, int currSize, int sum, int* returnSize, int** returnColumnSizes) {
    curr[currSize++] = root->val;
    if (root->val == sum && !root->left && !root->right) {
        res[*returnSize] = (int*)malloc(sizeof(int) * currSize);
        for (int i = 0; i < currSize; ++i) {
            res[*returnSize][i] = curr[i];
        }
        (*returnColumnSizes)[(*returnSize)++] = currSize;
    }
    if (root->left) addPath(res, root->left, curr, currSize, sum - root->val, returnSize, returnColumnSizes);
    if (root->right) addPath(res, root->right, curr, currSize, sum - root->val, returnSize, returnColumnSizes);
}

int** pathSum(struct TreeNode* root, int sum, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (!root) return 0;
    int leaves = 0;
    int depth = maxDepth(root, &leaves);
    int** res = (int**)malloc(sizeof(int*) * leaves);
    *returnColumnSizes = (int*)malloc(sizeof(int) * leaves);
    int currSize = 0;
    int* curr = (int*)malloc(sizeof(int) * depth);
    curr[currSize++] = root->val;
    if (root->val == sum && !root->left && !root->right) {
        res[*returnSize] = (int*)malloc(sizeof(int));
        res[*returnSize][0] = curr[0];
        (*returnColumnSizes)[(*returnSize)++] = currSize;
    }
    if (root->left) addPath(res, root->left, curr, currSize, sum - root->val, returnSize, returnColumnSizes);
    if (root->right) addPath(res, root->right, curr, currSize, sum - root->val, returnSize, returnColumnSizes);
    return res;
}