//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<vector<int>> a(V); // Fix 1: Change a to a vector of V vectors

        for (int x = 0; x < V; x++) // Fix 2: Loop over the vertices, not the adjacency list itself
        {
            for (auto i : adj[x]) // Fix 3: Loop over the neighbors of vertex x
            {
                a[x].push_back(i);
            }
        }
        vector<int> ans;

        queue<int> q;
        q.push(0);
        ans.push_back(0);
        vector<int> vis(V, 0);

        vis[0] = 1; // Fix 4: Mark the first node as visited before starting the traversal

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            // ans.push_back(node); // Fix 5: Don't push the node here, since it's already added before in the initialization.

            for (auto x : a[node])
            {
                if (!vis[x])
                {
                    vis[x] = 1;
                    q.push(x);
                    ans.push_back(x); // Fix 6: Push the neighboring node here when it's visited, not in the previous loop.
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends