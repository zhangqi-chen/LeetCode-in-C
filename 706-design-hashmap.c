/**
 * Design a HashMap without using any built-in hash table libraries.
 * 
 * To be specific, your design should include these functions:
 * 
 * put(key, value) : Insert a (key, value) pair into the HashMap. If the value already exists in the HashMap, update the value.
 * get(key): Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
 * remove(key) : Remove the mapping for the value key if this map contains the mapping for the key.
 * 
 * Note:
 * All keys and values will be in the range of [0, 1000000].
 * The number of operations will be in the range of [1, 10000].
 * Please do not use the built-in HashMap library.
 */

#include <stdlib.h>

typedef struct Map {
    int key;
    int val;
    struct Map* next;
} ListNode;

typedef struct {
    int size;
    ListNode** data;
} MyHashMap;

MyHashMap* myHashMapCreate() {
    MyHashMap* newHash = (MyHashMap*)malloc(sizeof(MyHashMap));
    newHash->size = 10001;
    newHash->data = (ListNode**)malloc(sizeof(ListNode*) * newHash->size);
    for (int i = 0; i < newHash->size; ++i) newHash->data[i] = NULL;
    return newHash;
}

void myHashMapPut(MyHashMap* obj, int key, int value) {
    int idx = key % obj->size;
    if (obj->data[idx] == NULL) {
        obj->data[idx] = (ListNode*)malloc(sizeof(ListNode));
        obj->data[idx]->key = key;
        obj->data[idx]->val = value;
        obj->data[idx]->next = NULL;
        return;
    }
    ListNode* curr = obj->data[idx];
    if (curr->key == key) {
        curr->val = value;
        return;
    }
    while (curr->next) {
        curr = curr->next;
        if (curr->key == key) {
            curr->val = value;
            return;
        }
    }
    curr->next = (ListNode*)malloc(sizeof(ListNode));
    curr = curr->next;
    curr->key = key;
    curr->val = value;
    curr->next = NULL;
}

int myHashMapGet(MyHashMap* obj, int key) {
    ListNode* curr = obj->data[key % obj->size];
    while (curr && curr->key != key) {
        curr = curr->next;
    }
    if (curr) return curr->val;
    return -1;
}

void myHashMapRemove(MyHashMap* obj, int key) {
    int idx = key % obj->size;
    if (obj->data[idx] == NULL) return;
    if (obj->data[idx]->key == key) {
        obj->data[idx] = obj->data[idx]->next;
        return;
    }
    ListNode* curr = obj->data[idx];
    while (curr->next && curr->next->key != key) {
        curr = curr->next;
    }
    if (curr->next) curr->next = curr->next->next;
}

void myHashMapFree(MyHashMap* obj) {
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