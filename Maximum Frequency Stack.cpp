
class FreqStack {
public:

    set<pair<int, pair<int, int>>> st;
    int cnt = 0;
    unordered_map<int,int>mp;
    FreqStack() {
        st.clear();
        mp.clear();
    }

    void push(int x) {
        mp[x]++;
        st.insert(make_pair(mp[x], make_pair(cnt++,x)));
    }

    int pop() {
        auto it=st.end();
//        while(it!=)
        it--;
        mp[it->second.second]--;

        //cout<<it->first<<" "<<it->second.first<<" "<<it->second.second<<endl;
        int ans = it->second.second;
        st.erase(it);
       return ans;

    }
};


class FreqStack {
public:

    set<pair<int, pair<int, int>>> st;
    int cnt = 0;
    unordered_map<int,int>f;
    unordered_map<int,stack<int>>m;
    FreqStack() {
        f.clear();
        m.clear();
    }

    void push(int x) {
        f[x]++;
        if(cnt < f[x]){
            cnt = f[x];
        }

        m[f[x]].push(x);

    }

    int pop() {
       int ans =  m[cnt].top();
        m[cnt].pop();
        f[ans]--;
        if(m[cnt].empty()) cnt--;

       return ans;
    }
};
