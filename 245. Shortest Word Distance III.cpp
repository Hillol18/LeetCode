/**
Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

word1 and word2 may be the same and they represent two individual words in the list.

Example:
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Input: word1 = “makes”, word2 = “coding”
Output: 1
Input: word1 = "makes", word2 = "makes"
Output: 3
Note:
You may assume word1 and word2 are both in the list.

**/

class Solution {
public:
    int fun(vector<string>& words, string &w, int cur){
        int len = words.size();
        while(cur<len){
            if(words[cur] == w){
                return cur;
            }
            cur++;
        }
        return len+1;
    }
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        
        int len = words.size();
        int ans = len+1;
        bool f=1;
        int fp,sp=-1;
        fp=fun(words, word1, 0);
      
        
        if(word1 == word2){
            f=0;
        }
        sp = fun(words, word2, !f? fp+1:0);
        
        while(fp <len &&(sp < len)){
            ans = min(ans, abs(fp-sp));
            if(!f){
                int x = fun(words, word1, sp+1);
                fp=sp;
                sp=x;
            }
            else{
                if(fp<sp){
                    fp = fun(words, word1, fp+1);
                }
                else{
                    sp = fun(words, word2, sp+1);
                }
            }
        }
        return ans;
    }
};