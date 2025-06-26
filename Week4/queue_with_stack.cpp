class MyQueue {
    int stk_in[100], stk_out[100];
    int p_in, p_out;

public:
    MyQueue()
    {
        p_out = p_in = 0;
    }

    void shift_stacks()
    {
        while(p_out < 100 && p_in > 0)
        {
            stk_out[p_out++] = stk_in[--p_in];
        }

        return;
    }
    
    void push(int x)
    {
        if (p_in != 100)
        {
            stk_in[p_in++] = x;
        }
        else
        {
            shift_stacks();
            stk_in[p_in++] = x;
        }
    }
    
    int pop()
    {
        if (p_out == 0)
        {
            shift_stacks();
        }

        if (p_out == 0)
            return -1;
        
        return stk_out[--p_out];
    }
    
    int peek()
    {
        if (p_out == 0)
        {
            shift_stacks();
        }

        if (p_out == 0)
            return -1;
        
        return stk_out[p_out - 1];
    }
    
    bool empty()
    {
        if (p_in == 0 && p_out == 0)
            return true;
        else
            return false;
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