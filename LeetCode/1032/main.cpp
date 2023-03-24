#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <string.h>

using namespace std;


//前缀树
/*
class node {
public:
    //map<char, node*> nMap;
    vector<node *> nMap;
    bool isEnd;

    node() : nMap(26), isEnd(false) {};

    void addChar(string &s) {
        node *n = this;
        for (char w: s) {
            int c = w - 'a';
            if (!n->nMap[c])
                n->nMap[c] = new node();
            n = n->nMap[c];
        }
        n->isEnd = true;
    }

    bool search(string &s) {
        node *n = this;
        for (int i = s.size() - 1, j = 0; i >= 0 && j < 201; i--, j++) {
            int c = s[i] - 'a';
            if (!n->nMap[c])
                return false;
            n = n->nMap[c];
            if (n->isEnd)
                return true;
        }
        return false;
    }
};

class StreamChecker {
public:

    node *head = new node();
    string s = "";

    StreamChecker(vector<string> &words) {
        for (string word: words) {
            reverse(word.begin(), word.end());
            head->addChar(word);
        }
    }

    bool query(char letter) {
        s += letter;
        return head->search(s);
    }
};
*/


//AC自动机
typedef struct TrieNode {
    vector<TrieNode *> children;
    bool isEnd;
    TrieNode *fail;
    TrieNode() {
        this->children = vector<TrieNode *>(26, nullptr);
        this->isEnd = false;
        this->fail = nullptr;
    }
};

class StreamChecker {
public:
    TrieNode *root;
    TrieNode *temp;
    StreamChecker(vector<string>& words) {
        root = new TrieNode();
        for (string &word : words) {
            TrieNode *cur = root;
            for (int i = 0; i < word.size(); i++) {
                int index = word[i] - 'a';
                if (cur->children[index] == nullptr) {
                    cur->children[index] = new TrieNode();
                }
                cur = cur->children[index];
            }
            cur->isEnd = true;
        }
        root->fail = root;
        queue<TrieNode *> q;
        for (int i = 0; i < 26; i++) {
            if(root->children[i] != nullptr) {
                root->children[i]->fail = root;
                q.emplace(root->children[i]);
            } else {
                root->children[i] = root;
            }
        }
        while (!q.empty()) {
            TrieNode *node = q.front();
            q.pop();
            node->isEnd = node->isEnd || node->fail->isEnd;
            for (int i = 0; i < 26; i++) {
                if(node->children[i] != nullptr) {
                    node->children[i]->fail = node->fail->children[i];
                    q.emplace(node->children[i]);
                } else {
                    node->children[i] = node->fail->children[i];
                }
            }
        }

        temp = root;
    }

    bool query(char letter) {
        temp = temp->children[letter - 'a'];
        return temp->isEnd;
    }
};



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
