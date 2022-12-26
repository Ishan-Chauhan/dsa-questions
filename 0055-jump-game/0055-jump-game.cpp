class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int f=0;
        vector<int> v(n,0);
        v[0]=1;
        for(int i=0;i<n;i++)
        {
            if(v[i]==1)
            {
                int len = min(n-1,i+nums[i]);
                for(int j=i;j<=len;j++) v[j]=1;
            }
        }
        return v[n-1]==1;
    }
};