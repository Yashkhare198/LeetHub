//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:

bool palind(string s){
    int i=0;
    int j=s.size()-1;
    
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        else{
            i++;
            j--;
        }
    }
    return true;
}

    int addMinChar(string str){    
        //code here
        
        if(palind(str)) return 0;
        
        for(int i=str.size()-1;i>=0;i--){
            if(palind(str.substr(0,i)))
            {
                return str.length()-i;
            }
        }
        return str.length()-1;
        
    }
};

//{ Driver Code Starts.


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin >> str;
        
        Solution ob;
        cout << ob.addMinChar(str) << endl;
    }
    return 0; 
} 
// } Driver Code Ends