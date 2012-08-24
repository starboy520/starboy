#include <stdio.h>


struct node {
    int data;
    struct node* next;
};

typedef struct node list;

// 判断两个无环的单链表是否相交
int intersection(list *head1, list* head2) {
    list* p1 = head1->next;
    list* p2 = head2->next;
    list* tail1, *tail2;

    while (p1) {
        tail1 = p1;
        p1 = p1->next;
    }
    
    while (p2) {
        tail2 = p2;
        p2 = p2->next;
    }

    return tail1 == tail2;
}


// 判断单链表是否存在环
// 快慢指针

int circile(list* head) {
    list *fast = head->next;
    list *slow = head->next;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }

    return !(fast== NULL || fast->next == NULL);
}

// 求出环入口的地址

list* looport(list* head) {
    list *slow = head->next;
    list *fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }
    if (fast == NULL || fast == NULL)
        return NULL;
    slow = head->next;
    while (slow !=fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}


