class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        for(int i=0;i<n;i++) tasks[i].push_back(i);
        sort(tasks.begin(),tasks.end());
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        vector<int> ans(n,0),temp;
        ans[0] = tasks[0][2];
        int time=tasks[0][1]+tasks[0][0];
        int f=0,i=1,index=1;
        while(i!=n)
        {
            f=0;
            // cout<<time;
            while(i<n && time>=tasks[i][0])
            {
                // cout<<tasks[i][2]<<" ";
                f=1;
                q.push({tasks[i][1],tasks[i][2]});
                i++;
            }
            // cout<<endl;
            if(!q.empty())
            {
                temp = q.top();
                q.pop();
                time+=temp[0];
                ans[index++]=temp[1];
            }
            else time=tasks[i][0];
        }
        while(!q.empty())
        {
            temp = q.top();
            q.pop();
            // time+=temp[0];
            ans[index++]=temp[1];
        }
        return ans;
    }
};