/**
 * Design a HashSet without using any built-in hash table libraries.
 * 
 * To be specific, your design should include these functions:
 * 
 * add(value): Insert a value into the HashSet. 
 * contains(value) : Return whether the value exists in the HashSet or not.
 * remove(value): Remove a value in the HashSet. If the value does not exist in the HashSet, do nothing.
 * 
 * Note:
 * All values will be in the range of [0, 1000000].
 * The number of operations will be in the range of [1, 10000].
 * Please do not use the built-in HashSet library.
 */

#include <stdbool.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} ListNode;

typedef struct {
    int size;
    ListNode** data;
} MyHashSet;

MyHashSet* myHashSetCreate() {
    MyHashSet* newHash = (MyHashSet*)malloc(sizeof(MyHashSet));
    newHash->size = 10001;
    newHash->data = (ListNode**)malloc(sizeof(ListNode*) * newHash->size);
    for (int i = 0; i < newHash->size; ++i) newHash->data[i] = NULL;
    return newHash;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    int idx = key % obj->size;
    if (obj->data[idx] == NULL) {
        obj->data[idx] = (ListNode*)malloc(sizeof(ListNode));
        obj->data[idx]->val = key;
        obj->data[idx]->next = NULL;
        return;
    }
    ListNode* curr = obj->data[idx];
    if (curr->val == key) return;
    while (curr->next) {
        curr = curr->next;
        if (curr->val == key) return;
    }
    curr->next = (ListNode*)malloc(sizeof(ListNode));
    curr->next->val = key;
    curr->next->next = NULL;
}

void myHashSetRemove(MyHashSet* obj, int key) {
    int idx = key % obj->size;
    if (obj->data[idx] == NULL) return;
    if (obj->data[idx]->val == key) {
        ListNode* temp = obj->data[idx];
        obj->data[idx] = obj->data[idx]->next;
        free(temp);
        return;
    }
    ListNode* curr = obj->data[idx];
    while (curr->next && curr->next->val != key) {
        curr = curr->next;
    }
    if (curr->next) {
        ListNode* temp = curr->next;
        curr->next = curr->next->next;
        free(temp);
    }
}

bool myHashSetContains(MyHashSet* obj, int key) {
    int idx = key % obj->size;
    ListNode* curr = obj->data[idx];
    while (curr && curr->val != key) {
        curr = curr->next;
    }
    if (curr) return true;
    return false;
}

void myHashSetFree(MyHashSet* obj) {
    for (int i = 0; i < obj->size; ++i) {
        ListNode *temp, *curr;
        curr = obj->data[i];
        while (curr) {
            temp = curr->next;
            free(curr);
            curr = temp;
        }
    }
    free(obj->data);
    free(obj);
}
