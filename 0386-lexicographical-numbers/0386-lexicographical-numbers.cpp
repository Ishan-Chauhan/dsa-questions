class Solution {
private:
    void dfs(string& s, vector<int>& v, int n)
    {
        if(s.length()>0)
        {
            if(stoi(s)>n) return;
            v.push_back(stoi(s));
        } 
        for(int i=0;i<10;i++)
        {
            if(s.size()==0 && i==0) continue;
            s.push_back(char('0'+i));
            dfs(s, v, n);
            s.pop_back();
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        if(n==1) return {1};
        vector<int> v;

        string temp="";
        dfs(temp,v, n);

        return v;
    }
};