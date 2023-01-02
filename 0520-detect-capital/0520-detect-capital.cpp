class Solution {
public:
    bool detectCapitalUse(string s) {
        int n = s.size();
        int f=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]<'A' || s[i]>'Z') 
            {
                f=1;
                break;
            }
        }
        if(f==0) return true;
        f=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]<'a' || s[i]>'z') 
            {
                f=1;
                break;
            }
        }
        if(f==0) return true;
        f=0;
        
        if(s[0]>='A' && s[0]<='Z')
        {
            for(int i=1;i<n;i++)
            {
                if(s[i]<'a' || s[i]>'z') 
                {
                    f=1;
                    break;
                }
            }
            if(f==0) return true;
        }
        return false;
    }
};