// { Driver Code Starts
//Initial Template for C++// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};



 // } Driver Code Ends
/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/

class Solution
{
    public:
    //Function to reverse a linked list.
        // recursive
    struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list 
        if(head==NULL or head->next==NULL)
            return head;
        struct Node* temp;
        temp = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return temp;
    }

    struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list 
        if(head==NULL or head->next==NULL)
            return head;
        if(head->next->next==NULL){
            struct Node *temp = head->next;
            temp->next = head;
            head->next = NULL;
            head = temp;
            return head;
        }
        struct Node *cur,*prev,*former;
        cur = head->next->next;
        prev = head->next;
        former = head;
        former->next = NULL;
        while(prev!=NULL){
            prev->next = former;
            former = prev;
            prev = cur;
            if(cur)
                cur = cur->next;
        }
        head = former;
        return head;
    }
    
};
    


// { Driver Code Starts.

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
       printf("%d ", temp->data);
       temp  = temp->next;
    }
}

/* Driver program to test above function*/
int main()
{
    int T,n,l,firstdata;
    cin>>T;

    while(T--)
    {
        struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        
        for (int i=1; i<n; i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        
        Solution ob;
        head = ob. reverseList(head);
        
        printList(head);
        cout << endl;
    }
    return 0;
}

  // } Driver Code Ends