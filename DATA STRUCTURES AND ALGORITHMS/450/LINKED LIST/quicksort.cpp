// { Driver Code Starts
#include <iostream>
#include <cstdio>
using namespace std;
 
/* a node of the singly linked list */
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
};

/* A utility function to insert a node at the beginning of linked list */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node = new node(new_data);
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* A utility function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
void quickSort(struct node **headRef);
int main()
{
	int t,n,x;
	cin>>t;
	while(t--){
		
        
        cin>>n;n=n-1;
		cin>>x;
        node *temp,*head = new node(x);
        temp=head;
        while(n--)
        {
			cin>>x;
          temp->next=new node(x);
          temp=temp->next;
			}
    
    quickSort(&head);
 
    printList(head);
 while(head!= NULL){
     temp=head;
     head=head->next;
     free(temp);
     
 }
	}
    return 0;
}// } Driver Code Ends


 
/* a node of the singly linked list 
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
}; */

//you have to complete this function

int length(struct node *head){
    struct node *temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

struct node* last(struct node *head){
    if(head==NULL)
        return head;
    struct node *temp=head;
    while(temp->next!=NULL)
        temp = temp->next;
    return temp;
}

struct node* sort(struct node *head){
    if(head==NULL or head->next==NULL)
        return head;
    int len = length(head);
    int pivotindex = rand()%len;
    struct node *pivot=head;
    while(pivotindex--)
        pivot = pivot->next;
    struct node *cur=head,*small=NULL,*large=NULL,*sh=NULL,*lh=NULL,*left,*right;
    while(cur!=NULL){
        if(cur!=pivot){
            if(cur->data<pivot->data){
                if(small==NULL){
                    small = cur;
                    sh = cur;
                }
                else{
                    small->next = cur;
                    small = small->next;
                }
            }
            else{
                if(large==NULL){
                    large = cur;
                    lh = cur;
                }
                else{
                    large->next = cur;
                    large = large->next;
                }
            }
        }
        cur = cur->next;
    }
    if(small)
        small->next = NULL;
    if(large)
        large->next = NULL;
    left = sort(sh);
    right = sort(lh);
    pivot->next = right;
    struct node *ll = last(left);
    if(left)
        ll->next = pivot;
    return left==NULL ? pivot : left;
}

void quickSort(struct node **headRef) {
    *headRef = sort(*headRef);
}














