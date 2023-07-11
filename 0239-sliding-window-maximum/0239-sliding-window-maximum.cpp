class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> st;
        int i=0,j=0,n=nums.size();
        vector<int> ans;
        for(j=0;j<n;j++)
        {
            if(j-i+1<=k) st.insert(nums[j]);
            
            if(j-i+1==k)
            {
                ans.push_back(*st.rbegin());
                
                st.erase(st.find(nums[i]));
                i++;
            }
        }
        return ans;
    }
};