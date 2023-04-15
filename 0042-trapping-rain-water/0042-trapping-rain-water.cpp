class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> l(n),r(n);
        l[0]=0;
        r[n-1]=0;
        
        for(int i=1;i<n;i++)
        {
            l[i]=max(l[i-1],height[i-1]);
            //cout<<l[i]<<" ";
        }
        //cout<<endl;
        
        for(int i=n-2;i>=0;i--)
        {
            r[i]=max(r[i+1],height[i+1]);
            //cout<<r[i]<<" ";
        }
        
        int ans=0;
        for(int i=1;i<n-1;i++)
        {
            ans += (min(l[i],r[i])-height[i]>0)?min(l[i],r[i])-height[i]:0;
        }
        
        return ans;
    }
};