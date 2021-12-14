/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
                int data;
                Node *next;
                Node(int data)
                {
                        this->data = data;
                        this->next = NULL;
                }
        };

*****************************************************************/

Node* deleteNode(Node* head, int key) 
{
    // Write your code here.
    if(head==NULL)
        return head;
    if(head->next==head and head->data==key)
        return NULL;
    Node *temp=head,*last=head;
    while(last->next!=head)
        last = last->next;
    Node *prev=last;
    if(head->data==key){
        last->next = head->next;
        head = head->next;
        return head;
    }
    while(temp->next!=head){
        if(temp->data==key){
            prev->next = temp->next;
            return head;
        }
        prev = temp;
        temp = temp->next;
    }
    if(last->data==key){
        prev->next = head;
    }
    return head;
}










