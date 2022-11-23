class Solution {
public:
    string reformat(string s) {
        int n=s.size(),a=0,b=0;
        vector<char> x,y;
        for(int i=0;i<n;i++)
        {
            if(s[i]>='a' && s[i]<='z') 
            {
                x.push_back(s[i]);
                a++;
            }
            else 
            {
                y.push_back(s[i]);
                b++;
            }
        }
        if(abs(a-b)!=0 && abs(a-b)!=1) return "";
        string ans;
        if(a>=b)
        {
            for(int i=0;i<y.size();i++)
            {
                ans+=x[i];
                ans+=y[i];
            }
            if(a>b)
                ans+=x[x.size()-1];
        }
        else
        {
            for(int i=0;i<x.size();i++)
            {
                ans+=y[i];
                ans+=x[i];
            }
            ans+=y[y.size()-1];
        }
        return ans;
    }
};