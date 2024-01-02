class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int maxi=0;
        map<int,int> mp;
        int n=nums.size();
        
        for(int i=0;i<n;i++) 
        {
            mp[nums[i]]++;
            maxi=max(maxi, mp[nums[i]]);
        }
        
        vector<vector<int>> res(maxi);
        
        for(auto it: mp)
        {
            int freq=it.second;
            int val=it.first;
            int i=0;
            while(freq--)
            {
                res[i].push_back(val);
                i++;
            }
        }
        
        return res;
    }
};