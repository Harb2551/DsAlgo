
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++

class Solution {
public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
        //code here
        double p = 1, count0 = 0;
        vector <long long int> prod;
        for (auto i = 0; i < n; i++) {
            if (nums[i] == 0)
                count0++;
        }
        for (auto i = 0; i < n; i++) {
            if (nums[i] == 0)
                continue;
            p *= nums[i];
        }
        // cout << p << endl;
        for (auto i = 0; i < n; i++) {
            if (count0 == n) {
                prod.push_back(0);
                continue;
            }
            if (nums[i] == 0) {
                if (count0 == 1)
                    prod.push_back(p);
                else
                    prod.push_back(0);
            }
            else {
                if (count0 > 0)
                    prod.push_back(0);
                else
                    prod.push_back(p / nums[i]);
            }
        }
        return prod;
    }
};


// { Driver Code Starts.
int main()
{
    int t;  // number of test cases
    cin >> t;
    while (t--)
    {
        int n;  // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr, n);  // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}