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
    int removeStones(vector<vector<int>>& stones) {
        int r = 0;
        int c = 0;
        int k = stones.size();
        
        for(auto it: stones){
            r = max(r,it[0]);
            c = max(c,it[1]);
        }
 
        disjointSet ds(r+c+2);
        unordered_map<int, int> stoneNodes;
        for(auto it: stones){
            int u = it[0];
            int v = it[1]+r+1;
            ds.unionByRank(u,v);
            stoneNodes[u] = 1;
            stoneNodes[v] = 1;
        }

        int cnt =0;
        for(auto it: stoneNodes){
            if (ds.findUParent(it.first) == it.first) {
                cnt++;
            }    
        }
        
        return k-cnt;

    }
};