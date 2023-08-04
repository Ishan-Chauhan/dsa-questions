class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> v(60,0);
        int n=time.size();
        int ans=0;
        long long temp;
        
        for(int i=0;i<n;i++)
        {
            v[time[i]%60]++;
        }
        
        for(int i=1;i<=29;i++)
        {
            temp = v[i];
            temp*=v[60-i];
            ans += temp;
        }
        temp = v[30]-1;
        temp*=v[30];
        temp/=2;
        ans += temp;
        temp = v[0]-1;
        temp*=v[0];
        temp/=2;
        ans += temp;
        return ans;
    }
};