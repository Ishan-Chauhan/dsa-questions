class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size()-1;
        int l=0,r=n,mid;
        while(l<=r)
        {
            mid=l+(r-l)/2;
            //cout<<mid<<endl;
            if(nums[mid]==target)
                return mid;
            if(nums[mid]<target)
                l=mid+1;
            else
                r=mid-1;
        }
        return -1;
    }
};