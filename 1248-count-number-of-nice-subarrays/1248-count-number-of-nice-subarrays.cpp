class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int res=0;
        int c=0;
        
        for(int j=0;j<n;j++)
        {
            k-=(nums[j]&1);
            if(k<=0)
            {
                c=0;
            }
            
            while(k<=0)
            {
                k += (nums[i]&1);
                i++;
                c++;
            }
            res+=c;
        }
        return res;
    }
};