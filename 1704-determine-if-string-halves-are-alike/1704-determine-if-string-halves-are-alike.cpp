class Solution {
public:
    bool halvesAreAlike(string s) {
        string v = "aeiouAEIOU";
        int n = s.size();
        int mid = n/2;
        int c=0;
        for(int i=0;i<mid;i++)
        {
            for(int j=0;j<10;j++)
            {
                if(s[i]-v[j]==0)
                {
                    c++;
                    break;
                }
            }
        }
        for(int i=mid;i<n;i++)
        {
            for(int j=0;j<10;j++)
            {
                if(s[i]-v[j]==0)
                {
                    c--;
                    break;
                }
            }
        }
        return (c==0);
    }
};