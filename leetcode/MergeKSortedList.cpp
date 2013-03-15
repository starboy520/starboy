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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode* head = NULL;
        ListNode* cur = NULL;
        
        for (vector<ListNode*>::iterator it = lists.begin(); it != lists.end();) {
            if (*it == NULL) {
                it = lists.erase(it);
            } else {
                it++;
            }
        }
        while (lists.size() != 0) {
            int val = INT_MAX;
            int index = -1;
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i]->val < val) {
                    val = lists[i]->val;
                    index = i;
                }
            }

            ListNode* tmp = lists[index];
            lists[index] = lists[index]->next;
            if (lists[index] == NULL) {
                lists.erase(lists.begin()+index);
            }
            if (head == NULL) {
                head  = tmp;
                cur = tmp;
            } else {
                cur->next = tmp;
                cur = tmp;
            }
        }
        return head;
    }
};
