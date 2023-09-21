//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int thief(int arr[],vector<int>&dp,int n,int i)
    {
        
        if(dp[i]!=-1) return dp[i];
        
        int take = arr[i];
        if(i>1)
       {
           take += thief(arr,dp,n,i-2);
       }
       
       int notTake = arr[i-1];
       if(i>2)
       {
           notTake += thief(arr,dp,n,i-3);
           
           
       }
       
       return dp[i] = max(take,notTake);
   
        
    }
    
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        vector<int>dp(n,-1);
        
        
        thief(arr,dp,n,n-1);
        
        return dp[n-1];
        
        
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends