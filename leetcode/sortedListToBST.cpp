/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return new TreeNode(head->val);
        
        ListNode* dummy = new ListNode(INT_MAX);
        dummy->next = head;
        
        ListNode* slow = dummy->next;
        ListNode* fast = slow;
        ListNode* prev = dummy;
        while (fast && fast->next) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        TreeNode* root = new TreeNode(slow->val);
        prev->next = NULL;
        root->left = sortedListToBST(dummy->next);
        root->right = sortedListToBST(slow->next);
        return root;
    }
};
