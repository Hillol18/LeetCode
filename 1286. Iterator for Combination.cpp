/*
3
abcdefg

abg

*/
class CombinationIterator {
public:
    vector<int> mp;
    int len;
    string chs;
    string itr = "";
    
    CombinationIterator(string characters, int combinationLength) {
        mp.resize(26, -1);
        for(int i = 0; i< characters.size(); i++){
            mp[characters[i] - 'a'] = i;
        }
        
        
        len = combinationLength;
        chs = characters;
    }
    
    string next() {
        
        int n = len - 1;
        int m = chs.size() - 1;
        if(itr.size() == 0) {
            itr = chs.substr(0, len);
            return itr;
        }
        
        int dif = -1;
        while((n-dif) >= 0 && itr[n - dif] == chs[m - dif]){
            dif++;
        }
        
        bool flag = true;
         int idx = -1;
        cout<<dif<<endl;
        while((n - dif) <= n){           
            if(idx == -1){
                idx = mp[itr[n - dif] - 'a'];
            }
            idx++;
            //cout<<" "<<idx<<endl;
            itr[n-dif] = chs[idx];
            
            dif--;
        }
        return itr;
    }
    
    bool hasNext() {
        if(!len) return false;
        
        //cout<<itr<<" "<<chs.substr(chs.size() - len + 1)<<endl;
        if( chs.substr(chs.size() - len ) == itr) return false;
        
        return true;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */