/*
Hillol
*/

class Solution {
public:
    
    string getHashValue(string data){
        
        int md = 26;
        string temp = "";
        char pre = data[0];
        for(int i=0; i<data.size(); i++){
            int dif = (data[i] - pre + md) % md;
            temp = temp + "#" + to_string(dif);
        }
        return temp;
    }
    
    vector<vector<string>> groupStrings(vector<string>& strings) {
      
        unordered_map<string, vector<string>> u_mp;
        
        for(auto it : strings){
           string code = getHashValue(it);
            u_mp[code].push_back(it);
        }
        
        vector<vector<string>> ans;
        
        auto it = u_mp.begin();
        while(it != u_mp.end()){
            ans.push_back(it->second);
            it++;
        }
        return ans;
    }
};