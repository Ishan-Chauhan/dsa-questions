class Solution {
public:
    string clearStars(string& s) {
        int k,n=s.size();

        vector<stack<int>> v(26);
        vector<bool> take(n, true);

        for(int i=0;i<n;i++)
        {
            if(s[i]=='*')
            {
                take[i]=false;
                for(int i=0;i<26;i++)
                {
                    if(!v[i].empty())
                    {
                        k = v[i].top();
                        v[i].pop();
                        take[k]=false;
                        break;  
                    }
                }
            }
            else
            {
                v[s[i]-'a'].push(i);
            }
        }

        string ans;
        for(int i=0;i<n;i++)
        {
            if(take[i]) ans.push_back(s[i]);
        }
        return ans;
    }
};