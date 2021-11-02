class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        string t = s;
        reverse(s.begin(), s.end());
        string r = s;
        s = t + "#" + s;

        int m = s.size();
        vector<int> table(m, 0);

        int j = 1, i = 0;
        
        while(j<m){
            while(i > 0 && i<j && s[i] != s[j]) {     
                
                i = table[i-1];
                
            }

            if(s[i] == s[j])
            i++;

            table[j] = i;
            //cout<<j<<" "<<i<<endl;
            j++;
            
        }
        
        m = n - table[m-1];
        //cout<<m<<" "<<r<<endl;
        string prefix = r.substr(0, m);
        
        return prefix + t;
        
    }
};