//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int minimumCost(vector<vector<int>>& flights, int n, int k) {
        // code here
        vector<vector<pair<int,int>>>adj(n+1);

        for(int i = 0; i<flights.size() ; i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];

            adj[u].push_back({v,wt});
        }

        queue<pair<int,int>>q;

        vector<int>dis(n+1,1e9);
        dis[k]=0;

        q.push({k,0});

        while(!q.empty()){
             auto it = q.front();
             int node = it.first;
             int wt = it.second;

             q.pop();

             for(auto x:adj[node]){
                 int child = x.first;
                 int sig = x.second;

                 if(wt+sig < dis[child]){
                     dis[child] =wt +sig;
                     q.push({child,wt+sig});
                 }
             }


        }
        
int maxi=-1;
        for(int i=1;i<=n;i++){
            if(dis[i] == 1e9){
               
                return -1;
            }
            maxi=max(maxi,dis[i]);
        }
         
          return maxi;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size,vector<int>(3));
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i]=temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}

// } Driver Code Ends