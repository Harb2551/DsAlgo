// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* middleNode(Node* head) {
        if(head->next==NULL)
            return head;
        Node *slow=head,*fast=head->next;
        while(fast!=NULL and fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    Node* merge(Node* cur1,Node *cur2){
        Node *temp1=cur1,*temp2=cur2,*ans1=NULL,*ans2=NULL;
        while(temp1!=NULL and temp2!=NULL){
            Node* cur;
            if(temp1->data<temp2->data){
                cur = new Node(temp1->data);
                temp1 = temp1->next;
            }
            else{
                cur = new Node(temp2->data);
                temp2 = temp2->next;
            }
            if(ans1==NULL){
                ans1 = cur;
                ans2 = cur;
            }
            else{
                ans1->next = cur;
                ans1 = ans1->next;
            }
        }
        while(temp1!=NULL){
            Node *cur = new Node(temp1->data);
            ans1->next = cur;
            ans1 = ans1->next;
            temp1 = temp1->next;
        }
        while(temp2!=NULL){
            Node *cur = new Node(temp2->data);
            ans1->next = cur;
            ans1 = ans1->next;
            temp2 = temp2->next;
        }
        return ans2;
    }
    
    Node* mergeSort(Node* head) {
        // your code here
        if(head->next==NULL)
            return head;
        Node *mid = middleNode(head);
        Node *cur1 = head;
        Node *cur2 = mid->next;
        mid->next = NULL;
        cur1 = mergeSort(cur1);
        cur2 = mergeSort(cur2);
        head = merge(cur1,cur2);
        return head;
    }
};


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends