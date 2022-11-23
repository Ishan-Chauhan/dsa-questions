class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        int n=words.size(),f=0;
        for(int i=0;i<n;i++)
        {
            f=0;
            unordered_map<char,char> mp;
            vector<int> v(26,-100);
            int m=words[i].size();
            for(int j=0;j<m;j++)
            {
                if(pattern.size()!=m) break;
                
                if(mp[pattern[j]]==NULL) mp[pattern[j]]=words[i][j];
                else if(mp[pattern[j]]!=words[i][j])
                {
                    f=1;
                    break;
                }
                if(v[words[i][j]-'a']==-100)
                {
                    v[words[i][j]-'a']=pattern[j]-words[i][j];
                }
                else if(v[words[i][j]-'a']!=pattern[j]-words[i][j])
                {
                    f=1;
                    break;
                }
            }
            if(f==0)
            {
                res.push_back(words[i]);
            }
        }
        return res;
    }
};