class Solution {
public:
    int find(vector<vector<int>>& items, int& n, int a)
    {
        int l=0,h=n-1, m, idx ;
        
        if(items[0][0]>a) return -1;
        
        while(l<=h)
        {
            m = l+(h-l)/2;

            if(items[m][0]>a) h = m-1;
            else
            {
                idx = m;
                l = m+1;
            }
        }
        return idx;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int q=queries.size();
        int n = items.size();

        sort(items.begin(), items.end());
        for(int i=1;i<items.size();i++)
        {
            items[i][1]=max(items[i-1][1],items[i][1]);
        }
        vector<int> res(q, 0);

        for(int i=0;i<q;i++)
        {
            int idx = find(items, n, queries[i]);
            if(idx>=0) res[i] = items[idx][1];
        }

        return res;
    }
};