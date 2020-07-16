/**
 * Given a linked list, remove the n-th node from the end of list and return its head.
 */

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *fast, *slow = head;
    fast = slow;
    for (int i = 0; i < n; i++) fast = fast->next;
    if (!fast) return head->next;
    while (fast->next) {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return head;
}