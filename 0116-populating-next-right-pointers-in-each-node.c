/**
 * You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The
 * binary tree has the following definition:
 * 
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right; 
 *     Node *next;
 * }
 * 
 * Populate each next pointer to point to its next right node. If there is no next right node, the next pointer
 * should be set to NULL.
 * 
 * Initially, all next pointers are set to NULL.
 */

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    struct TreeNode *next;
};

void connect(struct TreeNode *root) {
    if (!root) return;
    if (root->left) root->left->next = root->right;
    if (root->right && root->next) root->right->next = root->next->left;
    connect(root->left);
    connect(root->right);
}