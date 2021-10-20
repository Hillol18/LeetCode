class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> st1, st2;
    
    
    void populateSt2(){
         while(!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
    }
    
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        st1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(st2.empty()){
            populateSt2();
        }
        
        int ans = st2.top();
        st2.pop();
        return ans;
    }
    
    /** Get the front element. */
    int peek() {
        if(st2.empty()){
           populateSt2();
        }
        return st2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return !(st1.size() || st2.size());
    }
};
