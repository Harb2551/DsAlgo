// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
vector<int> find(int a[], int n , int x );

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


// } Driver Code Ends


int binary_first(int arr[],int n,int x){
    int l = 0,r=n-1,res = -1;
    while(l<=r){
        int mid = (l+r)/2;
        if(arr[mid]==x){
            res = mid;
            r=mid-1;
        }
        else if(arr[mid]>x)
            r = mid-1;
        else
            l = mid+1;
    }
    return res;
}

int binary_last(int arr[],int n,int x){
    int l = 0,r=n-1,res=-1;
    while(l<=r){
        int mid = (l+r)/2;
        if(arr[mid]==x){
            res = mid;
            l=mid+1;
        }
        else if(arr[mid]>x)
            r = mid-1;
        else
            l = mid+1;
    }
    return res;
}

vector<int> find(int arr[], int n , int x )
{
    // code here
    vector <int> v;
    int a,b;
    a = binary_first(arr,n,x);
    b = binary_last(arr,n,x);
    v.push_back(a);
    v.push_back(b);
    return v;
}







