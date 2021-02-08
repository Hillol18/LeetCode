class Solution {
public:

    struct cmp{
        bool operator()(pair<int, string> &a, pair<int, string> &b){
            if(a.first == b.first){
                return a.second<b.second;
            }

            return a.first > b.first;
        }
    };


    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> dic;
        int len = words.size();
        for(int i=0;i<len;i++){
           dic[words[i]]++;
        }

        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;

        auto it = dic.begin();

        vector<string> ans;

        while(it != dic.end()){
            //cout<<"ind"<<endl;
            pq.push(make_pair(it->second, it->first));

            if(pq.size()>k) pq.pop();
            it++;
        }


        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
