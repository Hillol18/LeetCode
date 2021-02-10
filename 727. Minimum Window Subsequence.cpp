/*
Hillol
*/

/**
Given strings S and T, find the minimum (contiguous) substring W of S, so that T is a subsequence of W.

If there is no such window in S that covers all characters in T, return the empty string "". If there are multiple such minimum-length windows, return the one with the left-most starting index.

Example 1:

Input:
S = "abcdebdde", T = "bde"
Output: "bcde"
Explanation:
"bcde" is the answer because it occurs before "bdde" which has the same length.
"deb" is not a smaller window because the elements of T in the window must occur in order.
**/

class Solution {
public:
    string minWindow(string S, string T) {
        int len = S.size();
        int j=0;
        int lenT=T.size();
        string ans = "";
        int pos=0,plen=0;
        for(int i=0;i<len;i++){
            if(S[i] == T[j]){
                j++;
            }

            if(j==lenT){

                int ind = i;
                j--;
                while(ind >= 0 && j >= 0){
                    if(S[ind] == T[j]){
                        j--;
                        if(j<0 && (plen == 0 || plen > (i-ind+1))){
                            pos=ind;
                            plen = (ind, i-ind+1);
                        }
                    }
                    ind--;
                }

                j=lenT-1;
            }
        }

        if(plen)
        ans = S.substr(pos,plen);
       return ans;
    }
};
