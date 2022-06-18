void topologicalSort(vector<int> adj[], int v) {
    vector<int> inDegree(v, 0);
    
    for(int i=0;i<v;i++) {
        for(int x:adj[i]) inDegree[x]++;
    }
    
    queue<int> q;
    for(int i=0;i<v;i++) if(inDegree[i]==0) q.push(i);
    
    while(!q.empty()) {
        int x = q.front();
        cout << x << " ";
        q.pop();
        for(int y:adj[x]) {
            if(inDegree[y]==1) q.push(y);
            else inDegree[y]--;
        }
    }
}
