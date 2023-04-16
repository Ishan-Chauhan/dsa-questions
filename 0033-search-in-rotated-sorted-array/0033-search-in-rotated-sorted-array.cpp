class Solution {
public:
    int sol(vector<int> nums, int l,int r,int target)
    {
        if(l>r) return -1;
        int mid=l+(r-l)/2;
        if(nums[mid]==target) return mid;
        if(nums[mid]<nums[r])
        {
            if(target>nums[mid] && target<=nums[r])
                return sol(nums,mid+1,r,target);
            return sol(nums,l,mid-1,target);
        }
        else if(nums[l]<nums[mid])
        {
            if(target>=nums[l] && target<nums[mid])
                return sol(nums,l,mid-1,target);
            // return sol(nums,mid+1,r,target);   
        }
        return sol(nums,mid+1,r,target);   
        //return -1;
    }
    int search(vector<int>& nums, int target) {
        return sol(nums,0,nums.size()-1,target);
    }
};