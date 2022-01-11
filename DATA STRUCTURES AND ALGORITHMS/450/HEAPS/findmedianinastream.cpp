// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    //Function to insert heap.
    
    priority_queue <int,vector<int>> pq_max;
    priority_queue <int,vector<int>,greater<int>> pq_min;
    
    void insertHeap(int &x)
    {
        int size1 = pq_max.size();
        int size2 = pq_min.size();
        if(size1>size2){
           if(x>pq_max.top())
                pq_min.push(x);
           else{
               int temp = pq_max.top();
               pq_max.pop();
               pq_min.push(temp);
               pq_max.push(x);
           }
        }
        else{
            if(size1==0)
                pq_max.push(x);
            else{
                if(x>pq_min.top()){
                    int temp = pq_min.top();
                    pq_min.pop();
                    pq_max.push(temp);
                    pq_min.push(x);
                }
                else
                    pq_max.push(x);
            }
        }
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
    }
    
    //Function to return Median.
    double getMedian()
    {
        int size1 = pq_max.size();
        int size2 = pq_min.size();
        if(size1>size2) {
            // cout << pq_max.top() << "  ";
            return pq_max.top();
        }
        else if(size1<size2)
            return pq_min.top();
        else
            return (pq_max.top()+pq_min.top())/2.0;
    }
};


// { Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}  // } Driver Code Ends