class Solution {
public:
    int minimizeSet(int d1, int d2, int uc1, int uc2) {
        long long s=uc1+uc2, e=10000000000;
        long long lcm = (1LL*d1*d2)/__gcd(d1, d2);
        
        while(s<e)
        {
            long long mid = s+(e-s)/2;
            
            long long both=mid/lcm;
            long long onlyd1=mid/d1-both;
            long long onlyd2=mid/d2-both;
            
            long long remain=mid-onlyd1-onlyd2-both;
            
            if(uc2>onlyd1) remain -= (uc2-onlyd1);
            if(uc1>onlyd2) remain -= (uc1-onlyd2);
            
            if(remain>=0) e=mid;
            else s=mid+1;
        }
        return s;
    }
};