#include"TrieNode.h"
#include<string>
using namespace std;

class Trie{
    private:
        TrieNode *root;
    public:
    Trie(){
        root = new TrieNode('\0');
    }

    private:
    void insertWord(TrieNode *root, string word){
        if(word.size() == 0){
            root->isTerminal = true;
            return;
        }
        int index = word[0] - 'a';
        TrieNode *child;
        if(root -> children[index] != NULL){
            child = root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insertWord(child, word.substr(1));
    }

    public:
    void insertWord(string word){
        insertWord(root, word);
    }
};