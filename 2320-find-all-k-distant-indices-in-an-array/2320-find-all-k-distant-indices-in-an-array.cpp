class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n=nums.size(),l,h;

        vector<int> v;

        for(int i=0;i<n;i++)
        {
            l = max(0, i-k);
            h = min(n-1, i+k);
            for(int j=l;j<=h;j++)
            {
                if(nums[j]==key)
                {
                    v.push_back(i);
                    break;
                }
            }
        }
        return v;
    }
};