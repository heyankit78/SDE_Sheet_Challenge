#include<bits/stdc++.h>
bool dfs(int node,int c,vector<int>&color,vector<vector<int>>&adj){
   queue<int>q;
    q.push(node); 
    color[node] = c; 
    while(!q.empty()) {
        int node = q.front(); 
        q.pop();
        
        for(auto it : adj[node]) {
            if(color[it] == -1) {
                color[it] = 3 - color[node]; 
                q.push(it); 
            } else if(color[it] == color[node]) {
                return false; 
            }
        }
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
