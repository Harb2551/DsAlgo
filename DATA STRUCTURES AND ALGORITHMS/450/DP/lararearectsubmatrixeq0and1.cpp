int max_area(vector <int> arr,int n,int b){
	int ans = 0;
    int sums[n];
    sums[0] = arr[0];
    for(auto i=1;i<n;i++)
        sums[i] = sums[i-1]+arr[i];
    for(auto i=0;i<n;i++){
        for(auto j=0;j<=i;j++){
            int temp = sums[i]-sums[j]+arr[j];
            if((i-j+1)*b>ans && (temp==((i-j+1)*b)/2.0))
                ans = (i-j+1)*b;
        }
    }
    return ans;
}

int maximumArea(vector<vector<int>>& mat, int n, int m)
{
    // Write your code here.
    int ans=0;
    for(auto i=0;i<n;i++){
        vector <int> x(m);
        for(auto j=i;j<n;j++){
            for(auto k=0;k<m;k++){
                x[k] += mat[j][k];
            }
            int temp = max_area(x,m,j-i+1);
            ans = max(ans,temp);
        }
    }
    return ans;
}
