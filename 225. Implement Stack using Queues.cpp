class MyStack {
    queue<int> q1;
    queue<int> q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        for (int i = q1.size()-1; i > 0; i--){
            q2.push(q1.front());
            q1.pop();
        }
        int x = q1.front();
        q1.pop();
        for (int i = q2.size(); i > 0; i--){
            q1.push(q2.front());
            q2.pop();
        }
        return x;
    }
    
    int top() {
        return q1.back();
    }
    
    bool empty() {
        return q1.empty();
    }
};