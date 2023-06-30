//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isDivisible(string s){
	    //complete the function here
	    
	    int n = s.length();
	    int even = 0;
	    int odd = 0;
	    
	   for(int i =n-1 ;i>=0 ; i--){
	       if((i)%2 == 0){
	       if((s[i]-'0')&1)
	       {
	           even++;
	       }
	       }
	       else{
	           if((s[i]-'0')&1)
	       {
	           
	           odd++;
	       }
	       }
	   }
	    return (abs(even-odd)%3==0)?1:0;
	}

};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends