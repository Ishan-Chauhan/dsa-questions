class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        
        for(int i=0;i<32;i++)
        {
            int count=0;
            for(int j=0;j<n;j++)
            {
                if((1<<i)&nums[j]) count++;
            }
            if(count%3!=0) res |= (1<<i);
        }
        
        return res;
    }
};