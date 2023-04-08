//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        // code here
     stack<int>st;
        
        for(int i=0;i<arr.size();i++){
            if(!st.empty()&& ((st.top()>=0&&arr[i]<0)||(st.top()<0&&arr[i]>=0))){
                st.pop();
            }
            else{
                st.push(arr[i]);
            }
        }
        arr.clear();
        
        while(!st.empty()){
            arr.push_back(st.top());
            st.pop();
            
        }
        reverse(arr.begin(),arr.end());
        return arr;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> res = obj.makeBeautiful(arr);
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }

        cout << "\n";
    }
}
// } Driver Code Ends