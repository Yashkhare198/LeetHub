//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
		
		int prediacte(int x,int y )
		{
		    if(y>=x)return 1;
		    
		    return 0;
		}
		int last(int y,int x)
		{
		    if(y<=x) return 1;
		    
		    return 0;
		}
	int count(int arr[], int n, int x) {
	    // code here
	    int s = -1;
	    int e = n;
	    int mid;
	    
	    while(s+1<e)
	    {
	        mid = s+(e-s)/2;
	        
	        if(prediacte(x,arr[mid])==0)
	        {
	            s = mid;
	        }
	        else
	        {
	            e=mid;
	        }
	        
	    }
	    
	    int l = -1;
	    int r = n;
	    int m;
	    
	    while(l+1 < r)
	    {
	        m = l+(r-l)/2;
	        
	        if(last(arr[m],x)==1)
	        {
	            l = m;
	        }
	        else
	        {
	            r = m;
	        }
	    }
	    
	    if(arr[e]!=x) return 0;
	    
	    return l-e+1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends