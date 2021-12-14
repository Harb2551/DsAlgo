void interLeaveQueue(queue <int> &q) {
    // Write your code here.
    queue <int> q1,q2;
    int n = q.size();
    int c=0;
    while(c!=n/2){
        q1.push(q.front());
        q.pop();       
        c++;
    }
    while(c!=n){
        q2.push(q.front());
        q.pop();
        c++;
    }
    while(!q1.empty()){
        q.push(q1.front());
        q1.pop();
        q.push(q2.front());
        q2.pop();
    }
}