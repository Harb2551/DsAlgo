// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    
    Node* reverse(Node *head){
        if(head==NULL or head->next == NULL)
            return head;
        Node *temp;
        temp = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return temp;
    }
    
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
         head = reverse(head);
         Node *temp = head;
         while(temp!=NULL){
             if(temp->data<9){
                temp->data += 1;
                break;
             }
             temp->data = 0;
             if(temp->next==NULL){
                 Node *cur = new Node(1);
                 temp->next = cur;
                 break;
             }
             temp = temp->next;
         }
         return reverse(head);
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends