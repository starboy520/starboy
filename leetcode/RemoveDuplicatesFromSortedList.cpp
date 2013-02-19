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
};
