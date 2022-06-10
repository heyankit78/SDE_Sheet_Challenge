bool dfs(int node,int c,vector<int>&col,vector<vector<int>>&adj){
    col[node] = c;
    for(auto it : adj[node]){
        if(col[it] == -1){
            if(!dfs(it,3-c,col,adj))
                return false;
        }
        else if(col[it] == col[node])
            return false;
    }
    return true;
}
bool isGraphBirpatite(vector<vector<int>> &edges) {
	// Write your code here.
    int n = edges.size();
    vector<vector<int>>adj(n);
    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            if(edges[i][j]){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    vector<int>col(n,-1);
    for(int i=0;i<n;i++){
        if(col[i] == -1 ){
            if(dfs(i,1,col,adj) == false)return false;
        }
    }
    return true;
}
