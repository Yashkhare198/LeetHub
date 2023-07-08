//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    if(n == 1) return arr[0];
	    
	    int prev = arr[0];
	    
	    int prev2 = 0;
	    int curri = 0;
	    
	    for(int i =1; i<n ; i++){
	        
	        int take = arr[i];
	        
	        if(i>1){
	            take += prev2;
	        }
	        
	        int notTake = 0 + prev;
	        curri = max(take,notTake);
	        
	        prev2 = prev;
	        prev = curri;
	        
	    }
	    return curri;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends