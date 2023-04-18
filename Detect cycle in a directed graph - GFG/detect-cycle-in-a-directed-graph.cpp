//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int a;
  
  bool dfs(vector<int> *adj,int node,vector<int>&vis,vector<int>&pathVis){
      vis[node]=1;
      pathVis[node]=1;
      for(auto x:adj[node]){
          if(!vis[x]){
              if(dfs(adj,x,vis,pathVis)==true){
                  return true;
              }
          }
          else if(pathVis[x]){
              return true;
          }
      }
      pathVis[node]=0;
      return false;
  }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>vis(V,0);
         vector<int>pathVis(V,0);
        a=V;
        for(int i=0;i<V;i++)
        {
            if(!vis[i]){
                if(dfs(adj,i,vis,pathVis)==true)
                return 1;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends