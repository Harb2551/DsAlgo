// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution {
public:
    vector<int> factorial(int N){
        // code here
       vector <vector<int>> v;
       v.push_back({1});
       v.push_back({1});
      for(auto i=2;i<=N;i++){
          v.push_back(multiply(v[i-1],i));
      }
       return v[N];
    }
    
    vector <int> multiply(vector <int> a,int num){
        vector <int> c;
        int car=0;
        int i=a.size()-1;
        // cout << "i=" << i << endl;
        while(i>=0){
            int temp = a[i--]*num + car;
            if(i==-1){
                while(temp!=0){
                    c.push_back(temp%10);
                    temp /= 10;
                }
            }
            else if(temp<=9){
                c.push_back(temp);
                car = 0;
            }
            else{
                c.push_back(temp%10);
                temp /= 10;
                car = temp;
            }
        }
        reverse(c.begin(),c.end());
        return c;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends