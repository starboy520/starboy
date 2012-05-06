#include <iostream>
using namespace std;

struct node {
    node* left;
    node* right;
    node* successor;
    int value;
};

node* get_pre(node* root, node * current) {
    while (root != NULL) {
        if (root->successor == current) {
            return root;
        } else if (root->value > current->value) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return NULL;
}


void add_node(node* root, int value) {
    if (root == NULL) {
        node *temp = new node;
        temp->value = value;
        temp->left = temp->right =temp->successor = NULL;
        root = temp;
    } else {
        node *temp;
        node* head = root;
        while (root != NULL) {
            temp = root;
            if (root->value == value) {
                return;
            } else if (root->value > value) {
                root = root->left;
            } else {
                root = root->right;
            }
        }

        if(temp->value < value) {
            node* ts = new node;
            ts->left=ts->right=ts->successor = NULL;
            ts->value = value;
            temp->right = ts;

            ts->successor = temp->successor;
            temp->successor = ts;
        } else {
            node* ts = new node;
            ts->value = value;
            ts->left = ts->right = ts->successor = NULL;
            temp->left = ts;

            node* pre = get_pre(head, temp);
            ts->successor = temp;
            if (pre != NULL) {
                pre->successor = ts;
            }
        }
    }
}
