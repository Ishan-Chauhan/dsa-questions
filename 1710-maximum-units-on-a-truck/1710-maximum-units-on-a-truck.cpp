class Solution {
public:
    int maximumUnits(vector<vector<int>>& box, int truckSize) {
        int n = box.size();
        for(int i=0;i<n;i++) swap(box[i][0], box[i][1]);
        
        sort(box.begin(), box.end());
        reverse(box.begin(), box.end());
        
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            if(box[i][1]>=truckSize)
            {
                ans += truckSize*box[i][0];
                break;
            }
            ans+=(box[i][0]*box[i][1]);
            truckSize-=box[i][1];
        }
        return ans;
    }
};