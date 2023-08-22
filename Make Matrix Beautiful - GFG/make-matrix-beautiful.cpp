//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        // code here 
        int maxi = INT_MIN;
           int total = 0;
        for(int i = 0; i<n ; i++)
        {int col = 0;
        int row = 0;
     
            for(int j = 0;j<n;j++)
            {
                col +=matrix[j][i];
                row +=matrix[i][j];
                total +=matrix[i][j];
            }
            maxi = max(maxi,max(row,col));
        }
        
        return (maxi*n)-total;
        
        
    } 
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends