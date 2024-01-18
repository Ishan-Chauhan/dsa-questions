class Solution {
public:
    string findLongestWord(string s, vector<string>& dic) {
        vector<string> v;
        int sz=dic.size();
        int x=0,y=0;
        string word;
        
        int n=s.size(),m;
        
        for(int i=0;i<sz;i++)
        {
            word=dic[i];
            x=0;
            y=0;
            m=word.size();
            
            while(x!=n && y!=m)
            {
                if(s[x]==word[y])
                {
                    x++;
                    y++;
                }
                else x++;
            }
            if(y==m) v.push_back(word);
            // cout<<y<<" "<<m<<endl;
        }
        
        sort(v.begin(), v.end(),[](const string& a, const string& b) {
        if(a.length()==b.length()) return a<b;
        return a.length() < b.length();
    });
        n=v.size();
        
        for(int i=n-1;i>=0;i--) 
        {
            if(i>0 && v[i].size()==v[i-1].size()) continue;
            else return v[i];
        }
        
        return "";
    }
};