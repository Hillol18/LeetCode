class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int k=0;
        int cost=0;
        int n = s.size();
        int mx =0;
        for(int i=0;i<n;i++){
            cost+=abs(s[i]-t[i]);
            while(cost>maxCost){
                cost-=abs(s[k]-t[k]);
                k++;
            }
            mx = max(mx, i-k+1);
        }
        return mx;
    }
};
