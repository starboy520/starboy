/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (head == NULL) return NULL;
        ListNode* ret_head = NULL;
        ListNode* cur = head;
        ListNode* tail = NULL;
        while (cur) {
            ListNode* first = cur;
            ListNode* second = cur->next;
            if (second == NULL) break;
            if (ret_head == NULL) {
                ret_head = second;
            }
            first->next = second->next;
            second->next = first;
            cur = first->next;
            
            if (tail != NULL) {
                tail->next = second;
            }
            tail = first;
        }
        return ret_head == NULL? head:ret_head;
    }
    
    
};

/*

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (head == NULL) return NULL;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* cur = head;
        while (cur != NULL) {
            ListNode* first = cur;
            ListNode* second = cur->next;
            if (second == NULL) {
                prev->next = first;
                return dummy.next;
            }
            cur = second->next;
            prev->next = second;
            second->next = first;
            prev = first;
            prev->next = NULL;
            
        }
        return dummy.next;
    }
};

*/
