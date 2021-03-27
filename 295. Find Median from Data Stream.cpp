class MedianFinder {
public:
    /** initialize your data structure here. */
    struct cmp{
    bool operator()(const int &a,const int &b){
        return a>b;
    }
    };

    priority_queue<int> fq;
    priority_queue<int,vector<int>,cmp> sq;
    MedianFinder() {

    }

    void addNum(int num) {

        fq.push(num);
        if(fq.size()>sq.size()){
            sq.push(fq.top());
            fq.pop();
        }
        else{
            int x = fq.top(), y= sq.top();
            if(x > y){
                fq.pop();
                sq.push(x);
                y= sq.top();
                sq.pop();
                fq.push(y);
            }
        }

    }

    double findMedian() {
        if(sq.size()){
           if(fq.size() && fq.size() == sq.size()){
              return (double(fq.top() + sq.top()))/2.0;
           }
            return sq.top();
        }
        return 0;
    }
};
