class MinStack {
public:
    int size = 0;
    vector<int> arr;
    vector<int> mn;
    
    MinStack() {
        
    }
    
    void push(int val) {
        if(arr.size() == size)
        {
            arr.push_back(val);
            mn.push_back(val);
        }
        else{
            mn[size] = val;
            arr[size] = val;    
        }
        
        if(size) mn[size] = min(mn[size-1], mn[size]);
        size++;
    }
    
    void pop() {
        
        size--;
    }
    
    int top() {
        
        return arr[size-1];
    }
    
    int getMin() {
        return mn[size-1];
    }
};