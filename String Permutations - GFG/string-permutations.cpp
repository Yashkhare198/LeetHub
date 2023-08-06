//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    void perm(int x,vector<string>&ans,string S)
    {
        if(x>=S.length())
        {
            ans.push_back(S);
            return;
        }
        
        for(int i = x; i<S.size();i++)
        {
            swap(S[i],S[x]);
            perm(x+1,ans,S);
             swap(S[i],S[x]);
        }
    }
    
    vector<string> permutation(string S)
    {
        //Your code here
        vector<string>ans;
        
       
        
        perm(0,ans,S);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends