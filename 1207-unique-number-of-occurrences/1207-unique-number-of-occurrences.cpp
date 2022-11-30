class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        map<int,int> a,b;
        for(int i=0;i<n;i++)
        {
            a[arr[i]]++;
        }
        for(auto it: a)
        {
            b[it.second]++;
            if(b[it.second]==2) return false;
        }
        return true;
    }
};