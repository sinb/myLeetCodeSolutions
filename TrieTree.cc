// Trie Tree的插入,搜索,和前缀搜索,字母a-z
#include<iostream>

using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    bool is_end; //判断这个节点是否是一个单词得结尾
    int prefix_count = 0; //记录拥有这个前缀得所有节点得个数.
    TrieNode* child[26]; //一共26个字母, 子节点有26种可能
    TrieNode() {
        is_end = false;
        prefix_count = 0;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* current = root;
        current->prefix_count += 1;
        for (int i = 0; i < word.size(); ++i)
        {
            int this_letter = (int)word[i] - (int)'a';
            if (current->child[this_letter] == nullptr)  //插入不同得单词时, 碰到有相同前缀得就不用再新建节点了,只要给节点+1即可
                current->child[this_letter] = new TrieNode();
            current->child[this_letter]->prefix_count += 1;
            current = current->child[this_letter];
        }
        current->is_end = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* current = root;
        for (int i = 0; i < word.size(); ++i)
        {
            int this_letter = (int)word[i] - (int)'a';
            if (current->child[this_letter] == nullptr)
                return false;
            current = current->child[this_letter];
        }
        return current->is_end;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* current = root;
        for (int i = 0; i < prefix.size(); ++i)
        {
            int this_letter = 0;
            if (current->child[this_letter] == nullptr)
                return false;
            current = current->child[this_letter];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

int main() {
    Trie a;
    return 0;
}
