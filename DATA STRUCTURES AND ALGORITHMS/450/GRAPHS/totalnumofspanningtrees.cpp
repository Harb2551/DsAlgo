int determinant(vector <vector<int>> &mat){
    int n = mat.size();
    int det = 0;
    if(n==1)
        return mat[0][0];
    else if(n==2)
        return mat[0][0]*mat[1][1]-mat[1][0]*mat[0][1];
    else{      
        for(auto i=0;i<n;i++){
            vector <vector<int>> temp;
            for(auto j=1;j<n;j++){
                vector <int> v;
                for(auto k=0;k<n;k++){
                    if(k!=i)
                        v.push_back(mat[j][k]);
                }
                if(v.size()>0)
                    temp.push_back(v);
            }
            int mul = (i&1) ? -1 : 1;
            det += mul*mat[0][i]*determinant(temp);
        }
    }
    return det;
}

int spanningTrees(vector<vector<int>> &adjMatrix, int n, int m)
{
    // Write your code here
    int deg[n] = {0};
    for(auto i=0;i<n;i++){
        for(auto j=0;j<n;j++){
            if(adjMatrix[i][j]==1)
                deg[i]++;
        }
    }
    for(auto i=0;i<n;i++){
        for(auto j=0;j<n;j++){
            if(i==j)
                adjMatrix[i][j] = deg[i];
            else{
                if(adjMatrix[i][j])
                    adjMatrix[i][j] = -1;
            }
        }
    }
    vector <vector<int>> temp(n-1,vector <int> (n-1));
    for(auto i=1;i<n;i++)
        for(auto j=1;j<n;j++)
           temp[i-1][j-1] = adjMatrix[i][j];          
    
    return determinant(temp);
}