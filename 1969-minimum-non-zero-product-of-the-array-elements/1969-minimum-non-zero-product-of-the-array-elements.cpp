class Solution {
public:
    long long sol(long long a, long long b, long long m)
    {
        if(b==0) return 1;
        
        long long ans = sol(a, b/2, m);
        ans = ans*ans % m;
        
        if(b&1) return (ans* (a%m)) %m;
        return ans;
    }
    int minNonZeroProduct(int p) {
        long long maxi = (1LL << p)-1;
        long mod = 1000000007;
        
        long long temp = sol(maxi-1, maxi/2, mod);
        
        return ((maxi%mod)*temp)%mod;
    }
};
