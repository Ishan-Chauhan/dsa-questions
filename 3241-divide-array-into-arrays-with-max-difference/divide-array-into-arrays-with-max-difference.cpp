class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for(int i=0;i<n;i+=3)
        {
            // cout<<nums[i+2]-nums[i]<<" ";
            if(nums[i+2]-nums[i]>k) return {};

            vector<int> t(3);
            t[0] = nums[i];
            t[1] = nums[i+1];
            t[2] = nums[i+2];

            res.push_back(t);
        }

        return res;
    }
};