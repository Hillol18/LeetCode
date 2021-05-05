class MedianFinder {
public:
    /** initialize your data structure here. */

    struct cmp{
        bool operator()(int &a, int &b){
            return a>b;
        }
    };
    priority_queue<int> mxHeap;
    priority_queue<int, vector<int>, cmp> mnHeap;

    MedianFinder() {
        while(!mxHeap.empty())mxHeap.pop();
        while(!mxHeap.empty())mnHeap.pop();

    }

    void addNum(int num) {
        mxHeap.push(num);

        mnHeap.push(mxHeap.top());
        mxHeap.pop();
        if(mnHeap.size() > mxHeap.size()){
            mxHeap.push(mnHeap.top());
            mnHeap.pop();
        }

    }

    double findMedian() {
        int n = mxHeap.size() + mnHeap.size();
        double ans = 0;
        if(n%2) {
            ans = mxHeap.top();
        }
        else{
            ans = mxHeap.top();
            ans+= mnHeap.top();
            ans/=2.00;
        }
        return ans;
    }
};
