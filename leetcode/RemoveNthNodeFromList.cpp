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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == NULL) return NULL;
        if (n == 0) return head;
        
        int i = 0;
        
        ListNode* cur = head;
        while (i < n && cur != NULL) {
            cur = cur->next;
            i++;
        }
        
        ListNode* tmp = head;
        ListNode* pre = tmp;
        while (cur != NULL) {
            cur = cur->next;
            pre = tmp;
            tmp = tmp->next;
        }
        
        if (pre == tmp) return head->next;
        pre->next = tmp->next;
        return head;
        
    }
};
