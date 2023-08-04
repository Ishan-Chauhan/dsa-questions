class Solution {
public:
    void func(vector<string> s,vector<string>& ans,int n,string temp,int i,string d)
    {
        if(i==n)
        {
            ans.push_back(temp);
            return;
        }
        for(char x:s[d[i]-'0'])
        {
            func(s,ans,n,temp+x,i+1,d);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans,s;
        int n=digits.size();
        if(n==0) return {};
        s={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        func(s,ans,n,"",0,digits);
        return ans;
    }
};