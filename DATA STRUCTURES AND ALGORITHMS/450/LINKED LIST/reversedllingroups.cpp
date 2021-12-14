/*********************************************************

    Following is the class structure of the Node class:

    class Node
	{
	public:
	    int data;
	    Node *next;
	    Node *prev;
	    Node(int data)
	    {
	        this->data = data;
	        this->next = NULL;
	        this->prev = NULL;
	    }
	};

************************************************************/

Node *reverse(Node *head){
    if(head==NULL)
        return head;
    if(head->next==NULL){
        head->prev = NULL;
        return head;
    }
    Node *temp = reverse(head->next);
    head->next->next = head;
    head->prev = head->next;
    head->next = NULL;
    return temp;
}

Node* reverseDLLInGroups(Node* head, int k)
{	
    // Write your code here. 
    Node *temp = head;
    int count=0;
    while(count<k-1 and temp!=NULL){
        temp = temp->next;
        count++;
    }
    if(temp==NULL or temp->next==NULL){
        return reverse(head);
    }
    temp->next->prev = NULL;
    Node *ans = reverseDLLInGroups(temp->next,k);
    Node *last = head;
    temp->next = NULL;
    head = reverse(head);
    last->next = ans;
    ans->prev = last;
    return head;
}






