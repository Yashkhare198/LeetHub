//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    int minOperation(int n)
    {
        //code here.
        int ans = 0;
        int x = n;
        if(n==0 || n==1)
        {
            return n;
        }
        
     while(x>=1)
     {
         if(x%2==0)
         {
             x=x/2;
         }
         else
         {
             x=x-1;
         }
         
         ans++;
         
         
     }
     return ans;
        
        
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
	        Solution ob;
	        cout<<ob.minOperation(n)<<endl;
	    }
}
// } Driver Code Ends