// { Driver Code Starts
//Initial template for C++

#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;  // https://www.geeksforgeeks.org/factorial-large-number-using-boost-multiprecision-library/
using namespace std;


 // } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find the nth catalan number.}
    cpp_int nCr(int n, int r){
       cpp_int res1=1,res2=1;
       if(r>n-r)
         r = n-r;
       for(auto i=0;i<r;i++){
           res1 *= n-i;
           res2 *= i+1;
       }
       return res1/res2;
    }
    
    cpp_int findCatalan(int n) 
    {
        //code here
        return (nCr(2*n,n))/(n+1);
    }
};

// { Driver Code Starts.

int main() 
{
    //taking count of testcases
	int t;
	cin>>t;
	while(t--) {
	    
	    //taking nth number
	    int n;
	    cin>>n;
	    Solution obj;
	    //calling function findCatalan function
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}  // } Driver Code Ends