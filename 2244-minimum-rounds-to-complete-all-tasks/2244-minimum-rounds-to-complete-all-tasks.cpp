class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n = tasks.size();
        map<int,int> m;
        int c=0;
        for(int i=0;i<n;i++)
        {
            m[tasks[i]]++;
            if(m[tasks[i]]==1) c++;
            else if(m[tasks[i]]==2) c--;
        }
        if(c!=0) return -1;
        c=0;
        for(auto it:m)
        {
            if(it.second%3==0)  c+=it.second/3;
            else if(it.second%3==1) c+=(2+(it.second-4)/3);
            else c+=(1+(it.second-2)/3);
        }
        return c;
    }
};