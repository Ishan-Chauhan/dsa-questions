class Solution {
public:
    int lb(vector<int>& ages, int x, int n)
    {
        int l=0,r=n-1,mid, ans=-1;
        int minage = x/2+7;
        
        while(l<=r)
        {
            mid=(l+r)/2;
            
            if(ages[mid]>minage)
            {
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        
        return ans;
    }
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(), ages.end());
        
        int i=0;
        int n=ages.size();
        int l, minage, r, ans=0,rep;
        
        while(i!=n)
        {
            int l = lb(ages, ages[i], n);
            
            rep=1, r=i+1;
            while(r<n && ages[i]==ages[r])
            {
                r++;
                rep++;
            }
            
            // cout<<l<<r;
            if(l!=-1 && l<r)
            {
                ans+=(r-1-l)*rep;
            }
            i=r;
        }
        
        return ans;
    }
};