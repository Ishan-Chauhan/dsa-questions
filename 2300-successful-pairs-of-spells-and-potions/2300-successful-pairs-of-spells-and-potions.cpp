class Solution {
public:
    int bs(long l, long r, long long t, vector<int>& potions, long success)
    {
        int mid = (r-l)/2+l;
        while(l<=r)
        {
            mid = (r-l)/2+l;
            if(t*potions[mid]>=success)
            {
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
            // cout<<r<<" ";
        }
        // cout<<endl;
        return r;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        // sort(spells.begin(), spells.end());
        sort(potions.begin(), potions.end());
        int n = spells.size();
        int m = potions.size();
        vector<int> res(n,0);
        // int f;
        long long temp;
        
        for(int i=0;i<n;i++)
        {
            int j = bs(0,m-1,spells[i], potions, success);
            if(j==-1) 
            {
                res[i]=m;
                continue;
            }
            long long temp = potions[j];
            temp *= spells[i];
            
            if(j==m-1 && temp<success) continue;
            
            if(j!=m-1) j+=1;
            res[i]+=m-j;
        }
        
        return res;
    }
};