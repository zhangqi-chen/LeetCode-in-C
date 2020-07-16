/**
 * Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
 * 
 * For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees
 * of every node never differ by more than 1.
 */

struct ListNode {
    int val;
    struct ListNode* next;
};

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* sortedListToBST(struct ListNode* head) {
    if (!head) return NULL;
    struct ListNode* fast = (struct ListNode*)malloc(sizeof(struct ListNode));
    fast->next = head;
    struct ListNode* slow = head = fast;
    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = slow->next->val;
    root->right = sortedListToBST(slow->next->next);
    slow->next = NULL;
    root->left = sortedListToBST(head->next);
    return root;
}