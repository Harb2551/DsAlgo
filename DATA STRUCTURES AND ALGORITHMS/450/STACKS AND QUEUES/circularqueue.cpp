#include <bits/stdc++.h>
using namespace std;

class CircularQueue{
    public:
    // Initialize your data structure.
    queue <int> q;
    int s = 0;
    CircularQueue(int n){
        // Write your code here
        s = n;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        // Write your code here.
        if(q.size()==s)
            return false;
        q.push(value);
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        // Write your code here.
        if(q.empty())
            return -1;
        int temp = q.front();
        q.pop();
        return temp;
    }
};