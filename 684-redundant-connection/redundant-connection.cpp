class Solution {
public:
    int getparent(int i,vector<int> & parent){

        if(parent[i]==i) return i;

        return parent[i]=getparent(parent[i],parent);
    }

    void uni(int a ,int b,vector<int> & parent,vector<int>& rank){

        int px=getparent(a,parent);
        int py=getparent(b,parent);

        if(px==py) return ;

        if(rank[px]>rank[py]){
            parent[py]=px;

        }

        else if(rank[py]>rank[px]){

            parent[px]=py;

        }

        else{
            parent[py]=px;
            rank[px]++;
        }

        return;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n=edges.size();

        vector<int>parent(n+1,0);
        vector<int> rank(n+1,0);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        for(auto it : edges){

            int a=it[0];
            int b=it[1];

            int pa=getparent(a,parent);
            int pb=getparent(b,parent);

            if(pa==pb){
                vector<int>temp={a,b};
                return temp;
            }

            else{
                uni(a,b,parent,rank);
            }
        }


        return {-1,-1};
        
    }
};