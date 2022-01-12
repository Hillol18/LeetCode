/*
1771
1877=1881
1881
100
18810

*/

class Solution {
public:
      
    long long int getPalindrom(long long value, bool isOdd){
        long long d = 1;
        long long div = 10;
        long long ans = value;
        
        if(isOdd) value /= 10;
        
        while(value){
            ans *= 10;
            ans += (value % 10);
            value /= 10;
        }
        return ans;
    }
    
    void setValue(long long cur, long long pre, long long &dif, long long &ans){
        long long d = abs(cur - pre);
        
        if(dif == d) ans = min(ans, cur);
        else if(dif > d){
            ans = cur;
            dif = d;
        }
    }
    
    string nearestPalindromic(string n) {  

        int len = n.size();
        int mid = len % 2 + len / 2;   
        long long int left = stoll(n.substr(0, mid));
        long long int num = stoll(n);
        long long dif = num;
        
        long long ans = 0;
        
        long long temp = getPalindrom(left, len % 2);
        
        if(temp != num && abs(num - temp) <= dif){
            
            ans = temp;
            dif = abs(num - temp);
        }
        
        temp = getPalindrom(left + 1, len % 2);
        if(temp != num && abs(num - temp) <= dif){
            setValue(temp, num, dif, ans);
        }
        
        temp = getPalindrom(left - 1, len % 2);
        if(temp != num && abs(num - temp) <= dif){
            setValue(temp, num, dif, ans);
        }
        
        temp = pow(10, len);
        temp++;
        //cout<<temp<<endl;
        if(temp != num && abs(num - temp) <= dif){
            setValue(temp, num, dif, ans);
        }
        
        temp = pow(10, len-1);
        temp--;
        //cout<<num<<" "<<temp<<" "<<dif<<" "<<(num - temp)<<endl;
        if(temp != num && abs(num - temp) <= dif){
            
            setValue(temp, num, dif, ans);
        }
        cout<<dif<<endl;
        return to_string(ans);
    }
};