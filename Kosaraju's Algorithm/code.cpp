void dfs(vector<int> adj[], vector<bool> &visited, stack<int> &st, int src) {
    visited[src] = true;
    for(int y:adj[src]) {
        if(!visited[y])
            dfs(adj, visited, st, y);
    }
    
    st.push(src);
}

void printDfs(vector<int> adj[], vector<bool> &visited, int src) {
    visited[src] = true;
    cout << src << " ";
    for(int y:adj[src]) {
        if(!visited[y])
            printDfs(adj, visited, y);
    }
}
void printComponents(vector<int> adj[], int v) {
    vector<bool> visited(v, false);
    for(int i=0;i<v;i++) {
        if(!visited[i]) {
            cout << "Component: ";
            printDfs(adj, visited, i);
            cout << endl;
        }
    }
}

void kosaRaju(vector<int> adj[], int v) {
    stack<int> st;
    vector<bool> visited(v, false);
    
    for(int i=0;i<v;i++)
        if(!visited[i])
            dfs(adj, visited, st, i);
    
    vector<int> revadj[v];
    for(int i=0;i<v;i++) {
        for(int y: adj[i])
        revadj[y].push_back(i);
    }
    
    printComponents(revadj, v);
}
