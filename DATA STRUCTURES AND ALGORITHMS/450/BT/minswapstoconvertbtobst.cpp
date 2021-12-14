vector <int> in;

void inorder(vector<int> &arr,int i,int n){
	if(i>=n)
        return;
    inorder(arr,2*i+1,n);
    in.push_back(arr[i]);
    inorder(arr,2*i+2,n);
}

int minimumSwaps(vector<int>&arr, int n) {
	// Write your code here.
    in.clear();
    inorder(arr,0,n);
    vector <pair<int,int>> temp(n);
    for(auto i=0;i<n;i++){
        temp[i].first = in[i];
        temp[i].second = i;
    }
    sort(temp.begin(),temp.end());
    int s=0;
    for(auto i=0;i<n;i++){
        while(temp[i].second!=i){
            swap(temp[i],temp[temp[i].second]);
            s++;
        }
    }
    return s;
}


