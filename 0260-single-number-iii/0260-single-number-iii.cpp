class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res(2);
        int n=nums.size(), x=0;
        
        for(int i=0;i<n;i++) x ^= nums[i];
        
        int bit=0;
        while((x&1)==0)
        {
            x = (x>>1);
            bit++;
        }
        
        int xor1=0, xor2=0;
        
        for(auto it: nums)
        {
            if((it&(1<<bit))) xor1 = (xor1^it);
            else xor2 = (xor2^it);
        }
        res[0]=xor1;
        res[1]=xor2;
        
        return res;
    }
};