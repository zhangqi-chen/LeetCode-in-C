/**
 * Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
 * 
 * For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees
 * of every node never differ by more than 1.
 */

#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if (numsSize == 0) return NULL;
    int leftSize = numsSize / 2;
    int rightSize = numsSize - 1 - leftSize;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = nums[leftSize];
    root->left = sortedArrayToBST(nums, leftSize);
    root->right = sortedArrayToBST(nums + leftSize + 1, rightSize);
    return root;
}