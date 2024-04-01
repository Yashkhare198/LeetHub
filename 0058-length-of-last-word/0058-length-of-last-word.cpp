class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int n = s.length();
        
        int ans = 0;
        bool x = false;
        
        for(int i = n-1; i>=0 ; i--)
        {
         
            if(x==true && (s[i] == ' '))
            {
               
                break;
                
            }
         
            else if((s[i]>='a'&& s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
            {
                ans++;
                x=true;
            }
            
        }
        return ans;
        
    }
};