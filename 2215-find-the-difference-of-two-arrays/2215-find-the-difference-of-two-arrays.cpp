class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2,vector<int>());
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        
        int n=nums1.size(),m=nums2.size();
        int i=0,j=0;
        while(i!=n && j!=m)
        {
            if(i>0 && nums1[i]==nums1[i-1])
            {
                i++;
                continue;
            }
            if(nums1[i]<nums2[j]) 
            {
                ans[0].push_back(nums1[i]);
                i++;
            }
            else if(nums1[i]==nums2[j])
            {
                i++;
                // j++;
            }
            else
            {
                j++;
            }
        }
        if(j==m)
        {
            while(i!=n) 
            {
                if(i>0 && nums1[i]==nums1[i-1])
                {
                    i++;
                    continue;
                }
                ans[0].push_back(nums1[i]);
                i++;
            }
        }
        i=0,j=0;
        while(i!=n && j!=m)
        {
            if(j>0 && nums2[j]==nums2[j-1])
            {
                j++;
                continue;
            }
            if(nums1[i]>nums2[j]) 
            {
                ans[1].push_back(nums2[j]);
                j++;
            }
            else if(nums1[i]==nums2[j])
            {
                // i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        if(i==n)
        {
            while(j!=m) 
            {
                if(j>0 && nums2[j]==nums2[j-1])
                {
                    j++;
                    continue;
                }
                ans[1].push_back(nums2[j]);
                j++;
            }
        }
        return ans;
    }
};