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
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL) return head;
        
        ListNode* tmp = head;
    
        int i = 0;
        while (tmp) {
            i++;
            tmp = tmp->next;
        }
        
        k = k % i;
        k = i - k;
        if (k == i) return head;
        
        ListNode* cur = head;
        i = 1;
        while (i < k) {
            i++;
            cur = cur->next;
        }
        tmp = cur->next;
        ListNode* newhead = cur->next;
        cur->next = NULL;
        while (tmp->next != NULL) tmp = tmp->next;
        tmp->next = head;
        return newhead;
        
    }
    
};
