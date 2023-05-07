//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  vector<long long int>d;
  int mod =1e9+7;
  long long int prev = 1,prev2 = 0;
  long long int memo(int n)
  {
      if(n<=1) return n;
        if(d[n] != -1) return d[n];
        
        return d[n] = (memo(n-1)+memo(n-2))%mod; 
  }
    long long int topDown(int n) {
        // code here
        d.resize(n+1);
        for(int i =0;i<=n;i++){
            d[i] = -1;
        }
        memo(n);
        
    }
    long long int bottomUp(int n) {
        // code here
        
        for(int i = 2; i<=n ; i++){
            
            long long int curr  =(prev + prev2)%mod;
            
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends