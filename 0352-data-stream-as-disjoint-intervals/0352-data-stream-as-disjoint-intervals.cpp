class SummaryRanges {
public:
    set<int> st;
    SummaryRanges() {}
    
    void addNum(int value) {
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> result; 
        int n = size(st); 
        auto firstIt = begin(st), secondIt = begin(st);
        ++secondIt;    
        for(int i = 0; i < n ; i++) {
            int start = *firstIt;          
            while(i < n-1 && *firstIt + 1 == *secondIt) {
                i++;
                firstIt++, secondIt++;
            }
            result.push_back({start, *firstIt});
            ++firstIt, ++secondIt;
        }   
        return result;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */