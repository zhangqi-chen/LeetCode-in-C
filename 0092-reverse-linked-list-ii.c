/**
 * Reverse a linked list from position m to n. Do it in one-pass.
 * 
 * Note: 1 ≤ m ≤ n ≤ length of list.
 */

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    if (m == n) return head;
    struct ListNode new;
    new.next = head;
    head = &new;
    struct ListNode *neck, *start, *tail;
    neck = head;
    for (int i = 0; i < m - 1; ++i) {
        neck = neck->next;
    }
    start = neck->next;
    struct ListNode *prev, *curr;
    prev = start;
    curr = start->next;
    for (int i = 0; i < n - m; ++i) {
        tail = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tail;
    }
    neck->next = prev;
    start->next = tail;
    return head->next;
}