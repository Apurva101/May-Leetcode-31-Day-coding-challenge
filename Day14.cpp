/*

Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
*/
class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode *links[26]={NULL};
    bool isEnd;
   
    
    TrieNode() {
        isEnd = false;
    
    }
};

class Trie {
    private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
      
        TrieNode *node = root;
        
        for (int i = 0; i < word.length(); i++)
        {
            
            if (!node->links[word[i]-'a'])
            {
                node->links[word[i]-'a'] = new TrieNode();
            }
            
            node= node->links[word[i]-'a'];
        }
        
        node->isEnd = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *node = root;
        
        for (int i = 0; i < word.length(); i++)
        {
           
            
            if (node->links[word[i]-'a']==NULL)
                return false;
             node = node->links[word[i]-'a'];
        }
        
        return node->isEnd;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
    
        TrieNode *node = root;
        
        for (int i = 0; i<prefix.length(); i++)
        {
            if (!node->links[prefix[i]-'a'])
                return false;
            node=node->links[prefix[i]-'a'];
        }
        
        return true;
    }

};
