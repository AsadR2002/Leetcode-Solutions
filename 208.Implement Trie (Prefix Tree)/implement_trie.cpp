class TrieNode {
    public: 
    unordered_map<char, TrieNode*> children;
};
// # sign to denote big klubnika 
class Trie {
public:
    TrieNode root;

    Trie() {
        
    }
    
    void insert(string word) {
        TrieNode *p = &root; 
        for (char c : word) {
            if(p->children.find(c) == p->children.end()) p->children[c] = new TrieNode();
            p = p->children[c];
        }
        p->children['#'] = nullptr;  
    }
    
    bool search(string word) {
        TrieNode *p = &root; 
        for (char c : word) {
            if(p->children.find(c) == p->children.end()) return false;
            p = p->children[c];
        }
        return p->children.find('#') != p->children.end();
    }
    
    bool startsWith(string prefix) {
        TrieNode *p = &root; 
        for (char c : prefix) {
            if(p->children.find(c) == p->children.end()) return false;
            p = p->children[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */