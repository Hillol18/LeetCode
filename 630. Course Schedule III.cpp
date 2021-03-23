/*
[,,,,,]
 |     |                         |      |     |
[6,7],[2,10],[10,11][8,14][5,15][5,16] [3,19][2,19]
*/

class Solution {
public:
    struct cmp{
      bool operator()(vector<int> &a, vector<int> &b){
          return a[0] < b[0];
      }
    };

    bool static cmp1 (vector<int> &a, vector<int> &b){
        return a[01] <b[01];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        priority_queue<vector<int>, vector<vector<int>>, cmp> qu;
        sort(courses.begin(), courses.end(), cmp1);
        int n =  courses.size();
        int cnt = 0;
        int sum = 0;
        int i=0;

        int mx = 0;
        for(i=0;i<n;i++){
            sum = sum + courses[i][0];
            qu.push(courses[i]);
            cnt++;

            while(sum >courses[i][1] && !qu.empty()){
                //cout<<"in"<<endl;
                sum-=qu.top()[0];
                qu.pop();
                cnt--;

            }

            cout<<sum<<" "<<cnt<< endl;
        }
        return cnt;
    }
};
