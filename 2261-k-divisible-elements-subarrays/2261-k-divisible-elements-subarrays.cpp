class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n=nums.size();
        
        set<vector<int>> st;
        
        for(int i=0;i<n;i++)
        {
            vector<int> v;
            int c=0;
            
            for(int j=i;j<n;j++)
            {
                if(nums[j]%p==0) c++;
                v.push_back(nums[j]);
                
                if(c<=k) st.insert(v);
                else break;
            }
        }
        
        return st.size();
    }
};