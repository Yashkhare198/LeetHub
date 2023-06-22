//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int n, vector<int> &arr) 
    {
        int cnt_5=0;
        int cnt_10=0,cnt_20=0;
        if(arr[0]!=5)
        {
            return false;
        }
        for(int i=0;i<n;i++)
        {
            if(arr[i]==5)
            {
                cnt_5++;
            }
            else if(arr[i]==10)
            {
                if(cnt_5>0)
                {
                    cnt_5--;
                }
                else
                {
                    return false;
                }
                cnt_10++;
            }
            else if(arr[i]==20)
            {
                if(cnt_5>0 && cnt_10>0)
                {
                    cnt_5--;
                    cnt_10--;
                }
                else if(cnt_5>=3)
                {
                    cnt_5=cnt_5-3;
                }
                else
                {
                    return false;
                }
                cnt_20++;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends