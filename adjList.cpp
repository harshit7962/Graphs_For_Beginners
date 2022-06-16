//Here we are creating a graph using an adjacency list representation...
//We are using vectors to act as list here

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

/**
To add an edge we use the following command
addEdge(0,1)

It will add 1 in the adjacency list of 0 and 0 to the adjacency list of 1
*/
