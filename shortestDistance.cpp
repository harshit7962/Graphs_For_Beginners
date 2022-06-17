//Given a graph, we need to print the distance of all the nodes from given source...

void shortestDistance(vector<int> adj[], int v, int start) {
    //To keep track of visited array
    vector<bool> visited(v, false);
    
    //To keep track of distance of each vertex from source vertex
    vector<int> distance(v, INT_MAX);
    
    //To store vertex using breadth-first manner
    queue<int> q;
    
    //Start Node is already visited and also distance of start from start is  0
    q.push(start);
    visited[start] = true;
    distance[start] = 0;
    
    
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int y:adj[x]) {
            if(!visited[y]) {
                q.push(y);
                visited[y]=true;
                /**
                    Distance of a particular vertex from start is given by-
                    (distance of vertex from its previous un-visited vertex)+1
                    This is because in breadth-first search, we visit vertex in shortest path manner itself.
                    Hence even if another path exist between the start and current vertex,
                    the shortest one would be from the vertex which visits it first...
                */
                distance[y] = distance[x]+1;
            }
        }
    }
    
    for(int i:distance) cout << i << " ";
}
