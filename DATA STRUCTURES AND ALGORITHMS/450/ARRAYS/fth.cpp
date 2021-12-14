#include<bits/stdc++.h>
#define ll long long int 
using namespace std;

int findDuplicate(vector<int>& nums) {
   int t = nums[0];
   int h = nums[0];
   do{
       t = nums[t];
       h = nums[nums[h]];
   }
   while(t!=h);
   t = nums[0];
   while(t!=h){
   	  t = nums[t];
      h = nums[h];
   }
   return t;     
}

int main()
{
  int n;
  cin >> n;
  vector <int> v;
  for(auto i=0;i<n;i++){
  	int x;
  	cin >> x;
  	v.push_back(x);
  }
  cout << findDuplicate(v) << endl;;
  return 0;
}
