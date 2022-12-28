class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n = piles.size();
        priority_queue<int> q;
        for(int i=0;i<n;i++) q.push(piles[i]);
        int a=0;
        for(int i=0;i<k;i++)
        {
            a = q.top();
            q.pop();
            q.push(a-a/2);
        }
        a=0;
        while(!q.empty())
        {
            a+=q.top();
            q.pop();
        }
        return a;
    }
};