// { Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

 // } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class Solution{
  public:
    //Function to merge K sorted linked list.
    
    Node *merge(Node *cur1,Node *cur2){
        Node *temp1=cur1,*temp2=cur2,*ans=NULL,*ans2=NULL;
        while(temp1!=NULL and temp2!=NULL){
            if(temp1->data<temp2->data){
                if(ans==NULL){
                    ans = temp1;
                    ans2 = temp1;
                }
                else{
                    ans->next = temp1;
                    ans = ans->next;
                }
                temp1 = temp1->next;
            }
            else{
                if(ans==NULL){
                    ans = temp2;
                    ans2 = temp2;
                }
                else{
                    ans->next = temp2;
                    ans = ans->next;
                }
                temp2 = temp2->next;
            }
        }
        while(temp1!=NULL){
            if(ans==NULL){
                ans = temp1;
                ans2=temp1;
            }
            ans->next = temp1;
            ans = ans->next;
            temp1 = temp1->next;
        }
        while(temp2!=NULL){
            if(ans==NULL){
                ans=temp2;
                ans2=temp2;
            }
            ans->next = temp2;
            ans = ans->next;
            temp2 = temp2->next;
        }
        return ans2;
    }
    
    Node * mergeKLists(Node *arr[], int K)
    {
           // Your code here
           for(auto i=0;i<K-1;i++){
               Node *temp = merge(arr[i],arr[i+1]);
               arr[i+1] = temp;
           }
           return arr[K-1];
    }
};



// { Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}
  // } Driver Code Ends