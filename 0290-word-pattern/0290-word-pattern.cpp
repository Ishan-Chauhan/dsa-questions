class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n = pattern.size(),m=s.size();
        map<char,string> mp;
        set<string> st;
        int j=0,i;
        for(i=0;i<n;i++)
        {
            string temp;
            while(j!=m && s[j]!=' ')
            {
                temp+=s[j];
                j++;
            }
            j++;
            // cout<<pattern[i]<<" "<<temp<<endl;
            if(mp.find(pattern[i])==mp.end())
            {
                mp[pattern[i]]=temp;
                if(st.find(temp)!=st.end()) return false;
                st.insert(temp);
            }
            else if(mp[pattern[i]]!=temp) return false;
            
            if(i!=n-1 && j==m+1) return false;
        }
        if(i==n && j!=m+1) return false;
        if(i!=n && j==m+1) return false;
        return true;
    }
};