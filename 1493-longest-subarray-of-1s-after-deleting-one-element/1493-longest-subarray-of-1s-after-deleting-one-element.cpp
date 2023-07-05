class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0,c=0,ans=0;
        
        while(j!=n)
        {
            if(nums[j]==1)
            {
                j++;
            }
            else
            {
                c++;
                if(c==2)
                {
                    while(c!=1)
                    {
                        if(nums[i]==0)
                        {
                            c--;
                        }
                        // cout<<c<<endl;
                        i++;
                    }
                    j++;
                }
                else
                {
                    j++;
                }
            }
            
            // cout<<j<<" "<<i<<endl;
            if(j!=n && (nums[j]!=0 || c==0))
                ans=max(ans,j-i);
        }
        
        if(ans==n) return n-1;
        
        return ans;
    }
};