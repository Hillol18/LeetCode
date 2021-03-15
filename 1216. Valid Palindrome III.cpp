/*
Given a string s and an integer k, find out if the given string is a K-Palindrome or not.

A string is K-Palindrome if it can be transformed into a palindrome by removing at most k characters from it.
*/

class Solution {
public:

    int help(int f, int l, string &s, vector<vector<int>> &dp){

        if(f>l)
            return 0;

        int &ret=dp[f][l];


        if(ret!=-1)
            return ret;

        ret = s.size();

        if(s[f] == s[l]){
            ret = min(ret, help(f+1,l-1, s, dp));
        }
        else {
            ret = min(ret, 1+help(f+1,l, s, dp));
            ret = min(ret, 1+help(f,l-1, s, dp));
        }

        return ret;
    }

    bool isValidPalindrome(string s, int k) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        int ans = help(0,s.size()-1, s, dp);
        return ans<=k;
    }
};

/*
Nafiul
*/
class Solution {
public:

    bool isValidPalindrome(string s, int k) {

        int n = s.size();

        if(n<2) return 0;

        vector<int> a(n, 0);
        vector<int> b(n, 0);
        vector<int> cur(n, 0);

        for(int i=0;i<n-1;i++){
            b[i]=(s[i]!=s[i+1]);
        }

        if(n==2)
            return b[0];


        for(int i=3;i<=(n);i++){
            for(int j=0;j<(n-i+1);j++){
                if(s[j] == s[j+i-1]){
                    cur[j]=a[j+1];
                }
                else{
                    cur[j] = 1+ min(b[j], b[j+1]);
                }
                //cout<<cur[j]<<" ";
            }
            //cout<<endl;
            a=b;
            b=cur;
        }

        int ans = b[0];
        cout<<ans<<endl;

        return ans<=k;
    }
};

/*
      |   |
    a b c d e c a

    0 1 2 3 4 5 6
  1 0 0 0 0 0 0 0
  2 1 1 1 1 1 1
  3 2 2 2 2 2
  4 3 3 1 3
  5 3 2 2
  6 3 3
  7 2

    b a a c a c a a
    0 1 2 3 4 5 6 7
  2 1 0 1 1 1 1 0
  3 1 1 0 0 0 1
  4 2 1 1 1 1
  5 2 2 0 2
  6 3 0 1
  7



*/
