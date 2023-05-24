class Solution {
public:
    int check(vector<int> v,vector<vector<int>> ans)
    {
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i]==v)
                return 0;
        }
        return 1;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),a,b;
        vector<vector<int>> ans;
        for(int i=0;i<n-3;i++)
        {
            if(nums[i]>target && target>0)continue;
            if(i!=0 && nums[i]==nums[i-1])continue;
            for(int j=i+1;j<n-2;j++)
            {
                if(nums[j]==nums[j-1] && i!=0 && nums[i]==nums[i-1])continue;
                a=j+1;
                b=n-1;
                while(a<b)
                {
                    //cout<<i<<" "<<j<<" "<<a<<" "<<b<<" "<<endl;
                    //cout<<nums[i]<<" "<<nums[j]<<" "<<nums[a]<<
 //" "<<nums[b]<<" "<<endl;
                    long long int p=nums[i];
                    p+=nums[j];
                    p+=nums[a];
                    p+=nums[b];
                    if(p==target)
                    {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[a]);
                        temp.push_back(nums[b]);
                        if(check(temp,ans))
                        {
                            ans.push_back(temp);
                        }
                        a++;
                        b--;
                        //while(a<b-1 && nums[a]==nums[a+1])a++;
                        //while(b>a+1 && nums[b]==nums[b-1])b--;
                    }
                    else if(p>target)
                    {
                        b--;
                        //while(a<n-1 && nums[a]==nums[a+1])a++;
                        //while(b>a+1 && nums[b]==nums[b-1])b--;
                    }
                    else
                    {
                        a++;
                        //while(b>0 && nums[b]==nums[b-1])b--;
                        //while(a<b-1 && nums[a]==nums[a+1])a++;
                    }
                }
            }// -2 -1 -1 1 1 2 2
        }
        return ans;
    }
};