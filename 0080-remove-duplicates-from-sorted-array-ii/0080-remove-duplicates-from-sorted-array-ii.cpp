class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=1,f=0;
	    for(int i=1; i<nums.size(); i++) 
        {
		    if(nums[i]!=nums[i-1] || f==0) 
            {
                if(nums[i]==nums[i-1]) f=1;
                else if(nums[i]!=nums[i-1]) f=0;
                nums[k++] = nums[i];   
            }
        }
	    return k;
    }
};