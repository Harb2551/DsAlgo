// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      map <int,int> mp;
      int ans=INT_MIN;
      for(auto i=0;i<N;i++){
          mp[arr[i]] = 1;
      }
      for(auto i=mp.begin();i!=mp.end();i++){
          if(mp[i->first - 1]!=1){
              int temp=0,j=i->first;
              while(mp[j]==1){
                  temp++;
                  j++;
              }
              if(temp>ans)
                ans = temp;
          }
      }
      return ans;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends