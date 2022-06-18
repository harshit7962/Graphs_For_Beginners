//DFS approach to detect if the graph contains any cycle

bool checkForCycle(vector<int> adj[], vector<bool> &visited, int src, int parent) {
    vis[src] = true;
    for(int y:adj[src]) {
        if(!vis[y]) {
            if(checkForCycle(adj, vis, y, src)) return true;
        } else if(y!=parent) return true;
    }
    
    return false;
}

bool hasCycle(vector<int> adj[], int v) {
    vector<bool> vis(v, false);
    for(int i=0;i<v;i++){
        if(!vis[v]) if(checkForCycle(adj, vis, i, -1)) return true;
    }
    
    return false;
}
