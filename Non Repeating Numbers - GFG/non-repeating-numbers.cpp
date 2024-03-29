//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int n = nums.size();
        unordered_map<int,int>mp;
        
        for(int i = 0; i<n ; i++)
        {
            mp[nums[i]]++;
        }
        
        nums.clear();
        
        for(auto x:mp)
        {
            if(x.second == 1)
            {
                nums.push_back(x.first);
            }
        }
        sort(nums.begin(),nums.end());
        
        return nums;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends