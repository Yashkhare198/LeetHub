//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        
        
        // Your code goes here
        
        set<vector<int>>st;
        sort(arr.begin(),arr.end());
        
       
        
        vector<vector<int>>ans;
        
        int n = arr.size();
        // unordered_set<int>st;
        for(int i=0;i<n;i++)
        {
            for(int j =i+1;j<n;j++)
            {
                for(int m=j+1;m<n;m++)
                {
                 int s = m+1;
                 int e =n-1;
                 int target = k-arr[i]-arr[j]-arr[m];
                 
                 while(s<=e)
                 {
                     int mid = s+(e-s)/2;
                     
                     if(arr[mid] == target)
                     {
                         st.insert({arr[i],arr[j],arr[m],arr[mid]});
                         s++;
                         e--;
                     }
                     else if(arr[mid]>target)
                     {
                         e = mid-1;
                     }
                     else
                     {
                         s=mid+1;
                     }
                 }
                }
            }
        }
        ans.assign(st.begin(),st.end());
        return ans;
        
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends