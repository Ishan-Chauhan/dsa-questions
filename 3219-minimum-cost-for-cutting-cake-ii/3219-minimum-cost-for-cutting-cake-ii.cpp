class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& hc, vector<int>& vc) {
        
        long long hsum=0, vsum=0;

        for(long long i=0;i<n-1;i++) vsum+=vc[i];
        for(long long i=0;i<m-1;i++) hsum+=hc[i];

        if(m==1) return vsum;
        if(n==1) return hsum;

        sort(hc.begin(), hc.end());
        reverse(hc.begin(), hc.end());

        sort(vc.begin(), vc.end());
        reverse(vc.begin(), vc.end());

        long long i=1, j=1;
        long long a=0,b=0;
        long long x = hc[0], y=vc[0];
        long long int ans=0;

        while(a<m-1 && b<n-1)
        {
            y=vc[b];
            x=hc[a];
            if(y>=x)
            {
                ans += j*y;
                i++;
                b++;
            }
            else
            {
                ans += i*x;
                j++;
                a++;
            }

        }
        while(a<m-1)
        {
            x=hc[a];
            ans += i*x;
            // for(int p=0;p<i;p++) ans+=x;
            a++;
        }
        while(b<n-1)
        {
            y=vc[b];
            ans += j*y;
            // for(int p=0;p<j;p++) ans+=y;
            b++;
        }
        return ans;
    }
};