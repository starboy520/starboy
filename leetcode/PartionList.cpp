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
    ListNode *partition(ListNode *head, int x) {
        if (head == NULL) return NULL;
        
        ListNode* before = NULL;
        ListNode* after = NULL;
        ListNode* head_before = NULL;
        ListNode* head_after = NULL;
        
        ListNode* tmp = head;
        
        while (tmp != NULL) {
            if (tmp->val < x) {                
                if (before == NULL) {
                    before = tmp;
                    head_before = tmp;
                } else {
                    before->next = tmp;
                    before = tmp;
                }
            } else {
                if (after == NULL) {
                    head_after = tmp;
                    after = tmp;
                } else {
                    after->next = tmp;
                    after = tmp;
                }
            }
            tmp = tmp->next;
        }
        if (before != NULL) before->next = NULL;
        if (after != NULL)after->next = NULL;
        
        if (head_after == NULL) return head_before;
        if (head_before == NULL) return head_after;
        
        before->next = head_after;
        return head_before;
    }
};


/**
 * 
 * 
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if (head == NULL) return NULL;
        ListNode* dummy = new ListNode(INT_MAX);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* cur = dummy;
        while (cur->next != NULL) {
            if (cur->next->val >= x) {
                cur = cur->next;
            } else {
                ListNode* tmp = cur->next;
                if (prev->next != tmp) {
                    cur->next = cur->next->next;
                    tmp->next = prev->next;
                    prev->next = tmp;
                } else {
                    cur = cur->next;
                }
                prev = prev->next;

            }
        }
        return dummy->next;
        
    }
};
