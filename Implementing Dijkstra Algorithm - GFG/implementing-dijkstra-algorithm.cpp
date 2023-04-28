//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
     
        vector<vector<pair<int, int>>> a(V);
        for (int i = 0; i < V; i++) {
            for (auto x : adj[i]) {
                int u = i;
                int v = x[0];
                int wt = x[1];
                a[u].push_back({v, wt});
                a[v].push_back({u, wt});
            }
        }
        
        vector<int> dis(V, INT_MAX);
        dis[S] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, S});
        
        while (!pq.empty()) {
            auto n = pq.top();
            int node = n.second;
            int d = n.first;
            pq.pop();
            if (d > dis[node]) {
                continue;
            }
            for (auto x : a[node]) {
                int child = x.first;
                int wt = x.second;
                if (dis[node] + wt < dis[child]) {
                    dis[child] = dis[node] + wt;
                    pq.push({dis[child], child});
                }
            }
        }
        
        return dis;
    


    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends