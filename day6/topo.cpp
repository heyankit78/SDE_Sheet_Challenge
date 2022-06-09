#include<bits/stdc++.h>
#include<stack>
void topo(int node,vector<bool>&vis,stack<int>&st,vector<vector<int>>&adj){
    vis[node] = true;
    for(auto it : adj[node]){
        if(!vis[it])
            topo(it,vis,st,adj);
    }
    st.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<vector<int>>adj(v);
    for(int i=0;i<e;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }
    stack<int>st;
    vector<bool>vis(v,false);
    for(int i=0;i<v;i++){
        if(!vis[i]){
            topo(i,vis,st,adj);
        }
    }
    vector<int>ans;
    while(!st.empty()){
        auto it = st.top();
        st.pop();
        ans.push_back(it);
    }
//     reverse(ans.begin(),ans.end());
    return ans;
}
