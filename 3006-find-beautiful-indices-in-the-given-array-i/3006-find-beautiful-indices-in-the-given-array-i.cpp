class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> c, d;
        
        for (int i = 0; (i + a.size()) <= s.size(); i++) {
            if (s.substr(i, a.size()) == a) c.push_back(i);
        }
        for (int i = 0; (i + b.size()) <= s.size(); i++) {
            if (s.substr(i, b.size()) == b) d.push_back(i);
        }
        
        vector<int> ans;
        for(int num1 : c) {
            for(int num2 : d) {
                if(abs(num1-num2) <= k) {
                    ans.push_back(num1);
                    break;
                }
            }
        }
        return ans;
    }
};