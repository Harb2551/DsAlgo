/****************************************************************

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

*****************************************************************/

Node *sortedDll(Node *head, int k)
{
    // Write your code here
    priority_queue <int,vector<int>,greater<int>> pq;
    Node *temp = head;
    for(auto i=0;i<k;i++){
        pq.push(temp->data);
        temp = temp->next;
    }
    Node *cur = head;
    while(cur!=temp){
        if(temp!=NULL){
            pq.push(temp->data);
            temp = temp->next;
        }
        cur->data = pq.top();
        pq.pop();
        cur = cur->next;
    }
    return head;
}






