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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {    
        int n = accounts.size();
        unordered_map<string, int> mail;
        disjointSet ds(n);

        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                if(mail.find(accounts[i][j]) != mail.end()){
                    ds.unionByRank(i, mail[accounts[i][j]]);    
                }else{
                    mail[accounts[i][j]] = i;    
                }
            }
        } 

        vector<string> merge[n];
        for(auto it: mail){
            string acc = it.first;
            int node = ds.findUParent(it.second);
            merge[node].push_back(acc);
        } 

        vector<vector<string>> ans;   
        for(int i=0; i<n; i++){
            if(merge[i].size() == 0)
                continue;
            sort(merge[i].begin(),merge[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it: merge[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }       
        
        return ans;
    }
};