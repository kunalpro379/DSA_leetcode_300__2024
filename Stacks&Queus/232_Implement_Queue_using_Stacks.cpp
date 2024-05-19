class MyQueue {
public:
    stack<int>Stk1;
    stack<int>Stk2;

    MyQueue() {
        
    }
    
    void push(int x) {
        Stk1.push(x);
    }
    
    int pop() {
        if(Stk2.empty()){
            while(!Stk1.empty()){
                    Stk2.push(Stk1.top());
                    Stk1.pop();
            }
        }
        int frnt=Stk2.top();
        Stk2.pop();
        return frnt; 
    }
    
    int peek() {
        if(Stk2.empty()){
            while(!Stk1.empty()){
                    Stk2.push(Stk1.top());
                    Stk1.pop();
            }
        }return Stk2.top();
    }
    
    bool empty() {
        return Stk1.empty()&&Stk2.empty();
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