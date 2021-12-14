// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
	struct dll{
	    char data;
	    struct dll *next;
	    struct dll *prev;
	    dll(char x){
	        data = x;
	        next = NULL;
	        prev = NULL;
	    }
	};
	
	   void del(struct dll** head,
                struct dll** temp, struct dll** cur)
{
    
    if ((*head) == NULL)
        return;
 
    if ((*head) == (*cur)){
        (*head) = (*head)->next;
    }
    if (*temp == (*cur)){
        *temp = (*temp)->prev;
    }
    if ((*cur)->next != NULL)
        (*cur)->next->prev = (*cur)->prev;
    if ((*cur)->prev != NULL)
        (*cur)->prev->next = (*cur)->next;
    delete ((*cur));
}
	
		string FirstNonRepeating(string &A){
		    // Code here
		    string s="";
		    dll *head=NULL,*temp=NULL;
		    map <char,int> mp1;
		    map <char,dll*> mp2;
		    int n = A.length();
		    for(auto i=0;i<n;i++){
		        if(mp1[A[i]]==0){
		            mp1[A[i]]++;
		            dll *cur = new dll(A[i]);
		            mp2[A[i]] = cur;
		            if(head==NULL){
		                temp = cur;
		                head = cur;
		            }
		            else{
		                temp->next = cur;
		                cur->prev = temp;
		                temp = temp->next;
		            }
		        }
		        else if(mp1[A[i]]==1){
		            mp1[A[i]]++;
		            del(&head,&temp,&mp2[A[i]]);
		            mp2[A[i]] = NULL;
		        }
		        else{
		            mp1[A[i]]++;
		        }
		        if(head!=NULL)
		            s.push_back(head->data);
		        else
		            s.push_back('#');
		    }
		    return s;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends