/**
 * Given a binary tree
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

void findnext(struct TreeNode *root, struct TreeNode *ref) {
    if (!root) return;
    root->next = ref;
    while (ref) {
        if (ref->left) {
            ref = ref->left;
            break;
        } else if (ref->right) {
            ref = ref->right;
            break;
        } else
            ref = ref->next;
    }
    if (root->right) findnext(root->right, ref);
    if (root->left) {
        if (root->right)
            findnext(root->left, root->right);
        else
            findnext(root->left, ref);
    }
}

void connect(struct TreeNode *root) {
    findnext(root, NULL);
}