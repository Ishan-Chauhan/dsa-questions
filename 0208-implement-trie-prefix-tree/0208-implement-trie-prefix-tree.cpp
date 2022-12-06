class trienode{
public:
    trienode *child[26];
    bool isword=false;
    trienode()
    {
        for(int i=0;i<26;i++)
        {
            child[i]=NULL;
        }
    }
};
class Trie {
public:
    trienode* root;
    Trie() {
        root = new trienode();
    }
    
    void insert(string word) {
        trienode* temp = root;
        int n = word.size();
        for(int i=0;i<n;i++)
        {
            if(!temp->child[word[i]-'a'])
                temp->child[word[i]-'a'] =  new trienode();
            temp = temp->child[word[i]-'a'];
        }
        temp->isword=true;
    }
    
    bool search(string word) {
        trienode* temp = root;
        int n = word.size();
        for(int i=0;i<n;i++)
        {
            if(!temp->child[word[i]-'a'])
                return false;
            temp = temp->child[word[i]-'a'];
        }
        return temp->isword;
    }
    
    bool startsWith(string word) {
        trienode* temp = root;
        int n = word.size();
        for(int i=0;i<n;i++)
        {
            if(!temp->child[word[i]-'a'])
                return false;
            temp = temp->child[word[i]-'a'];
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