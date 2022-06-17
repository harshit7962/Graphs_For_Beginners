//Here we need to traverse a loosely connected graph using Deapth first Traversal
void dfsRec(vector<int> adj[], int i, vector<bool> &visited) {
    visited[i] = true;
    cout << i << " ";
    for(int x:adj[i]) {
        if(!visited[x])
            dfsRec(adj, x, visited);
    }
}

void dfsDis(vector<int> adj[], int v) {
    vector<bool> visited(v, false);
    
    for(int i=0;i<v;i++) {
        if(!visited[i]) dfsRec(adj, i, visited);
    }
}
