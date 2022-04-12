class MyQueue {
public:
    stack<int> stk;
    MyQueue() {
        
    }
    
    void push(int x) {
        stk.push(x);
    }
    
    int pop() {
        stack<int> stkTemp;
        while(stk.size()>0){
            stkTemp.push(stk.top());
            stk.pop();
        }
        int element = stkTemp.top();
        stkTemp.pop();
        while(stkTemp.size()>0){
            stk.push(stkTemp.top());
            stkTemp.pop();
        }
        return element;
    }
    
    int peek() {
        stack<int> stkTemp;
        while(stk.size()>0){
            stkTemp.push(stk.top());
            stk.pop();
        }
        int element = stkTemp.top();
        while(stkTemp.size()>0){
            stk.push(stkTemp.top());
            stkTemp.pop();
        }
        return element;
    }
    
    bool empty() {
        return stk.size()==0;
    }
};
/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */