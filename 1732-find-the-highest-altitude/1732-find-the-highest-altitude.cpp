class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi=0;
        int n=gain.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=gain[i];
            maxi=max(ans, maxi);
        }
        return maxi;
    }
};