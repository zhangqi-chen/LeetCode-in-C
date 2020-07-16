/**
 * Given a binary tree, flatten it to a linked list in-place.
 */

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void flatten(struct TreeNode *root) {
    if (!root || (!root->left && !root->right)) return;
    flatten(root->left);
    flatten(root->right);
    if (root->left) {
        struct TreeNode *right = root->right;
        root->right = root->left;
        root->left = NULL;
        if (!right) return;
        struct TreeNode *curr = root->right;
        while (curr->right) {
            curr = curr->right;
        }
        curr->right = right;
    }
}