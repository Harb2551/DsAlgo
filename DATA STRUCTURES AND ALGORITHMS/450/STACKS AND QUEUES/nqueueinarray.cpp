class NQueue{
public:
    // Initialize your data structure.
    vector <int> arr;
    vector <int> next;
    vector <int> front;
    vector <int> last;
    int free;
    NQueue(int n, int s){
        // Write your code here.
        arr.resize(s);
        next.resize(s);
        last.resize(s,-1);
        front.resize(n,-1);
        for(auto i=0;i<s-1;i++)
            next[i] = i+1;
        next[s-1] = -1;
        free=0;
    }

    // Enqueues 'X' into the Mth queue. Returns true if it gets pushed into the queue, and false otherwise.
    bool enqueue(int x, int m){
        // Write your code here.
        if(free==-1)
            return false;
        arr[free] = x;
         if(front[m-1]==-1)
            front[m-1] = free;
         else
            next[last[m-1]] = free;
        int temp = next[free];        	
        last[m-1] = free;  
        next[free] = -1;
        free = temp;
        return true;
    }

    // Dequeues top element from Mth queue. Returns -1 if the queue is empty, otherwise returns the popped element.
    int dequeue(int m){
        // Write your code here.
        if(front[m-1]==-1)
            return -1;       
        int p = front[m-1];        
        front[m-1] = next[p];
        next[p] = free;
        free = p;
        return arr[p];
    }
};








