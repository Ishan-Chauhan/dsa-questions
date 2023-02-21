class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0, r=nums.size()-1, mid;
        while(l<r)
        {
            mid = l + (r-l)/2;
            if(nums[mid]==nums[mid+1])
            {
                if((mid-l)%2==0) l=mid+2;
                else r=mid-1;
            }
            else if(nums[mid]==nums[mid-1])
            {
                if((r-mid)%2==0) r=mid-2;
                else l=mid+1;
            }
            else return nums[mid];
            
            // cout<<l+1<<" "<<r+1<<endl;
        }
        return nums[l];
    }
};