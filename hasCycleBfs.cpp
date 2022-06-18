//BFS approach  to detect if the graph contains any cycle
bool checkCycle(vector<int> adj[], vector<bool> &vis, int src) {
    queue<pair<int, int>> q;
    q.push({src,-1});
    vis[src]=true;
    while(!q.empty()) {
        int x = q.front().first;
        int par = q.front().second;
        q.pop();
        for(int y:adj[x]) {
            if(!vis[y]) {
                q.push({y,x});
                vis[y] = true;
            } else if(y!=par) return true;
        }
    }
    
    return false;
}

bool hasCycle(vector<int> adj[], int v) {
    vector<bool> vis(v, false);
    for(int i=0;i<v;i++) {
        if(!vis[i]) {
            if(checkCycle(adj, vis, i)) return true;
        }
    }
    
    return false;
}
