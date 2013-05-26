class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL) return NULL;
        ListNode* cur = head;
        while (cur) {
            ListNode* next = cur->next;
            while(next && next->val == cur->val) next = next->next;
            cur->next = next;
            cur = next;
        }
        return head;
        
    }
    
    ListNode *deleteDuplicates2(ListNode *head) {
        if (head == NULL) return NULL;
        ListNode* dummy = new ListNode(INT_MIN);
        dummy->next = head;
        
        ListNode* prev = dummy;
        ListNode* cur = dummy->next;
        
        while (cur != NULL) {
            if (cur->val == prev->val) {
                prev->next = cur->next;
                cur = cur->next;
            } else {
                prev = cur;
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};
