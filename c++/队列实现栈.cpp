class MyStack {
public:
    queue<int> mqueue_1;
    queue<int> mqueue_2;
    int index;
    /** Initialize your data structure here. */
    MyStack() {
        index = 1;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if(index == 1)
            mqueue_1.push(x);
        else
            mqueue_2.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(mqueue_1.empty()&& mqueue_2.empty())
            return 0;
            
        if(index == 1)
        {
            while(mqueue_1.size() != 1)
            {
                mqueue_2.push(mqueue_1.front());
                mqueue_1.pop();
            }
            index *= -1;
            int temp = mqueue_1.front();
            mqueue_1.pop();
            return temp;
        }
        else
        {
            while(mqueue_2.size() != 1)
            {
                mqueue_1.push(mqueue_2.front());
                mqueue_2.pop();
            }
            index *= -1;
            int temp = mqueue_2.front();
            mqueue_2.pop();
            return temp;
        }
    }
    
    /** Get the top element. */
    int top() {
        if(mqueue_1.empty()&& mqueue_2.empty())
            return 0;
            
        if(index == 1)
        {
            while(mqueue_1.size() != 1)
            {
                mqueue_2.push(mqueue_1.front());
                mqueue_1.pop();
            }
            index *= -1;
            int temp = mqueue_1.front();
            mqueue_1.pop();
            mqueue_2.push(temp);
            return temp;
        }
        else
        {
            while(mqueue_2.size() != 1)
            {
                mqueue_1.push(mqueue_2.front());
                mqueue_2.pop();
            }
            index *= -1;
            int temp = mqueue_2.front();
            mqueue_2.pop();
            mqueue_1.push(temp);
            return temp;
        }
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return mqueue_1.empty()&& mqueue_2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
