#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
    node *another;
};

// There is one list who has a pointer next and another,
// please copy one with exact of this, with time complexcity O(n)
// space O(1)

node* copy(node* head) {
    if (head == 0)
        return 0;
    node* current = head;
    while (current != NULL) {
        node* next1= current->next;

        node* tmp = new node;
        tmp->next = NULL;
        tmp->another = NULL;

        tmp->next= current->next;
        current->next = tmp;
        
        current = next1;
    }

    current = head;
    while (current != NULL) {
        node* copying = current->next;
        copying->data = current->data;
      if (current->another != NULL)
            copying->another =current->another->next;

        current = current->next->next;
    }

    current = head;
    node *newcurrent = head->next;
    node *to_be_returned = newcurrent;
    while (current != NULL) {
        current->next = current->next->next;

        current = current->next->next;
        if (current != NULL){
            newcurrent->next = current->next;
            newcurrent = current->next;
        }
    }
    newcurrent->next = NULL;

    return to_be_returned;
}
