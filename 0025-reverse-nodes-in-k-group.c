/**
 * Given a linked list, reverse the nodes of a linked list k at a time
 * and return its modified list.
 * 
 * k is a positive integer and is less than or equal to the length of 
 * the linked list. If the number of nodes is not a multiple of k then
 * left-out nodes in the end should remain as it is.
 */

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (k == 1) return head;
    struct ListNode *newhead, *first, *second, *mid, *byd;
    newhead = (struct ListNode*)malloc(sizeof(struct ListNode));
    newhead->next = head;
    first = second = newhead;
    int i;
    while (1) {
        for (i = 0; i < k; i++) {
            if (first) first = first->next;
        }
        if (!first) break;
        struct ListNode *curr, *temp1, *temp2;
        mid = curr = second->next;
        byd = first->next;
        temp1 = curr->next;
        for (i = 0; i < k-1; i++) {
            temp2 = temp1->next;
            temp1->next = curr;
            curr = temp1;
            temp1 = temp2;
        }
        mid->next = byd;
        second->next = first;
        first = second = mid;
    }
    return newhead->next;
}