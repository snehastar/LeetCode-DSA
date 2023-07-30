class disjointSet{
    public:
    vector<int> size;
    vector<int> parent;
    vector<int> rank;
    disjointSet(int n){
        size.resize(n+1,1);
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }

    int findUParent(int node){
        if(parent[node] == node)
            return node;
        //path compression
        return parent[node] = findUParent(parent[node]); //recursion
    }

    void unionBySize(int u, int v){
        int up_u = findUParent(u);
        int up_v = findUParent(v);
        if(up_u == up_v)
            return;
        if(size[up_u] < size[up_v]){
            parent[up_u] = up_v;
            size[up_v] += size[up_u];
        } 
        else{
            parent[up_v] = up_u;
            size[up_u] += size[up_v];
        }
    }

    void unionByRank(int u, int v){
        int up_u = findUParent(u);
        int up_v = findUParent(v);
        if(up_u == up_v)
            return;
        if(rank[up_u] < rank[up_v]){
            parent[up_u] = up_v;
        } 
        else{
            parent[up_v] = up_u;
        }  
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        disjointSet ds(n*n);
        int r[] = {-1,0,1,0};
        int c[] = {0,-1,0,1};

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0)
                    continue;
                for(int it=0; it<4; it++){
                    int row = i+r[it];
                    int col = j+c[it];
                    if(row>=0 && row<n && col>=0 && col<n && grid[row][col] == 1){
                        int nodeNo = i*n + j;
                        int adjnodeNo = row*n + col;
                        ds.unionBySize(nodeNo, adjnodeNo);
                    }
                }
            }
        }

        int mx = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1)
                    continue;
                set<int> components;
                for(int it=0; it<4; it++){
                    int row = i+r[it];
                    int col = j+c[it];
                    if(row>=0 && row<n && col>=0 && col<n && grid[row][col] == 1){
                        
                        components.insert(ds.findUParent(row*n + col));
                               
                    }
                }
                int sizeTotal = 0;
                for (auto it : components) {
                    sizeTotal += ds.size[it];
                }
                mx = max(mx, sizeTotal + 1);
            }
        }
        
        
        mx = max(mx, ds.size[ds.findUParent(n*n-1)]);

        return mx;   
    }
};
