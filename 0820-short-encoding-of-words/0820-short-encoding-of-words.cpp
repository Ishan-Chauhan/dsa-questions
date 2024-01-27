class node{
public:
    char ch;
    unordered_map<char, node*> children;
    
    node(char ch)
    {
        this->ch=ch;
    }
};

class trie{
public:
    node* root;
    
    trie()
    {
        root = new node('#');
    }
    
    void insert(string& s)
    {
        node* temp=root;
        
        for(int i=s.size()-1; i>=0; i--)
        {
            char x = s[i];
            if(temp->children[x]==NULL)
            {
                // cout<<s[i];
                temp->children[x] = new node(s[i]);
            }
            temp = temp->children[x];
        }
    }
    
    void dfs(node* root, int& ans, int k)
    {
        int c=0;
        
        for(auto it: root->children)
        {
            dfs(it.second, ans, k+1);
            c++;
        }
        
        if(c==0)
        {
            // cout<<root->ch<<" "<<k<<endl;
            ans+=k+1;
        }
        
        return;
    }
    
    void new_words(int& ans)
    {
        for(auto it: root->children) dfs(it.second, ans, 1);
    }
};


class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        trie* root = new trie();
        
        for(auto it: words)
        {
            root->insert(it);
        }
        
        int ans=0;
        root->new_words(ans);
        cout<<endl;
        return ans;
    }
};