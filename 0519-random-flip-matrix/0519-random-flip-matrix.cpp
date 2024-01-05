class Solution {
public:
    int m;
    int n;
    set<pair<int,int>>u;
    Solution(int m, int n) {
        this->m = m;
        this->n = n;
    }
    
    vector<int> flip() {
        while(true){
            int i = rand()%m;
            int j = rand()%n;
            if(u.find({i,j})==u.end()){
                u.insert({i,j});
                return {i,j};
            }
        }
        return {};
    }
    
    void reset() {
        u.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */