//Here we need to count number of loosely connected components in our graph
void dfsRec(vector<int> adj[], int i, vector<bool> &visited) {
    visited[i] = true;
    for(int x:adj[i]) {
        if(!visited[x])
            dfsRec(adj, x, visited);
    }
}

int countComponents(vector<int> adj[], int v) {
    int count=0;
    vector<bool> visited(v, false);
    
    for(int i=0;i<v;i++) {
        if(!visited[i]) {dfsRec(adj, i, visited);count++;}
    }
    
    return count;
}
