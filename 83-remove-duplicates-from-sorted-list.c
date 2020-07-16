/**
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 */

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (!head || !head->next) return head;
    struct ListNode* curr = head;
    struct ListNode* fast = head->next;
    while (fast) {
        if (fast->val != curr->val) {
            curr->next = fast;
            curr = curr->next;
        }
        fast = fast->next;
    }
    curr->next = NULL;
    return head;
} 