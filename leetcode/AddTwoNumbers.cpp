struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  if (l1 == NULL && l2 == NULL) {
    return NULL;
  }

  if (l1 == NULL && l2 != NULL) {
    return l2;
  }

  if (l1 != NULL && l2 == NULL) {
    return l1;
  }

  ListNode *head = new ListNode(0);
  ListNode* current = head;
  int adds = 0;
  while (l1 != NULL && l2 != NULL) {
    int result = l1->val + l2->val + adds;
    adds = result / 10;
    result = result % 10;
    ListNode* tmp = new ListNode(result);
    current->next = tmp;
    current = tmp;
    l1 = l1->next;
    l2 = l2->next;
  }

  while (l1 != NULL) {
    int res = l1->val + adds;
    adds = res / 10;
    res = res % 10;
    ListNode* tmp = new ListNode(res);
    current->next = tmp;
    current = tmp;
    l1 = l1->next;
  }

  while (l2 != NULL) {
    int res = l2->val + adds;
    adds = res / 10;
    res = res % 10;
    ListNode* tmp = new ListNode(res);
    current->next = tmp;
    current = tmp;
    l2 = l2->next;
  }

  while (adds != 0) {
    int res = adds % 10;
    adds /= 10;
    ListNode* tmp = new ListNode(res);
    current->next = tmp;
    current = tmp;
  }
  return head->next;

};
