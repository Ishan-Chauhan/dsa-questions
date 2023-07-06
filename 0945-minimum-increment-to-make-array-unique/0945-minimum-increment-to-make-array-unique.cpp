class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        // set<int> st;
        // for(auto it:nums) st.insert(it);
        int mini= *min_element(nums.begin(), nums.end());
        int ans=0;
        sort(nums.begin(), nums.end());
        
        for(auto it: nums)
        {
            // cout<<it<<endl;
            if(it>mini)
            {
                mini =it;
            }
            else if(it<mini)
            {
                ans += mini-it;
            }
            mini++;
        }
        return ans;
    }
};