//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int row, int c) 
    {
        // code here 
        int l=0,r=c-1,t=0,b=row-1;
        vector<int> ans;
        while(l<=r && t<=b)
        {
            // cout<<l<<" "<<r<<endl;
            for(int i=l;i<=r;i++) ans.push_back(matrix[t][i]);
            t++;
            
            if(t>b) break;
            
            for(int i=t;i<=b;i++) ans.push_back(matrix[i][r]);
            r--;
            
            if(l>r) break;
            
            for(int i=r;i>=l;i--) ans.push_back(matrix[b][i]);
            b--;
            
            if(t>b) break;
            
            for(int i=b;i>=t;i--) ans.push_back(matrix[i][l]);
            l++;
            
            if(l>r) break;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends