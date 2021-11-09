class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        int n = words.size();
        int m = puzzles.size();
        
        unordered_map<int, int> mp;
        int number = 0;
        for(auto it: puzzles){
            number |= (1<<(it[0]-'a'));
        }
        
        for(int i = 0; i<n; i++){
            int wIndx = 0;
            int cnt = 0;
            for(int j = 0; j<words[i].size(); j++){
                int ch = words[i][j] - 'a';
                if(wIndx & (1<<ch)) continue;
                wIndx |= (1<<ch);
            }
            
            mp[wIndx]++;
        }
        
        vector<int> ans;

        for(auto it: puzzles){
            int hash = 0, cnt = 0;
            for(int i = 0; i<it.size(); i++){
                hash |= (1<<(it[i] - 'a'));
            }
            
            int fch = 1<<(it[0]-'a');
            int mask = hash;
            
            while(hash){
                if(hash & fch) cnt+= mp[hash];
                
                hash = (hash - 1) & mask;
            }
            
            ans.push_back(cnt);
            
        }
        
        return ans;
        
    }
};