//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int Count(vector<vector<int> >& matrix) {
        // Code here
        int n = matrix.size();
        int m = matrix[0].size();
        
        const int dx[8] = {-1,-1,0,1,1,1,0,-1};
        const int dy[8] = {0,1,1,1,0,-1,-1,-1};
        
        int ans = 0;
        for(int i = 0; i<n ; i++)
        {
            for(int j = 0; j<m ; j++)
            {
                if(matrix[i][j] == 1)
                { int cnt = 0;
                    for(int k = 0;k<8;k++)
                    {
                        int r =i+dx[k];
                        int c = j+dy[k];
                        
                        if(r>=0 && r<n && c>=0 & c<m && matrix[r][c]==0)
                        {
                            cnt++;
                        }
                    }
                    if((cnt>0) && (cnt%2 == 0))
                    {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends