class Solution {
public:
    
    int getBits(int number){
        int mask = 1<<7;
        int total = 0;
        while(mask & number){
            mask>>=1;
            total++;
        }
        return total;
    }
    
    bool validUtf8(vector<int>& data) {
        int prev = 0;
        
        for(auto it: data){
            int n = getBits(it);
            //cout<<n<<endl;
            if(n >= 5 || (n == 1 && prev == 0)) return false;
            
            if(n == 0 && prev == 0) continue;
            
            if((n == 0 || n > 1) && prev) return false;
            
            if(prev && n == 1) {
                prev--;
                continue;
            }
            
            if(n > 1) {
                prev = n-1;
            }
        }
        return prev == 0 ? true : false;
    }
};