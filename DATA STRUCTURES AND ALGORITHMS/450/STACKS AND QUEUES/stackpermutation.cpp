bool validStackPermutation(vector<int> &first, vector<int> &other){
	// Write your code here.
    if(first.size()==1)
        return true;
    int front = 0;
    stack <int> s;
    int n = first.size();
    s.push(first[0]);
    int i=1;
    while(i<n){
        if(!s.empty() and s.top()==other[front]){
            s.pop();
            front++;
            continue;
        }
        if(other[front]==first[i])
            front++;
        else
            s.push(first[i]);
        i++;
    }
    while(!s.empty() and front<n and s.top()==other[front]){
        front++;
        s.pop();
    }
    return front==n ? true : false;
}