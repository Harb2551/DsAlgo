// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* reverse(struct Node* head){
        if(head==NULL or head->next==NULL)
            return head;
        struct Node *temp;
        temp = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return temp;
    }
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        first = reverse(first);
        second = reverse(second);
        struct Node *temp1 = first,*temp2 = second;
        struct Node* ans=NULL,*ans2=NULL;
        int car=0;
        while(temp1!=NULL and temp2!=NULL){
            if(temp1->data+temp2->data+car>9){
                struct Node *cur = new Node((temp1->data+temp2->data+car)%10);
                if(ans==NULL){
                    ans = cur;
                    ans2=cur;
                }
                else{
                    ans->next = cur;
                    ans = ans->next;
                }
                car = (temp1->data+temp2->data+car)/10;
            }
            else{
                struct Node *cur = new Node(temp1->data+temp2->data+car);
                if(ans==NULL){
                    ans = cur;
                    ans2=cur;
                }
                else{
                    ans->next = cur;
                    ans = ans->next;
                }
                car=0;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        while(temp1!=NULL){
            struct Node *cur;
            if(temp1->data+car>9){
                cur = new Node((temp1->data+car)%10);
                car = (temp1->data+car)/10;
            }
            else{
                cur = new Node(temp1->data+car);
                car = 0;
            }
            if(ans==NULL){
                ans=cur;
                ans2=cur;
            }
            else{
                ans->next = cur;
                ans = ans->next;
            }
            temp1 = temp1->next;
        }
        while(temp2!=NULL){
            struct Node *cur;
            if(temp2->data+car>9){
                cur = new Node((temp2->data+car)%10);
                car = (temp2->data+car)/10;
            }
            else{
                cur = new Node(temp2->data+car);
                car = 0;
            }
            if(ans==NULL){
                ans=cur;
                ans2=cur;
            }
            else{
                ans->next = cur;
                ans = ans->next;
            }
            temp2 = temp2->next;
        }
        if(car){
            struct Node *cur = new Node(car);
            ans->next = cur;
        }
        return reverse(ans2);
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends