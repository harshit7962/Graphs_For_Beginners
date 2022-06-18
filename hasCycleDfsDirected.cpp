//To check if a directed graph has any cycle using DFS traversal
bool checkForCycle(vector<int> adj[], vector<bool> &visited, vector<bool> &recst, int src) {
    visited[src] = true;
    recst[src] = true;
    
    for(int y:adc[src]) {
        if(!visited[y]) {
            if(checkForCycle(adj, visited, recst, y)) return true;
        } else if(recst[y]) return true;
    }
    
    recst[src]=false;
    return false;
}

bool hasCycle(vector<int> adj[], int v) {
    vector<bool> visited(v, false), recst(v, false);
    
    for(int i=0;i<v;i++){
        if(!visited[i]) {
            (checkForCycle(adj, visited, recst, i)) return  true;;
        }
    }
    
    return false;
}
