/*
---------
   x 
    |
ababababaxabxabxac
123454321311111111



*/

class Solution {
public:
    
    vector<int> getMaxPalindrom(string s){
        int n = s.size();
        vector<int> palindrom(n), ans(n);
        int l = 0, r = -1, k = 0;
        
        for(int i = 0; i<n; i++){
            
            //cout<<i<<" "<<l<<" "<<r<<endl;
            k = i > r? 0 : min(palindrom[l + r - i], r - i +1);
            
            //cout<<" "<<k<<endl;
            while((i + k) < n && (i-k) >= 0 && s[i+k] == s[i - k]){
                ans[i+k] = max(ans[i+k], k*2 + 1);
                k++;
            }
            palindrom[i] = k--;
            
            if((i + k) > r){
                l = i-k;
                r = i+k;
            }
        }
        
        for(int  i = 1; i<n; i++){
            //cout<<ans[i]<<" ";
            ans[i] = max(ans[i], ans[i-1]);
        }
        //cout<<endl;
        return ans;
    }
    
    long long maxProduct(string s) {
        int n = s.size();
        
        vector<int> prefix = getMaxPalindrom(s);
        
        reverse(s.begin(), s.end());
        
        vector<int> sufix = getMaxPalindrom(s);
        
        reverse(sufix.begin(), sufix.end());
        
        long long ans = 0;
        for(int i = 0; i<n - 1; i++){
            //cout<<prefix[i]<<" "<<sufix[i]<<endl;
            ans = max(ans, ((long long)prefix[i] * (long long)sufix[i+1]));
        }
      
        return ans;
    }
};