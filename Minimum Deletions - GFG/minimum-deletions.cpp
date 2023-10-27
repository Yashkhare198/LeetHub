//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
  
    int lcs(string &S, string &T,int i,int j,vector<vector<int>>&dp)
    {
        if( i==0 || j ==0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(S[i-1] == T[j-1])
        {
            return dp[i][j] = 1 + lcs(S,T,i-1,j-1,dp);
        }
        else
        {
            return dp[i][j] = max(lcs(S,T,i-1,j,dp),lcs(S,T,i,j-1,dp));
        }
    }
    
    
    int minimumNumberOfDeletions(string S) { 
        
        // code here
        int n = S.length();
        
        if(n == 1) return 0;
        
        string T = S;
        
        reverse(S.begin(),S.end());
        
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        
        
        
         int x = lcs(S,T,n,n,dp);
        
         int i = n,j = n;
         
         return i-x;
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends