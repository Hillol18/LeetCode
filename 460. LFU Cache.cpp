/*

hash_map (key, position in the list pair<value, frequency>)

frequency, list
   1         dequeue<int>

*/


class LFUCache {
public:
    int cap;
    int size = 0;
    int minFrequency = 1;
    unordered_map<int, list<int>> frequency_mp; // frequency, [key]
    unordered_map<int, list<int>:: iterator> key_frq_mp; // key, [frequency_mp iterator}
    unordered_map<int, pair<int, int>> key_mp; //key, (value, frequency)

    LFUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        int ans = -1;
        if(key_mp.find(key) != key_mp.end()){
            auto obj = key_mp[key];
            ans = obj.first;
            int frq = obj.second;
            auto it = key_frq_mp[key];
            frequency_mp[frq].erase(it);
            frequency_mp[frq + 1].push_back(key);
            auto up_it = frequency_mp[frq+1].end();
            up_it--;
            key_frq_mp[key] = up_it;
            key_mp[key] = make_pair(obj.first, frq+1);
            if(frq == minFrequency && frequency_mp[frq].begin() == frequency_mp[frq].end()) minFrequency++;

        }

        return ans;
    }

    void put(int key, int value) {
        if(key_mp.find(key) != key_mp.end()){
            auto obj = key_mp[key];
            auto it = key_frq_mp[key];
            int frq = obj.second;
            frequency_mp[frq].erase(it);
            frequency_mp[frq + 1].push_back(key);

            auto up_it = frequency_mp[frq+1].end();
            up_it--;
            key_frq_mp[key] = up_it;

            key_mp[key] = make_pair(value, frq+1);

            if(frq == minFrequency && frequency_mp[frq].begin() == frequency_mp[frq].end()) minFrequency++;

        }
        else{
            size++;
            if(size > cap && cap){

                auto it = frequency_mp[minFrequency].begin();
                auto obj = key_mp[*it];
                key_mp.erase(*it);
                key_frq_mp.erase(*it);
                frequency_mp[minFrequency].erase(it);
                size--;
            }

            if(size <= cap && cap){
                frequency_mp[1].push_back(key);
                auto it = frequency_mp[1].end();
                it--;
                key_frq_mp[key] = it;
                key_mp[key] = make_pair(value,1);
                minFrequency = 1;
            }

        }
    }
};
