class Solution {
public:

    int toBit(vector<int> &cells){
        int bit = 0;
        for(int i=0;i<cells.size();i++){
            if(cells[i])
                bit|=(1<<i);
        }
        return bit;
    }

    vector<int> toArray(int bit, int n){
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(bit&(1<<i)){
                ans.push_back(1);
            }
            else ans.push_back(0);
        }
        return ans;
    }

    vector<int> prisonAfterNDays(vector<int>& cells, int n) {

         vector<int> ans;

        map<int,int> mp;

        int key = toBit(cells);
        int cnt = 0;
        int nn = cells.size();
        while(mp.find(key) == mp.end() ){
            mp[key] = cnt;
            cnt++;
            int nkey = 0;
            for(int i=1;i<(nn-1);i++){

                int pre = i-1;
                int next = i+1;
                if((((1<<pre) & key) > 0) == (((1<<next) & key) > 0)){
                    nkey |= (1<<i);
                }
            }
            key=nkey;

        }


        int idx;
        if(cnt>n){
            idx = n;
        }
        else{
            int start = mp[key];
            int dif = cnt-start;
            int ed = (n-start)%dif;
            idx = start + ed;
        }

        auto it=mp.begin();
        while(it != mp.end()){
            if(it->second == idx){
                break;
            }
            it++;
        }

        ans = toArray(it->first, nn);

        return ans;
    }
};
