/*
1
2
9

*/

class Solution {
public:
    
    long long nextPalinDrom(long long int value){
        string data = to_string(value);
        
        int len = data.size();
        string left = "", right = "", nLeft = "";
        
        left = data.substr(0, len/2 + len %2); 
        
        nLeft = to_string(stoi(left) + 1);
        
        int rl = len/2;
        if(rl == 0 && nLeft.size() == 2) nLeft[1] = nLeft[0];
        right = nLeft.substr(0, rl);
        reverse(right.begin(), right.end());
 
        return stoll(nLeft + right);
         
    }
    
    bool isPalindrom(long long int number){
        string num = to_string(number);
        int l = 0 , r = num.size() - 1;
        
        while(l < r && num[l] == num[r]){
            l++;
            r--;
        }
        return l>=r;
    }
    int superpalindromesInRange(string left, string right) {
        int cnt = 0;
        long long low = stoll(left);
        low = sqrt(low) - 1;
        low = nextPalinDrom(low);
        long long r = stoll(right);
        
        for (long long i = 1LL; i*i <= r; ){
            if(i*i >= stoll(left)){
                
                if(isPalindrom(i*i)){
                  cnt++;  
                } 
            }
            
            i = nextPalinDrom(i);
            
        }
        return cnt;
    }
};