/*
01
11
0101
01
01
1100=12
1101=13
1110=14

1010=10
1011=11

0101=5
0111=7
01
01
1010

1100

*/

class Solution {
public:
    int md = 1e9 + 7;
    bool isValid(int a, int b){
        for(int i = 0; i<4; i++){
            if(((a & (1<<i)) > 0) && ((b & (1<<i))>0)){
                return false;
            }  
        }
        return true;
    }
    
    bool isRowFill(int a){
        return ((a & 8) && (a & 4));
    }
    
    int dfs(int pos, int bit, vector<int>&pattern, vector<vector<int>> &dp){
     
        //cout<<pos<<" "<<bit<<endl;
        if(pos== 0){
            if(bit == 0) return 1;
            return 0;
        }
        
        int &ret = dp[pos][bit];
        if(ret != -1) return ret;
        
        
        if((bit & 12) == 12){
            
            int nbit = bit;
            nbit = nbit & 3;
            nbit = nbit << 2;
            return dfs(pos - 1, nbit, pattern, dp);
        }
        
        if(bit & 3 == 3) return 0;        

        ret = 0;
        for(int i = 0; i<pattern.size(); i++){
            if(isValid(bit, pattern[i])){
                int nbit = bit | pattern[i];

                ret += dfs(pos, nbit, pattern, dp);
                if(ret >= md)
                    ret %= md;
            }
        }
        
        
         
        return ret;
    }
    
    int numTilings(int n) {
        vector<int> pattern = {5,7,10,11,12,13,14};
        
        vector<vector<int>> dp(n+1, vector<int>(16, -1));
        int ans = dfs(n,0,pattern, dp);
        return ans;
    }
};