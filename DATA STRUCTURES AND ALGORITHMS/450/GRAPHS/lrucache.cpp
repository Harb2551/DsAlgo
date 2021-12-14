// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
    private:

    public:
    //Constructor for initializing the cache capacity with the given value.
    struct node{
        int key;
        int val;
        struct node *next;
        struct node *prev;
        node(int k,int v){
            key = k;
            val = v;
            next = NULL;
            prev = NULL;
        }
    };
    
    int c,c1;
    map <int,node*> mp;
    node *head;
    node *tail;
    
    LRUCache(int cap)
    {
        // code here
        c = cap;
        c1 = 0;
        head = new node(0,0);
        tail = new node(0,0);
        head->next = tail;
        tail->prev = head;
    }
    
    //Function to return value corresponding to the key.
    int get(int key)
    {
        // your code here
        if(!mp[key])
            return -1;
        node *temp = mp[key];
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        temp->next = head->next;
        head->next->prev = temp;
        head->next = temp;
        temp->prev = head;
        return temp->val;
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        // your code here   
        node *temp;
        if(!mp[key]){
            if(c1==c){
                mp[tail->prev->key] = NULL;
                node *cur = tail->prev;
                cur->prev->next = tail;
                tail->prev = cur->prev;
                delete cur;
                c1--;
            }
            temp = new node(key,value);
            mp[key] = temp;
            c1++;
        }
        else{
           temp = mp[key]; 
           temp->val = value;
           temp->next->prev = temp->prev;
           temp->prev->next = temp->next;
        }
        temp->next = head->next;
        head->next->prev = temp;
        head->next = temp;
        temp->prev = head;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends