/*
Hillol
*/

/**
There is a box protected by a password. The password is a sequence of n digits where each digit can be one of the first k digits 0, 1, ..., k-1.

While entering a password, the last n digits entered will automatically be matched against the correct password.

For example, assuming the correct password is "345", if you type "012345", the box will open because the correct password matches the suffix of the entered password.

Return any password of minimum length that is guaranteed to open the box at some point of entering it.

Example 1:

Input: n = 1, k = 2
Output: "01"
Note: "10" will be accepted too.

Example 2:
Input: n = 2, k = 2
Output: "00110"
Note: "01100", "10011", "11001" will be accepted too.

**/

class Solution {
public:
    void makePattern(int take, string pat, int &k, unordered_map<string, bool> &pattern){
        if(!take){
            pattern[pat]=true;
            return;
        }
        for(int i=0;i<k;i++){
            makePattern(take-1, pat + to_string(i), k, pattern);
        }

    }


    bool fun(int &n, string &ans, int cnt, int &k, unordered_map<string, bool> &pattern){
       // cout<<cnt<<" "<<n<<endl;
        if(cnt==0){
            return true;
        }

        string cur = "";
        if(n-1 && ans.size() >= n-1){

           cur = ans.substr(ans.size()-n+1);
        }

        for(char i='0';i<(k+'0');i++){
            cur+=i;
            if(n-1 && ans.size()<(n-1)){
              ans+=i;
              if(fun(n, ans, cnt, k, pattern))
                  return true;
              ans.pop_back();
            }
            else{

                if(pattern.find(cur) == pattern.end()){
                    pattern[cur] = true;
                    ans+=i;
                    if(fun(n, ans, cnt-1, k, pattern))
                        return true;
                    //pattern[cur+ to_string(i)] = true;

                    pattern.erase(cur);
                    ans.pop_back();

                }
            }
            cur.pop_back();
        }
        return false;
    }

    string crackSafe(int n, int k) {
        unordered_map<string, bool> pattern;
        //makePattern(n, "", k, pattern);
        //cout<<"pat"<<endl;
        string ans;
        fun(n, ans, pow(k,n), k, pattern);
        return ans;
    }
};
