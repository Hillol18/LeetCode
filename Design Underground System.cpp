class UndergroundSystem {
public:

    unordered_map<int,pair<string, int>> c_mp;
    unordered_map<string, pair<double, double>> mp;

    UndergroundSystem() {
        c_mp.clear();

    }

    void checkIn(int id, string stationName, int t) {
        c_mp[id]=make_pair(stationName,t);
    }

    void checkOut(int id, string stationName, int t) {
        auto it = c_mp.find(id);
        if(it != c_mp.end()){
            string key = it->second.first +"#"+ stationName;
            if(mp.find(key) == mp.end()){
                mp[key] = make_pair(0,0);
            }
            mp[key].first +=(t-it->second.second);
            mp[key].second +=1;
            c_mp.erase(it);
        }
    }

    double getAverageTime(string startStation, string endStation) {
       auto it = mp.find(startStation+"#"+endStation);
        if(it != mp.end()){
           return it->second.first/ it->second.second;
        }
        return 0.00;
    }
};
