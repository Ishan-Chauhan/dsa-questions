class Solution {
public:
    vector<vector<int>> r;
    vector<int> areas;
    
    Solution(vector<vector<int>>& rects) {
        r=rects;
        int n=r.size();
        
        for(int i=0;i<n;i++)
        {
            if(i==0) areas.push_back((r[i][2]-r[i][0]+1) * (r[i][3]-r[i][1]+1));
            else areas.push_back(areas.back()+ (r[i][2]-r[i][0]+1) * (r[i][3]-r[i][1]+1));
        }
    }
    
    vector<int> pick() {
        int area = rand()%areas.back()+1;
        int idx = lower_bound(areas.begin(), areas.end(), area) - areas.begin();
        
        int x = rand()%(r[idx][2]-r[idx][0]+1) +r[idx][0];
        int y = rand()%(r[idx][3]-r[idx][1]+1) +r[idx][1];
        
        return {x,y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick(); 
*/