//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        
        int s = -1;
        int e = n;
        vector<int>ans;
        
        while(s+1<e)
        {
            int mid = s+(e-s)/2;
            
            if(arr[mid]<=x)
            {
                s=mid;
            }
            else
            {
                e=mid;
            }
        }
        
        int l = -1;
        int r = n;
        
        while(l+1<r)
        {
            int mid = l + (r-l)/2;
            
            if(arr[mid]>=x)
            {
                r = mid;
            }
            else
            {
                l=mid;
            }
        }
        
        if(s == -1 ||arr[s]!=x )
        {
            return {-1,-1};
        }
        ans.push_back(r);
        ans.push_back(s);
        
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
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends