vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    vector<pair<int,int>>adj[vertices];
    for(int i = 0;i<edges;i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,source});
    vector<int>dist(vertices,INT_MAX);
    dist[source] = 0;
    
    while(!pq.empty()){
        auto dis = pq.top().first;
        auto node = pq.top().second;
        pq.pop();
        for(auto it : adj[node]){
            auto child = it.first;
            auto wt = it.second;
            
            if(dist[child] > dist[node] + wt){
                dist[child] = dist[node] + wt;
                pq.push({dist[child],child});
            }
        }
    }
    return dist;
}
