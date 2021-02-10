/**
Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

Example:
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Input: word1 = “coding”, word2 = “practice”
Output: 3
Input: word1 = "makes", word2 = "coding"
Output: 1
**/

class Solution {
public:

    int nextPos(vector<string>& words, string &word, int cur){
        int len = words.size();
        while(cur<len){
            if(words[cur] == word){
                return cur;
            }
            cur++;
        }
        return len;
    }


    int shortestDistance(vector<string>& words, string word1, string word2) {

        int len = words.size();
        int fp = nextPos(words, word1, 0);
        int sp = nextPos(words, word2, 0);
        int ans =len;
        while(1){

            if(fp>=len || sp>=len)
                break;


            ans=min(ans,abs(fp-sp));

            if(fp<sp){
                fp = nextPos(words, word1, fp+1);
            }
            else sp= nextPos(words,word2,sp+1);
        }

        return ans;
    }
};
