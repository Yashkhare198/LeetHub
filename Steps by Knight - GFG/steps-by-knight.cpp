//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&K,vector<int>&T,int N)
	{
	    // Code here
	    
	    const int dx[8] = {-2,-2,-1,1,2,2,-1,1};
	    const int dy[8] = {-1,1,-2,-2,-1,1,2,2};
	    
	    
	    queue<pair<pair<int,int>,int>>q;
	    
	    q.push({{K[0],K[1]},0});
	    
	    vector<vector<int>>vis(N+1,vector<int>(N+1,0));
	    
	    vis[K[0]][K[1]] = 1;
	    
	    while(!q.empty())
	    {
	        int r = q.front().first.first;
	        int c = q.front().first.second;
	        int steps = q.front().second;
	        
	        q.pop();
	        
	        if(r == T[0] && c ==T[1])
	        {
	            return steps;
	        }
	        
	        for(int i = 0; i<8;i++)
	        {
	            int x = r+dx[i];
	            int y = c+dy[i];
	            
	            if(x>=1 && x<=N && y>=1 && y<=N && vis[x][y] == 0)
	            {
	                q.push({{x,y},steps+1});
	                vis[x][y] = 1;
	            }
	            
	           
	            
	            
	        }
	        
	        
	    }
	    
	    return -1;
	    
	    
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends