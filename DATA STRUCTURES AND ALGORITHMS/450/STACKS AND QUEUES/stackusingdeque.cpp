class Stack
{
public:
    // Initialize your data structure.
    deque <int> d;
    Stack()
    {
    }

    // Pushes 'X' into the stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x)
    {
        // Write your code here.
        d.push_back(x);
    }

    // Pops top element from Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop()
    {
        // Write your code here.
        if(d.empty())
            return -1;
        int temp = d.back();
        d.pop_back();
        return temp;
    }

    // Returns the topmost element of the stack. In case the stack is empty, it returns -1.
    int top()
    {
        // Write your code here.
        if(d.empty())
            return -1;
        return d.back();
    }

    // Returns true if the stack is empty, otherwise false.
    bool isEmpty()
    {
        // Write your code here.
        return d.empty();
    }

    // Returns the number of elements currently present in the stack.
    int size()
    {
        // Write your code here.
        return d.size();
    }
};