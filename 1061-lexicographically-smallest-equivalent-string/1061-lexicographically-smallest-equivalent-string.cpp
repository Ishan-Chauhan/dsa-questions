class Solution {
public:
    vector<int> parent;
    int find(int p)
    {
        if(parent[p]<0) return p;
        return find(parent[p]);
    }
    void unionn(int a, int b)
    {
        int p1 = find(a);
        int p2 = find(b);
        if(p1!=p2)
        {
            if(p1<p2)
            {
                parent[p2]=p1;
            }
            else
            {
                parent[p1]=p2;
            }
        }
    }
    string smallestEquivalentString(string& s1, string& s2, string& b) {
        parent.resize(26,-1);
        int n=s1.size();
        for(int i=0;i<n;i++)
        {
            unionn(s1[i]-'a',s2[i]-'a');
        }
        n=b.size();
        string ans;
        char x;
        for(int i=0;i<n;i++)
        {
            x= 'a'+find(b[i]-'a');
            ans.push_back(x);
        }
        return ans;
    }
};