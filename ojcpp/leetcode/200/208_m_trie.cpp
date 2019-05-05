//
// Created by rui.zhou on 3/16/2019.
//

/*
 * Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.
 */
#include <codech/codech_def.h>
using namespace std;

namespace {
    struct TrieNode {
        TrieNode* childs[26];
        TrieNode() {
            for(int i=0 ; i<26 ; i++)
                childs[i] = nullptr;
            leaf=false;
        }
        bool leaf;
    };

    class Trie {
    private:
        TrieNode trieNode;
    public:
        /** Initialize your data structure here. */
        Trie() {

        }

        /** Inserts a word into the trie. */
        void insert(string word) {
            TrieNode*pnode=&trieNode;
            for (int i=0;i<word.length();i++) {
                int ch=word[i]-'a';
                if (pnode->childs[ch]==nullptr) {
                    pnode->childs[ch]=new TrieNode();
                }
                pnode=pnode->childs[ch];
                if (i==word.length()-1) {
                    pnode->leaf=true;
                }
            }
        }

        /** Returns if the word is in the trie. */
        bool search(string word) {
            TrieNode*pnode=&trieNode;
            for (int i=0;i<word.length();i++) {
                int ch=word[i]-'a';
                if (pnode)
                    pnode=pnode->childs[ch];
                else
                    return false;
            }
            return (pnode && pnode->leaf);
        }

        /** Returns if there is any word in the trie that starts with the given prefix. */
        bool startsWith(string prefix) {
            TrieNode*pnode=&trieNode;
            for (int i=0;i<prefix.length();i++) {
                int ch=prefix[i]-'a';
                if (pnode)
                    pnode=pnode->childs[ch];
                else
                    return false;
            }
            return pnode!=nullptr;
        }
    };

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
}

DEFINE_CODE_TEST(208_trie)
{
    {
        Trie trie;
        trie.insert("apple");
        VERIFY_CASE(trie.search("apple"),true);   // returns true
        VERIFY_CASE(trie.search("app"),false);     // returns false
        VERIFY_CASE(trie.startsWith("app"),true); // returns true
        trie.insert("app");
        VERIFY_CASE(trie.search("app"),true);     // returns true
    }

}