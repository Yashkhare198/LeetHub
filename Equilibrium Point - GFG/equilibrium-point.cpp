//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

#include <vector>
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        if(n == 1) 
        {return 1;}
        
        vector<long long>pref(n);
        
        pref[0] = a[0];
        
        for(int i = 1; i<n ; i++)
        {
            pref[i] = pref[i-1] + a[i];
        }
        
        
        int ans = -1;
        
        for(int i = 0; i<n ; i++)
        {
            if(i-1<0)
            {
                if(pref.back()-pref[i] ==0)
                {
                    return i+1;
                }
            }
            else if(i+1>=n)
            {
                if(pref[i-1]==0)
                {
                    return i+1;
                }
            }
            else
            {
                if(pref[i-1]==pref.back()-pref[i])
                {
                    return i+1;
                }
            }
        }
        return ans;
        
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends