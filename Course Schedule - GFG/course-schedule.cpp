//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> pre) 
    {
        //code here
         vector<int>indegree(n,0);
        vector<vector<int>>adj(n);
        for(int i=0;i<pre.size();i++){
           indegree[pre[i][0]]++;;
            adj[pre[i][1]].push_back(pre[i][0]);
        }
      
         queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        int cnt = 0;
vector<int>topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
topo.push_back(node);
            cnt++;

            for(auto child : adj[node]){
                indegree[child]--;
                if(indegree[child] == 0){
                    q.push(child);
                }
            }
        }

      if(topo.size()==n) return topo;
     
      return {};
   

    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends