class MyQueue {
    stack<int> push_stk;
    stack<int> pop_stk;
    
public:
    
    MyQueue() : push_stk(), pop_stk() {}
   
    void push(int x){
        push_stk.push(x);
    }

    int pop() {
        if (empty()) return -1;

        if (pop_stk.empty()){
            while (!push_stk.empty()){
                pop_stk.push(push_stk.top());
                push_stk.pop();
            }
            int top = pop_stk.top();
            pop_stk.pop();
            return top;
        }
        else{
            int top = pop_stk.top();
            pop_stk.pop();
            return top;
        }
    }

    int peek() {
        if (empty()) return -1;

        if (!pop_stk.empty()){
            return pop_stk.top();
        }
        else{
            while (!push_stk.empty()){
                pop_stk.push(push_stk.top());
                push_stk.pop();
            }
            return pop_stk.top();
        }
    }

    bool empty() {
        return (push_stk.empty() && pop_stk.empty());
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