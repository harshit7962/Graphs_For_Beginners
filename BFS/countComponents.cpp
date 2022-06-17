//Here similar to bfsDis, we instead of printing all the nodes, just need to find the number of loosely connected graphs...
//By loosely connected graphs, we mean that the two sets of graph have no link between them...

void bfs(vector<int> adj[], vector<bool> &visited, int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(int y:adj[x]) {
            if(!visited[y]) {visited[y]=true;q.push(y);}
        }
    }
}

int countComponents(vector<int> adj[], int v) {
    vector<bool> visited(v, false);
    int count=0;
    for(int i=0;i<v;i++) {
        if(!visited[i]) {
            count++;
            bfs(adj, visited, i);
        }
    }
    
    return count;
}
