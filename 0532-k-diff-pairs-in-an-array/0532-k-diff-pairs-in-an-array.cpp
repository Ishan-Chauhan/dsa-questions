class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<int, int> mp;
        
        int n=nums.size(), ans=0;
        
        for(int i=0;i<n;i++) mp[nums[i]]++;
        
        for(auto it: mp)
        {
            int x=it.first;
            
            if(k==0 && it.second>1) ans++;
            else if(k!=0 && mp.find(x+k)!=mp.end()) ans++;
        }
        
        return ans;
    }
};