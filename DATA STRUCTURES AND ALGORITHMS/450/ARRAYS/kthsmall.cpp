// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

int size =0;

void swap(int *a,int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

int left_child(int i){
   return (2*i+1);
}

int right_child(int i){
   return (2*i+2);
}

int parent(int i){
   return (i-1)/2;
}

void shift_down(int q[],int i){
   int min_index = i;
   if ((left_child(i)<size) && (q[min_index] >q[left_child(i)])){
      min_index = left_child(i);
   }
   if ((right_child(i) < size) && (q[min_index]> q[right_child(i)])){
      min_index = right_child(i);
   }
   if (min_index != i){
      swap(&q[min_index],&q[i]);
      shift_down(q,min_index);
   }
}

int extract_min(int q[]){
   int temp = q[0];
   swap(&q[0],&q[size-1]);
   size--;
   shift_down(q,0);
   return temp;
}

void shift_up(int q[],int i){
   if(i>0 && q[i] < q[parent(i)]){
      swap(&q[i],&q[parent(i)]);
      i = parent(i);
      shift_up(q,i);
   }
}

void build_heap(int heap[]){
	int i;
	for(i=(size/2)-1;i>=0;i--){
       shift_down(heap,i);
	}
}

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k){
        //code here
        size = r+1;
        build_heap(arr);
        for(int i=0;i<k-1;i++){
            int x = extract_min(arr);
        }
        return extract_min(arr);
    }
};


// { Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}  // } Driver Code Ends