class Solution {
public:
    double trimMean(vector<int>& arr) {
        double sum=0;
        int n = arr.size();
        int r = n/20;
        sort(arr.begin(),arr.end());
        for(int i=r;i<n-r;i++) sum+=arr[i];
        return sum/(n-2*r);
    }
};