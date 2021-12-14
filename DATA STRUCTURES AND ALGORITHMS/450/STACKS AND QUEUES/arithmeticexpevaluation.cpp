#include <bits/stdc++.h>
using namespace std;

int pre(char x){
    switch(x){
        case '+': return 1;
        case '-': return 1;
        case '*': return 2;
        case '/': return 2;
        case '(': return 3;	  
    }
}

int calc(int a,char op,int b){
    switch(op){
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;
    }
}

int change(string x){
    int n = x.length();
    int ans=0;
    for(auto i=0;i<n;i++){
        ans = (x[i]-48) + ans*10;
    }
    return ans;
}

void popping(stack <char> &op,stack <int> &num){
    char temp = op.top();
    op.pop();
    int a = num.top();
    num.pop();
    int b = num.top();
    num.pop();
    int ans = calc(b,temp,a);
    num.push(ans);
}

int evaluateArithmeticExpression(string &expression) 
{
	// Write your code here
    int n = expression.length();
    stack <char> op;
    stack <int> num;
    for(auto i=0;i<n;i++){
        if(expression[i]==')'){
            while(op.top()!='('){                
                if(num.size()>1){
                    popping(op,num);
            	}            
           	} 
            op.pop();
        }
        else if(expression[i]>='0' and expression[i]<='9'){
            string x;
            while(expression[i]>='0' and expression[i]<='9'){
                x.push_back(expression[i]);
				i++;
            }
            i--;
            int ans = change(x);
            num.push(ans);
        }
        else{
              	while(!op.empty() and op.top()!='(' and pre(expression[i])<=pre(op.top())){
                    popping(op,num);                    
                }
            	op.push(expression[i]);
        }
    }   
    return num.top();
}