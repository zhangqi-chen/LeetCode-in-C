/**
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 */

#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (!l1)
        return l2;
    else if (!l2)
        return l1;
    struct ListNode *head, *curr;
    head = (struct ListNode*)malloc(sizeof(struct ListNode));
    curr = head;
    while (l1 && l2) {
        if (l1->val <= l2->val) {
            curr->next = l1;
            l1 = l1->next;
            curr = curr->next;
        } else {
            curr->next = l2;
            l2 = l2->next;
            curr = curr->next;
        }
    }
    if (l1)
        curr->next = l1;
    else
        curr->next = l2;
    return head->next;
}

struct ListNode* mergeTwoLists2(struct ListNode* l1, struct ListNode* l2) {
    if (!l1)
        return l2;
    else if (!l2)
        return l1;
    if ((l1->val) <= (l2->val)) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l2->next, l1);
        return l2;
    }
}