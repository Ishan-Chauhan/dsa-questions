class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n,1e4+1);
        v[n-1]=0;
        for(int i=n-2;i>=0;i--)
        {
            for(int j=1;j<=nums[i];j++)
            {
                // cout<<1+v[i+j]<<" ";
                v[i] = min(v[i],1+v[min(i+j,n-1)]);
            }
            // cout<<endl;
        }
        return v[0];
    }
};