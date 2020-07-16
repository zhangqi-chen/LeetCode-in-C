/**
 * Given a linked list, rotate the list to the right by k places, where k is non-negative.
 */

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (k == 0 || head == NULL || head->next == NULL) return head;
    struct ListNode* curr = head->next;
    int len = 2;
    while (curr->next) {
        ++len;
        curr = curr->next;
    }
    if (k % len == 0) return head;
    curr->next = head;
    k = len - k % len;
    for (int i = 0; i < k; ++i) {
        curr = curr->next;
    }
    head = curr->next;
    curr->next = NULL;
    return head;
}