class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    unordered_map<int, unordered_set<int>> mp;
    vector<int> arr;
    int cnt = 0;
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        auto it = mp.find(val);
    
        if(arr.size() == cnt){
            arr.push_back(val);
        } 
        else{            
            arr[cnt] = val;
        }
            
        mp[val].insert(cnt);
        cnt++;
    
        return mp[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        //cout<<" - "<<val<<endl;
        
        auto it = mp.find(val);
        if((it != mp.end()) && it->second.size()){
            auto it2 = it->second.begin();
            auto itLast = mp.find(arr[cnt-1]);
            if(it->first != itLast->first){
                int firstIndex = *it2;
                it->second.erase(it2);    
                itLast->second.erase(cnt-1);
                itLast->second.insert(firstIndex);
                swap(arr[firstIndex], arr[cnt-1]);
            }
            else{
                it->second.erase(cnt-1);
            }
                       
            cnt--;
            return true;
        }
        return false;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int sz =  cnt;
        if(cnt) sz = rand() %cnt;
        return arr[sz];
    }
};