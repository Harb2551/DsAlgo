// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



 // } Driver Code Ends
/*

The structure of linked list is the following

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
class Solution
{
    public:
    
    Node *reverse(Node *head){
        if(head==NULL or head->next==NULL)
            return head;
        Node *temp = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return temp;
    }
    
    Node *compute(Node *head)
    {
        // your code goes here
        if(head->next==NULL)
            return head;
        head = reverse(head);
        int m = head->data;
        Node *temp = head->next,*prev=head;
        while(temp!=NULL){
            if(temp->data>=m){
                m = temp->data;
                prev = temp;
            }
            else
                prev->next = temp->next;
            temp = temp->next;
        }
        return reverse(head);
    }
    
};
   


// { Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}
  // } Driver Code Ends