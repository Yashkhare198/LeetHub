//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int n, vector<pair<int, int> >& pre) {
	    // Code here
	    
	     vector<int>indegree(n,0);
        vector<vector<int>>adj(n);
        for(int i=0;i<pre.size();i++){
           
            adj[pre[i].first].push_back(pre[i].second);
            indegree[pre[i].second]++;
           
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

      if(topo.size()==n) return true;
      
      return false;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends