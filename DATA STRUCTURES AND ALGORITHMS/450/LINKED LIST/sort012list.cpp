// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


 // } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        if(head==NULL or head->next==NULL)
            return head;
        Node *first=NULL,*second=NULL,*third=NULL,*ans1=NULL,*ans2=NULL,*cur=head;
        while(cur!=NULL){
            if(cur->data==0){
                if(first==NULL){
                    first = cur;
                    head = cur;
                }
                else{
                    first->next = cur;
                    first = first->next;
                }
            }
            else if(cur->data==2){
                if(third==NULL){
                    third = cur;
                    ans2 = cur;
                }
                else{
                    third->next = cur;
                    third = third->next;
                }
            }
            else{
                if(second==NULL){
                    second = cur;
                    ans1 = cur;
                }
                else{
                    second->next = cur;
                    second = second->next;
                }
            }
            cur = cur->next;
        }
        if(first)
            first->next = ans1;
        else
            head = second;
        if(second)
            second->next = ans2;
        else if(!first)
            head = third;
        else
            first->next = ans2;
        if(third)
            third->next = NULL;
        return head;
    }
};


// { Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}  // } Driver Code Ends