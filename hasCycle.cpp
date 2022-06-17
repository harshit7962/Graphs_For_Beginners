// We need  to find if a given graph consists of cycles
bool dfs(vector<int> adj[], vector<bool> &visited, int start, int parent) {
    if(visited[start]==true) return true;
    visited[start] = true;
    for(int y:adj[start]) {
        if(y!=parent) {
            return dfs(adj, visited, y, start);
        }
    }
    return false;
}

bool hasCycle(vector<int> adj[], int v) {
    vector<bool> visited(v, false);
    return dfs(adj, visited, 0, 0);
}
