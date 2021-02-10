/*
Hillol
*/

/**
Given a string, find the length of the longest substring T that contains at most k distinct characters.

Example 1:

Input: s = "eceba", k = 2
Output: 3
Explanation: T is "ece" which its length is 3.
Example 2:

Input: s = "aa", k = 1
Output: 2
Explanation: T is "aa" which its length is 2.
**/

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
      int len = s.size();
      int fcnt = 128;
      vector<vector<int>>frequency(len, vector<int>(128,0));
      //vector<unordered_map<int,int>>vecotr
      for(int i=0;i<len;i++){
          int idx = s[i];
          frequency[i][idx]=1;
          if(i==0)
              continue;

          for(int j=0;j<fcnt;j++){
              frequency[i][j]+=frequency[i-1][j];
          }
      }
      int f=0, l = 0;

      int ans = 0;
      while(l<len){
          int total = 0;
          for(int i=0;i<fcnt;i++){

              int cnt = frequency[l][i] - frequency[f][i];

              if(s[f] == i){
                cnt++;
              }

              if(cnt)
                  total++;
          }

          if(total <= k){
              ans = max(ans, l-f+1);
              l++;
          }
          else{
              f++;
              if(f>l){
                  l++;
              }
          }
      }
    return ans;

    }
};
