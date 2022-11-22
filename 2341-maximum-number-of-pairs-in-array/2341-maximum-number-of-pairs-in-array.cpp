class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        vector<int> v(2,0);
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            if(i<n-1 && nums[i]==nums[i+1])
            {
                v[0]++;
                i++;
            }
        }
        v[1] = n-2*v[0];
        return v;
    }
};