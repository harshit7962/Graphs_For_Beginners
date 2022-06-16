//Given an undirected, but loosely connected graph, we need to find all the nodes using BFS in any order...

//The idea here is to call normal BFS function, but this time we keep track of already visited nodes, using an array which is passed in as the parameter...
//If the node is not already visited, then we call  the BFS of that node...

//Time complexity here is O(V+E) where V is the number of vertices and E is the number of edges in our graph...
void bfs(vector<int> adj[], vector<bool> &visited, int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        cout << x << " ";
        for(int y:adj[x]) {
            if(!visited[y]) {visited[y]=true;q.push(y);}
        }
    }
}


void bfsDis(vector<int> adj[], int v) {
    vector<bool> visited(v, false);
    for(int i=0;i<v;i++) {
        if(!visited[i]) bfs(adj, visited, i);
    }
} 
