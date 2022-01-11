// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


 // } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class Solution{
    public:
    
    struct compare{
        bool operator()(const pair <int,int> &a,const pair <int,int> &b){
            return a.first>b.first;
        }
    };
    
    pair<int,int> findSmallestRange(int KSortedArray[][N], int &n, int &k)
    {
          //code here
          unordered_map <int,int> mp;
          for(auto i=0;i<k;i++)
              mp[i] = 0;
          priority_queue <pair<int,int>,vector <pair<int,int>>,compare> pq;
          int mi=INT_MAX,ma=INT_MIN,low,high,range=INT_MAX;
          for(auto i=0;i<k;i++){
              pq.push({KSortedArray[i][0],i});
              mi = min(mi,KSortedArray[i][0]);
              ma = max(ma,KSortedArray[i][0]);
          }
          range = ma-mi;
          low = mi;
          high = ma;
          while(!pq.empty()){
              auto cur = pq.top();
              pq.pop();
              if(mp[cur.second]+1<n){
                  mp[cur.second]++;
                  pq.push({KSortedArray[cur.second][mp[cur.second]],cur.second});
              }
              else
                  break;
              ma = max(ma,KSortedArray[cur.second][mp[cur.second]]);
              mi = pq.top().first;
              if(range>ma-mi){
                  range = ma-mi;
                  low = mi;
                  high = ma;
              }
          }
          return {low,high};
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}

  // } Driver Code Ends