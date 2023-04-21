//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  bool dfs(int node,vector<int>*adj,int color[],int cl){
      color[node] = cl;
      
      for(auto x: adj[node]){
          if(color[x]==-1){
              if(dfs(x,adj,color,!cl)==false) return false;
          }
          else if(color[x]==cl){
              return false;
          }
      }
      return true;
  }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    
	    int color[V];
	    
	    for(int i = 0; i<V; i++) color[i] = -1;
	    
	    int cl = 0;
	    for(int i = 0; i<V ;i++){
	        if(color[i]== -1){
	            if(dfs(i,adj,color,cl)==false)
	            {
	                return false;
	            }
	            
	        }
	    }
	    return true;
	    
	    
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends