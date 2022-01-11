int find_sum(stack <int> s){
    int ans = 0;
    while(!s.empty()){
        ans += s.top();
        s.pop();
    }
    return ans;
}

int maxSum(stack<int> &stk1, stack<int> &stk2, stack<int> &stk3) {
    // Write your code here
    int sum1 = find_sum(stk1);
    int sum2 = find_sum(stk2);
    int sum3 = find_sum(stk3);
    while(sum1!= sum2 or sum2!=sum3){
        int temp = max(sum1,max(sum2,sum3));
        if(temp==sum1){
            sum1 -= stk1.top();
            stk1.pop();
        }
        if(temp==sum2){
            sum2 -= stk2.top();
            stk2.pop();
        }
        if(temp==sum3){
            sum3 -= stk3.top();
            stk3.pop();
        }
    }
    return sum1;
}