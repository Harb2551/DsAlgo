// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    map <char,int> visited;
    vector <char> postorder;
    int post;
    
    void dfs(map <char,vector<char>> graph,char v){
        visited[v] = 1;
        int n = graph[v].size();
        for(auto i=0;i<n;i++){
            if(!visited[graph[v][i]]){
                dfs(graph,graph[v][i]);
            }
        }
        postorder.push_back(v);
    }
    
    string findOrder(string dict[], int N, int K) {
        //code here
        map <char,vector <char>> graph;
        post=1;
        for(auto i=0;i<N-1;i++){
            int j=0,k=0;
            int n = dict[i].length();
            int m = dict[i+1].length();
            while(j<n and k<m and dict[i][j]==dict[i+1][k]){
                j++;
                k++;
            }
            if(j!=n and k!=m){
                graph[dict[i][j]].push_back(dict[i+1][k]);
            }
        }
        for(auto i='a';i<'a'+K;i++){
            if(!visited[i]){
                dfs(graph,i);
            }
        }
        reverse(postorder.begin(),postorder.end());
        string s;
        for(auto i=0;i<postorder.size();i++)
            s.push_back(postorder[i]);
        return s;
    }
};

// { Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends