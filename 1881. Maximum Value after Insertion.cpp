class Solution {
public:
    string maxValue(string n, int x) {
        bool flag = true;
        if(n[0] == '-') flag = false;
        int p = 0;
        if(!(n[0] >= '0' && n[0] <= '9')) p =1;
        string ans;
        
            for(int i = p; i<n.size(); i++){ 
                if(((n[i] - '0') <x && flag) || ((n[i] - '0') > x && !flag)){
                    //cout<<n[i] - '0'<<endl;
                    ans = n.substr(0, i) + to_string(x) + n.substr(i);
                    return ans;
                }
            }
            ans = n + to_string(x);
      
       return ans;
    }
};