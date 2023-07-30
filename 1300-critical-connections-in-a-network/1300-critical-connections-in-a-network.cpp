class Solution {
private:
    int timer = 1;
    void dfs(int node, int parent, vector<int> adj[],int time[],int low[],vector<int> &vis,vector<vector<int>> &bridges){
        vis[node] = 1;
        time[node] = low[node] = timer;
        timer++;
        for(auto it: adj[node]){
            if(it == parent)
                continue;
            if(vis[it] == 0){
                dfs(it, node,adj,time,low,vis,bridges);
                if(low[it]> time[node]){
                    bridges.push_back({it, node});
                }
            }
            low[node] = min(low[it], low[node]);    
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto it: connections){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }    

        vector<int> vis(n,0);
        int low[n];
        int time[n];
        vector<vector<int>> bridges;

        dfs(0,-1,adj,time,low,vis,bridges);

        return bridges;
    }
};