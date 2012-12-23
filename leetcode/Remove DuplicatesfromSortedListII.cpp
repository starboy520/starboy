/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

*/
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL) return NULL;
        ListNode* ret_head = NULL;
        ListNode* cur = head;
        ListNode* ret_tmp = ret_head;
        
        int count = 1;
        bool first = true;
        
        while (cur != NULL) {
            int val = cur->val;

            while (cur->next != NULL && cur->next->val == val) {
                count++;
                cur = cur->next;
            }
            
            if (count != 1) {
                count = 1;
            } else {
                if (first) {
                    ret_tmp = cur;
                    ret_head = cur;
                    first = false;
                } else {
                    ret_tmp->next = cur;
                    ret_tmp = ret_tmp->next;
                }
                //cur = cur->next;
            }
            cur = cur->next;
        }
        if (ret_tmp != NULL)
            ret_tmp->next = NULL;
        
        return ret_head;
        
    }
};
