#include <iostream>
#include <cstring>
using namespace std;
const int branchNum = 26;
int i;

struct trie_node {
    bool isStr;  //记录是否构成一个串
    trie_node* next[branchNum];
    trie_node(): isStr(false) {
        memset(next, NULL, sizeof(next));
    }
};

class Trie {
    public:
        Trie();
        void insert(const char* word);
        bool search(char *word);
        void deleteTrie(trie_node* root);
    private:
        trie_node* root;
};


Trie::Trie() {
    root = new trie_node();
}


void Trie::insert(const char* word) {
    trie_node *location = root;
    while(*word) {
        if (location->next[*word-'a'] ==NULL) {
            trie_node* tmp = new trie_node();
            location->next[*word-'a'] = tmp;
        }
        location = location->next[*word-'a'];
        word++;
    }
    location->isStr = true;//到达尾部标记一个串
}

bool Trie::search(char* word) {
    trie_node* location = root;
    while (*word && location->next[*word - 'a']) {
        location = location->next[*word - 'a'];
        word++;
    }

    return location!=NULL && location->isStr;
}

void Trie::deleteTrie(trie_node* root) {
    int j;
    for (j = 0; j <branchNum; j++) {
        if (root->next[j] != NULL)
            deleteTrie(root->next[j]);
    }
    delete root;
}




