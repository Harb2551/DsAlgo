class NStack
{
public:
    // Initialize your data structure.
    vector <int> s;
    vector <int> top;
    vector <int> next;
    int free;
    NStack(int N, int S) 
    {
        // Write your code here.
        s.resize(S);
        top.resize(N,-1);
        next.resize(S);
        for(auto i=0;i<S-1;i++)
            next[i] = i+1;
        next[S-1] = -1;
        free = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // Write your code here.
        if(free==-1)
            return false;
        s[free] = x;
        int temp = next[free];
        if(top[m-1]==-1)
            next[free] = -1;
        else
            next[free] = top[m-1];
        top[m-1] = free;
        free = temp;
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // Write your code here.
        if(top[m-1]==-1)
            return -1;
        int temp = s[top[m-1]];
		int curfree = free;
        free = top[m-1];
        top[m-1] = next[free];
        next[free] = curfree;
        return temp;
    }
};











