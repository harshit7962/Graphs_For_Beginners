//Detection of cycle in a directed graph using BFS traversal...

/**
Here we also use Kahn's algorithm and count the number of traversed vertex.
Since, Kahn's algorithm works only for acyclic graphs, we know that we wont be able to traverse through all the vertex, if the graph has cycle...
Hence we return if count is equal to number of vertex as our identifier...
*/

bool hasCycles(vector<int> adj[], int v) {
    int count=0;
    vector<int> inDegree(v,0);
    
    for(int i=0;i<v;i++) {
        for(int y:adj[i]) inDegree[y]++;
    }
    
    queue<int> q;
    for(int i=0;i<v;i++) if(inDegree[i]==0) q.push(i);
    
    while(!q.empty()) {
        count++;
        int x= q.top();
        x.pop();
        for(int y: adj[x]) {
            if(inDegree[y]==1) q.push(y);
            else inDegree[y]--;
        }
    }
    
    return (count!=v);
}
