class MyStack {
public:
   // vector<int>stack;
    queue<int>q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
     int size=q.size();
     for(int i=0;i<size-1;i++){
        q.push(q.front());
        q.pop();
     }
     int top=q.front();
     q.pop();
     return top;

    }
    
    int top() {
        return q.back();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */