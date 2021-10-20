class Solution {
public:
    
    bool isDotExists(string IP){
        bool find = false;
        for(auto ch: IP){
            if(ch == '.') find = true;
        }
        return find;
    }
    
    bool isValidIPV4(string IP){
        int dotCnt = 0;
        int zero = 0;
        int value = 0;
        bool flag = 1;
        
        for(auto ch: IP){
            //cout<<ch<<" "<<value<<" "<<zero<<endl;
            if(ch == '.'){
                if(zero == 0 && value == 0) return false;
                flag = 1; zero = 0, value = 0;
                
                dotCnt++;
            }
            else {
                
                if(flag == 1 && ch == '0'){
                    zero++;
                }
                
                if(!('0' <= ch && ch <= '9')) return false;
                
                value*=10;
                value+= (ch - '0');
                if('1' <= ch && ch <= '9') flag = 0;
            }
            //cout<<"   "<<zero<<" "<<value<<endl;
            if(zero > 1 || value > 255) return false;
            
            if(zero  && value) return false;
        }
        
        return dotCnt == 3 && (zero > 0 || value > 0);
    }
    
    
     bool isValidIPV6(string IP){
        int dotCnt = 0;
        int cnt = 0;
        int value = 0;
        bool flag = 1;
        
        for(auto ch: IP){
            if(ch == ':') {
                dotCnt++;
                if(cnt == 0) return false;
                cnt = 0;
            }
            else if (('0' <= ch && ch <= '9') || ('a' <= ch && ch <= 'f' ) || ('A' <= ch && ch <= 'F' )){
                cnt++;
            }
            else return false;
            
            if(cnt > 4) return false;
        }
        
        return dotCnt == 7 && (1<=cnt && cnt<=4);
    }
    
    string validIPAddress(string IP) {
        
        string ans = "Neither";
        if(isDotExists(IP)){
            if(isValidIPV4(IP)){
                ans = "IPv4";
            }
            
        }
        else if(isValidIPV6(IP)){
                ans = "IPv6";
        }
        return ans;
    }
};