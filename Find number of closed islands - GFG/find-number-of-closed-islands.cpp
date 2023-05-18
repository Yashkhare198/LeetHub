//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    const int dx[4] = {-1,0,1,0};
    const int dy[4] = {0,1,0,-1};
    
    bool bound(int i,int j,int N,int M){
        
        if(i!=0 && i!=N-1 && j!=0 && j!=M-1)return true;
        
        return false;
    }
    
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        // Code here
        
    
        
       
        
        int cnt = 0;
       
        for(int i = 0; i<N; i++){
            for(int j = 0; j<M ;j++){
               if(matrix[i][j] == 1 && bound(i,j,N,M)){
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    matrix[i][j]=2;
                    bool found = false;
                    
                     while(!q.empty()){
            auto itr = q.front();
            q.pop();
            int r = itr.first;
            int c = itr.second;
            
            for(int i = 0; i<4 ;i++){
                int nexti = r+dx[i];
                int nextj= c+dy[i];
                
                if(nexti>=0 && nextj>=0 && nexti <N && nextj<M && matrix[nexti][nextj]==1){
                    matrix[nexti][nextj] = 2;
                    q.push({nexti,nextj});
                    if(!bound(nexti,nextj,N,M))found = true;
                }
                
                
            }
        }
        if(found == false)cnt++;
                    
               }
            }
        }
        
       
        
        return cnt;
        
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends