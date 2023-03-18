// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l=1,r=n,mid;
        while(l<r)
        {
            mid = l+(r-l)/2;
            if(isBadVersion(mid))   r=mid;
            else l=mid;
            
            if(l==r-1)
            {
                if(isBadVersion(l)) return l;
                return r;
            }
        }
        return l;
    }
};