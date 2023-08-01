class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char,int>,int> m;
        vector<pair<map<char,int>,vector<string>>> t;
        vector<vector<string>> res;
        
        int n=strs.size(),l;
        for(int i=0;i<n;i++)
        {
            map<char,int> m1;
            l=strs[i].size();
            for(int j=0;j<l;j++)
            {
                m1[strs[i][j]]++;
            }
            if(m.find(m1)==m.end()) 
            {
                // cout<<strs[i]<<" ";
                m[m1]=1;
                vector<string> temp;
                temp.push_back(strs[i]);
                t.push_back({m1,temp});
            }
            else
            {
                // cout<<strs[i]<<" ";
                for(int j=0;j<t.size();j++)
                {
                    if(t[j].first==m1)
                    {
                        // cout<<t[i].second[0]<<endl;
                        t[j].second.push_back(strs[i]);
                    }
                }
            }
        }
        for(auto it:t)
        {
            res.push_back(it.second);
        }
        // for(int i=0;i<t.size();i++)
        // {
        //     vector<string> temp;
        //     for(int j=0;j<t[i].second.size();j++)
        //     {
        //         // cout<<t[i].second[j]<<" ";
        //         temp.push_back(t[i].second[j]);
        //     }
        //     res.push_back(temp);
        // }
        return res;
    }
};