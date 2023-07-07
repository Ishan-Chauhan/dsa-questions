class Solution {
public:
    int maxConsecutiveAnswers(string ans, int k) {
        int n = ans.size();
        int i=0,j=0;
        int t=0,f=0;
        int maxi=0;
        
        while(j!=n)
        {
            if(ans[j]=='T')  t++;
            else  f++;
            
            if(t<k || f<k)
            {
                maxi = max(maxi, j-i+1);
            }
            if((t>=k && f==k) || (t==k && f>=k))
            {
                maxi = max(maxi, j-i+1);
            }
            if(t>k && f>k)
            {
                while(t>k && f>k)
                {
                    if(ans[i]=='T')  t--;
                    else  f--;
                    i++;
                }
            }
            j++;
        }
        return maxi;
    }
};