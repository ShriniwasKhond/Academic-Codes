#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& adj, vector<bool>& visited, int node) {
    visited[node] = true;
    cout << node << " ";

    for (int next_node : adj[node]) {
        if (!visited[next_node]) {
            dfs(adj, visited, next_node);
        }
    }
}

int main() {
    int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<int>> adj(n); 
    vector<bool> visited(n, false); 

    cout << "Enter the edges: " << endl;
    for (int i = 1; i <= m; i++) {
        int u, v; 
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start_node;
    cout << "Enter the start node: ";
    cin >> start_node;

    cout << "DFS traversal starting from node " << start_node << ": ";
    dfs(adj, visited, start_node);
    cout << endl;

    return 0;
}
