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
    Node * mergeKLists(Node *arr[], int K)
    {
           // Your code here
           unordered_map <int,Node*> mp;
           for(int i=0;i<K;i++){
               mp[i] = arr[i];
           }
           priority_queue <pair<int,int>,vector <pair<int,int>>,greater <pair<int,int>>> pq;
          for(int i=0;i<K;i++)
              pq.push({arr[i]->data,i});
           Node *head = NULL,*temp=head;
          while(!pq.empty()){
              pair<int,int> cur = pq.top();
              pq.pop();
              Node *root = new Node(cur.first);
              if(temp==NULL){
                  temp = root;
                  head = root;
              }
              else{
                    temp->next = root;
                    temp = root;
              }
              if(mp[cur.second]->next!=NULL){
                    pq.push({mp[cur.second]->next->data,cur.second});
                    mp[cur.second] = mp[cur.second]->next; 
              }
          }
           return head;
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