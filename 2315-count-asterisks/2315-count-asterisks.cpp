class Solution {
public:
    int countAsterisks(string s) {
        int n=s.size();
        int c=0,f=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='|')
            {
                f=(f==0)?1:0;
            }
            else if(s[i]=='*' && f%2==0) c++;
        }
        return c;
    }
};