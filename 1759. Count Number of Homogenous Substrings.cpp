class Solution {
public:
    int countHomogenous(string s) {
        char ch;
        long long ans = 0;
        long long int cnt = 0;
        long long md = 1e9+7;
        for(int i = 0; i<=s.size(); i++){
            if(ch != s[i]){
                ans += (cnt * (cnt+1))/2ll;
                if(ans >= md) ans %= md;
                cnt = 1;
                ch = s[i];
            }
            else{
                cnt++;
            }
        }
        return ans;
    }
};