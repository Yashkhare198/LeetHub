class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int n = s.size();
        
        int ans = 0;
        
        for(int i = n-1; i>=0 ; i--)
        {
          
            if(((s[i]>='a'&& s[i]<='z') || (s[i]>='A' && s[i]<='Z')) &&  i!=0 && (s[i-1]==' '))
            {
                ans++;
                break;
                
            }
          
            else if((s[i]>='a'&& s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
            {
                ans++;
            }
           
            
        }
        return ans;
        
    }
};