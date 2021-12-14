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
        cout << node->data <<" "; 
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
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        Node *odd=NULL,*even=NULL,*temp=head;
        Node *ans1=NULL,*ans2=NULL;
        while(temp!=NULL){
            if(temp->data&1){
                if(odd==NULL){
                    odd=temp;
                    ans2=temp;
                }
                else{
                    odd->next = temp;
                    odd = odd->next;
                }
            }
            else{
                if(even==NULL){
                    even = temp;
                    ans1 = temp;
                }
                else{
                    even->next = temp;
                    even = even->next;
                }
            }
            temp = temp->next;
        }
        if(even)
            even->next = ans2;
        if(odd)
            odd->next = NULL;
        return ans1==NULL ? ans2 : ans1;
    }
};

// { Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}
  // } Driver Code Ends