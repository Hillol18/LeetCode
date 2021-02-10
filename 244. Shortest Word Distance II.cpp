/*
Design a class which receives a list of words in the constructor, and implements a method that takes two words word1 and word2 and return the shortest distance between these two words in the list. Your method will be called repeatedly many times with different parameters. 

Example:
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Input: word1 = “coding”, word2 = “practice”
Output: 3
Input: word1 = "makes", word2 = "coding"
Output: 1
Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.

*/

class WordDistance {
public:
    unordered_map<string, vector<int>> mp;
    
    WordDistance(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            mp[words[i]].push_back(i);
        }
        
    }
    
    int shortest(string word1, string word2) {
        int i=0,j=0;
        int si=mp[word1].size();
        int sj = mp[word2].size();
        int ans = max(mp[word1][si-1],mp[word2][sj-1]);

        while(i<si && j<sj){
            ans = min(ans, abs(mp[word1][i]-mp[word2][j]));
            if(mp[word1][i] < mp[word2][j])
                i++;
            else 
                j++;
        }
        return ans;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */