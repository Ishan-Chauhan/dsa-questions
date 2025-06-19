class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int target) {
        int n=v.size(), m=v[0].size();

        int l=0, h=n*m-1, mid;
        int r,c;

        while(l<=h)
        {
            mid = l+(h-l)/2;
            r = mid/m;
            c = mid%m;

            // cout<<r<<" "<<c<<" "<<v[r][c]<<endl;

            if(v[r][c]==target) return true;
            else if(v[r][c] > target) h = mid-1;
            else l = mid+1;
        }
        return false;
    }
};