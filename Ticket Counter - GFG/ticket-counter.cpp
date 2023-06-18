//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int N, int K) {
        // code here
        deque<int> dq;
        
        
        for(int i=1; i<=N ; i++){
            dq.push_back(i);
        }
        int i=1;
        
        bool x =true;
        
        while(dq.size()){
            if(dq.size()==1){
                return dq.front();
            }
            
            if(x == true){
                if(i%K==0){
                dq.pop_front();
                x=false;
                }
                else{
                     dq.pop_front();
                }
              
            }
             else{
                if(i%K==0){
                dq.pop_back();
                x=true;
                }
                else{
                     dq.pop_back();
                }
              
            }
            i++;
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends