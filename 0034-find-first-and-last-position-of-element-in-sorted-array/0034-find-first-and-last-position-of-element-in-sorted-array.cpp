class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {vector<int> v(2,-1);
        auto a = lower_bound(nums.begin(),nums.end(),target);
        auto b = upper_bound(nums.begin(),nums.end(),target);
        
        if(a==nums.end() || *a!=target) return {-1,-1};
        
        int start = a-nums.begin();
        int end = b-nums.begin()-1;
        
        return {start,end};
    }
};