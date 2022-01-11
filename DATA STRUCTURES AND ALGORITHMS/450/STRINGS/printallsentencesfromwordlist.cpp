
void solve(vector<vector<string>> &arr,vector <vector<string>> &ans,int n,int i,vector <string> &temp){
    if(i==n){
        ans.push_back(temp);
        return;
    }
    int m = arr[i].size();
    for(auto j=0;j<m;j++){
        temp.push_back(arr[i][j]);
        solve(arr,ans,n,i+1,temp);
        temp.pop_back();
    }
}

void createSentences(vector <vector<string>> &arr, vector<vector<string>> &ans) {
    // Write your code here.
    int n = arr.size();
    vector <string> temp;
    solve(arr,ans,n,0,temp);
}