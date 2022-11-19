class Solution {
public:
    int countPrimes(int n) {
        vector<bool> v(n,true);
        int c=0;
        for(int i=2;i*i<n;i++)
        {
            if(v[i])
            {
                for(int j=i*i;j<n;j+=i)
                {
                    v[j]=false;
                }
            }
        }
    
        for(int i=2;i<n;i++)
        {
            if(v[i]) c++;
        }
        return c;
    }
};