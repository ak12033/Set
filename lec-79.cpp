#include<iostream>
using namespace std;

//                                                 Implementation of Trie

class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;
        
    TrieNode(char ch)
    {
        data = ch;
        for(int i=0; i<26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }    
};

class Trie {
    public:
    TrieNode *root;

    Trie(){
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode *root, string word){
        
        //base case
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        //assumption, word will be in CAPS
        int index = word[0]-'A';
        TrieNode* child;

        //present
        if(root->children[index] != NULL){
            child = root->children[index];
        }    
        else{
            //absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        
        // Recursion
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word) {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode *root,string word){

        // base case    
        if(word.length() == 0){
            return root->isTerminal;
        }
        
        int index = word[0]-'A';
        TrieNode *child;

        //present
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            //absent
            return false;
        }

        //Recursion    
        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word) {
        return searchUtil(root, word);
    }

    void removeUtil(TrieNode* root, string word){
        //base case
        if(word.length() == 0){
            root->isTerminal = false;
            return ;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        //present
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            //absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        //Recursion
        return removeUtil(child, word.substr(1));
    }

    void removeWord(string word){
        removeUtil(root, word);
    }

    bool prefixUtil(TrieNode *root,string word){

        //base case
        if(word.length() == 0){
            return true;
        }

        int index = word[0]-'A';
        TrieNode* child;

        //present
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            //absent
            return false;
        }

        //Recursion
        return prefixUtil(child, word.substr(1));
    }

    bool prefixWith(string prefix) {
        return prefixUtil(root, prefix);
    }
};

int main() {
    Trie* t = new Trie();

    // Insert words into the Trie
    t->insertWord("HELLO");
    t->insertWord("HELL");
    t->insertWord("HE");

    // Search for words
    cout << "Searching for HELLO: " << (t->searchWord("HELLO") ? "Found" : "Not Found") << endl;
    cout << "Searching for HEL: " << (t->searchWord("HEL") ? "Found" : "Not Found") << endl;

    // Search for prefixes
    cout << "Checking prefix HE: " << (t->prefixWith("HE") ? "Exists" : "Does not exist") << endl;
    cout << "Checking prefix HEL: " << (t->prefixWith("HEL") ? "Exists" : "Does not exist") << endl;
    cout << "Checking prefix HELLO: " << (t->prefixWith("HELLO") ? "Exists" : "Does not exist") << endl;
    cout << "Checking prefix HELL: " << (t->prefixWith("HELL") ? "Exists" : "Does not exist") << endl;
    cout << "Checking prefix HELLOO: " << (t->prefixWith("HELLOO") ? "Exists" : "Does not exist") << endl;

    // Remove a word and check again
    t->removeWord("HELLO");
    cout << "Searching for HELLO after removal: " << (t->searchWord("HELLO") ? "Found" : "Not Found") << endl;
    cout << "Checking prefix HELLO after removal: " << (t->prefixWith("HELLO") ? "Exists" : "Does not exist") << endl;

    return 0;
}

