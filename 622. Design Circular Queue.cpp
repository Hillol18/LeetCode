class MyCircularQueue {
public:
    int sz;
    deque<int>dqu;
    MyCircularQueue(int k) {
        dqu.clear();
        sz = k;
    }

    bool enQueue(int value) {
        if(dqu.size() == sz) return false;

        dqu.push_back(value);
        return true;
    }

    bool deQueue() {
        if(dqu.size() == 0) return false;

        dqu.pop_front();
        return true;
    }

    int Front() {
        if(!dqu.size()) return -1;
        return dqu.front();
    }

    int Rear() {
        if(!dqu.size()) return -1;
        return dqu.back();
    }

    bool isEmpty() {
        return (dqu.size()==0);
    }

    bool isFull() {
        return (dqu.size()==sz);
    }
};
