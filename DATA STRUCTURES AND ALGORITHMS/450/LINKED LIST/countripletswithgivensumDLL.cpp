/***********************************************

    Following is the class structure of the Node class:

    class DLLNode
    {
        public:
        int data;
        DLLNode *next;
        DLLNode *prev;
    };

***********************************************/

int countTriplets(DLLNode* head, int x)
{
    // WRITE YOUR CODE HERE
    if(head==NULL)
        return 0;
    int count = 0;
    DLLNode *last = head,*temp = head;
    while(last->next!=NULL)
        last = last->next;
    while(temp->next!=NULL){
        int sum = x-temp->data;
        DLLNode *cur1 = temp->next,*cur2=last;
        while(cur1!=cur2 and cur1->prev!=cur2){
            if(cur1->data + cur2->data == sum){
                count++;
                cur1 = cur1->next;
                cur2 = cur2->prev;
            }
            else if(cur1->data + cur2->data > sum)
                cur2 = cur2->prev;
            else
                cur1 = cur1->next;
        }
        temp = temp->next;
    }
    return 0;
}  













