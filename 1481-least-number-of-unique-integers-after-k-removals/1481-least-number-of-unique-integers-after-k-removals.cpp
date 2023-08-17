class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n=arr.size();
        map<int, int> mp;
        
        for(int i=0;i<n;i++) mp[arr[i]]++;
        
        priority_queue<pair<int, int> , vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for(auto it: mp) pq.push({it.second, it.first});
        
        while(1)
        {
            pair<int, int> p= pq.top();
            
            if(p.first > k) return pq.size();
            k-=p.first;
                
            pq.pop();
        }
        return 0;
    }
};