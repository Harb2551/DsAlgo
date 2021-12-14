// { Driver Code Starts
#include<iostream>
#include<stack>
using namespace std;
void push(stack<int>& s,int a);
bool isFull(stack<int>& s,int n);
bool isEmpty(stack<int>& s);
int pop(stack<int>& s);
int getMin(stack<int>& s);
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty(s)){
		    pop(s);
		}
		while(!isFull(s,n)){
			cin>>a;
			push(s,a);
		}
		cout<<getMin(s)<<endl;
	}
}// } Driver Code Ends


void push(stack<int>& s, int a){
	// Your code goes here
	s.push(a);
}

bool isFull(stack<int>& s,int n){
	// Your code goes here
	if(s.size()==n)
	    return true;
	return false;
}

bool isEmpty(stack<int>& s){
	// Your code goes here
	if(s.empty())
	    return true;
	return false;
}

int pop(stack<int>& s){
	// Your code goes here
	if(s.empty())
	    return -1;
	int temp = s.top();
	s.pop();
	return temp;
}

int getMin(stack<int>& s){
	// Your code goes here
	stack <int> s1 = s;
	int v[s1.size()];
	for(auto i=0;i<s.size();i++){
	    v[i] = s1.top();
	    s1.pop();
	}
	int m=1000000007;
	for(auto i=0;i<s.size();i++){
	    if(v[i]<m)
	        m = v[i];
	}
	return m;
}