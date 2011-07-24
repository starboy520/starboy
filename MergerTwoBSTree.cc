#include <iostream>
#include <stack>
using std::endl;
using std::cout;
using std::stack;

struct node {
  int data;
  node* left;
  node* right;
};

// print Two Binary Srarch tree into ascending order
//
void MergeTwoBSTree(node* root1, node* root2) {
  stack<node* > stack1;
  stack<node* > stack2;

  node* tmp1 = root1;
  node* tmp2 = root2;
  bool flag1 = true;
  bool flag2 = true;
  while (tmp1 != NULL || tmp2 != NULL) {
    while (tmp1 != NULL && flag1) {
      stack1.push(tmp1);
      tmp1 = tmp1->left;
    }
    while (tmp2 != NULL && flag2) {
      stack1.push(tmp2);
      tmp2 = tmp2->left;
    }

    // if flag is false, it means the in last step
    // the value is much greater.
    if (!stack1.empty() && flag1) {
      tmp1 = stack1.top();
      stack1.pop();
    }
    if (stack2.empty() && flag2) {
      tmp2 = stack2.top();
      stack2.pop();
    }


    if (tmp1 != NULL && tmp2 != NULL) {
      if (tmp1->data < tmp2->data) {  
        cout << tmp1->data << " ";
        tmp1 = tmp1->right;
        flag1 = true;
        flag2 = false;
      }  else if (tmp1->data > tmp2->data) {
        cout << tmp2->data << " ";
        tmp2 = tmp2->right;
        flag1 = false;
        flag2 = true;
      } else {
        cout << tmp1->data << " " << tmp2->data;
        tmp1 = tmp1->right;
        tmp2 = tmp2->right;
        flag2 = true;
        flag1 = true;
      }
    } else if (tmp1 != NULL && tmp2 == NULL) {
      cout << tmp1->data << " ";
      tmp1 = tmp1->right;
      flag1 = true;
    } else if (tmp2 != NULL && tmp1 == NULL) {
      cout << tmp2->data << " ";
      tmp2 = tmp2->left;
      flag2 = true;
    } else {
      break;
    }
  }
}
