class Solution {
public:
    string reverseWords(string s) {
        string ans;
        string temp;
        int n=s.size(),c=0,i=n-1;
        
        while(i!=-1)
        {
            if(i>0 && s[i]==' ' && s[i-1]==' ') 
            {
                i--;
                continue;
            }
            // if(c==0 && s[i]==' ') 
            // {
            //     i--;
            //     continue;
            // }
            if(s[i]!=' ')
            {
                temp.push_back(s[i]);
            }
            else
            {
                c+=1;
                reverse(temp.begin(),temp.end());
                ans += temp;
                temp.erase(temp.begin(),temp.end());
                ans.push_back(' ');
            }
            i--;
        }
        // if(c!=0)
        // {
            reverse(temp.begin(),temp.end());
            ans += temp;
        // }
        
        // cout<<ans;
        n = ans.size();
        for(int i=0;i<n;i++)
        {
            if(ans[i]==' ')
            {
                ans.erase(ans.begin());
                i--;
            }
            else break;
        }
        cout<<ans;
        n = ans.size();
        for(int i=n-1;i>=0;i--)
        {
            if(ans[i]==' ')
            {
                ans.pop_back();
            }
            else break;
        }
        
        // ans.pop_back();
        return ans;
    }
};