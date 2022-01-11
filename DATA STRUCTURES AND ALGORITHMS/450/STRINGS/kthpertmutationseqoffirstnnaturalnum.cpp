int find_first(int n,int &k){
    if(n==1)
        return 0;
    n--;
    int temp = n;
    while(k>=temp and n>1){
        temp *= (n-1);
        n--;
    }
    int a = k/temp;
    k = k%temp;
    return a;
}

vector<int>  kthPermutation(int n, int k)
{
    vector <int> v,w;
    for(auto i=1;i<=n;i++)
        v.push_back(i);
    k--;
    for(auto i=0;i<n;i++){
        int index = find_first(n-i,k);
        w.push_back(v[index]);
        v.erase(v.begin()+index);
    }
    return w;
}


