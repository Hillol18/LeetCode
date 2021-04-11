class Solution {
public:

    bool check(string &w, string &w2, vector<int> &mp){
        int wsz = w.size();
        int w2sz = w2.size();

        for(int i=0;i<min(wsz, w2sz);i++){
            if(mp[w[i]-'a'] > mp[w2[i]-'a']) return false;
            if(mp[w[i]-'a'] < mp[w2[i]-'a']) return true;
        }

        if(wsz > w2sz) return false;
        return true;
    }

    bool isAlienSorted(vector<string>& words, string order) {
        int n = words.size();
        vector<int>mp(26,-1);
        for(int i=0;i<order.size();i++){
            mp[order[i]-'a']= i;
        }

       for(int i=1;i<n;i++){
           if(!check(words[i-1], words[i], mp)) return false;
       }
        return true;
    }
};
