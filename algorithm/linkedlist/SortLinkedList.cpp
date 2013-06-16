#include <stdio.h>
struct Node {
    int val;
    Node* next;
};

Node* mergeSort(Node* head) {
    Node dummy;
    Node* left;
    Node* right;
    if (head == NULL) return NULL;

    Node* p1 = head;
    Node* p2 = head->next;
    while (p2 && p2->next) {
        p1 = p1->next;
        p2 = p2->next->next;
    }

    left = head;
    right = p1->next;
    p1->next = NULL;
    p1 = mergeSort(left);
    p2 = mergeSort(right);

    dummy.next = NULL;
    Node* ptr ;
    for (ptr = &dummy; p1 != NULL && p2 != NULL;) {
        if (p1->val < p2->val) {
            ptr->next = p1;
            ptr = p1;
            p1 = p1->next;
        } else {
            ptr->next = p2;
            ptr = p2;
            p2 = p2 ->next;
        }
    }

    ptr->next = (p1==NULL) ? p2 : p1;
    return dummy.next;
}
