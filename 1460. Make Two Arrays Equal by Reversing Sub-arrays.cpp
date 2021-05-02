class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n = target.size();
        int m = arr.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[target[i]]++;
        }


        for(int i=0;i<m;i++){
            auto it = mp.find(arr[i]);
            if(it == mp.end()) return false;

            it->second--;
            if(it->second==0) mp.erase(it);

        }

        if(mp.size()==0) return true;
        return false;
    }
};
