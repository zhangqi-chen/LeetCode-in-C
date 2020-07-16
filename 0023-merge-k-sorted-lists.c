/**
 * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 */

#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

// Method 1: Merge 2 by 2.
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
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

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0)
        return 0;
    else if (listsSize == 1)
        return lists[0];
    lists = (struct ListNode**)realloc(sizeof(struct ListNode*) * (listsSize * 2 - 1));
    int i = 0, k = listsSize;
    while (k > 1) {
        lists[i] = mergeTwoLists(lists[i], lists[i + 1]);
        i += 2;
        k++;
    }
    return lists[k - 1];
}

// Method 2: Merge k lists.
struct ListNode* mergeKLists2(struct ListNode** lists, int listsSize) {
    if (listsSize == 0)
        return 0;
    else if (listsSize == 1)
        return lists[0];
    struct ListNode *head, *curr;
    head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next = NULL;
    curr = head;
    int i, nextval, idx;
    nextval = 0;
    while (nextval < 10000) {
        nextval = 10000;
        for (i = 0; i < listsSize; i++) {
            if (lists[i] && lists[i]->val < nextval) {
                idx = i;
                nextval = lists[i]->val;
            }
        }
        if (nextval < 10000) {
            curr->next = lists[idx];
            curr = curr->next;
            lists[idx] = lists[idx]->next;
        }
    }
    return head->next;
}