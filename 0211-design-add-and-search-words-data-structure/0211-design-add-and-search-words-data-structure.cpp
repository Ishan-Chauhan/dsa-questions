class node{
public:
    int isend;
    vector<node*> children;
    
    node()
    {
        children.resize(26, NULL);
        isend=0;
    }
};

class WordDictionary {
private:
    node* words;
    
    void insert(node* root, string& s)
    {
        node* temp=root;
        
        for(int i=0; i<s.size(); i++)
        {
            int x = s[i]-'a';
            if(temp->children[x]==NULL)
            {
                temp->children[x] = new node();
            }
            temp = temp->children[x];
        }
        temp->isend=1;
    }
    
    bool search(node* root, string& s, int i)
    {
        if(i==s.size()) 
        {
            if(root->isend==1) return true;
            return false;
        }
        cout<<s[i];
        
        bool l = false;
        
        if(s[i]=='.')
        {
            for(auto it: root->children)
            {
                if(it && search(it, s, i+1)) return true;
            }
            return false;
        }
        
        int x=s[i]-'a';
        
        if(root->children[x]==NULL) return false;
        
        return search(root->children[x], s, i+1);
    }
public:
    
    WordDictionary() {
        words = new node();
    }
    
    void addWord(string word) {
        insert(words, word);
    }
    
    bool search(string word) {
        return search(words, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */