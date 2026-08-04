class Solution {
public:
    int getparent(int i,vector<int>&parent){

        if(parent[i]==i) return i;

        return parent[i]=getparent(parent[i],parent);
    }

    void uni(int a,int b,vector<int>&parent){
        int pa=getparent(a,parent);
        int pb=getparent(b,parent);

        if(pa==pb) return ;

        parent[pb]=pa;

    }

    int kruskal(int skip,int force,vector<vector<int>>ed,int n,int N){

        vector<int> p(N,0);
        for(int i=0;i<N;i++){
            p[i]=i;
        }

        int wt=0;
        int count=0;

        if(force!=-1){
            int px=getparent(ed[force][1],p);
            int py=getparent(ed[force][2],p);

            if(px!=py) {

                uni(px,py,p);
                count++;
                wt+=ed[force][0];
            }
        }

        int i=0;

        while(i<n && count<N-1){

            if(i==skip){
                i++;
                continue;
            }

            int px=getparent(ed[i][1],p);
            int py=getparent(ed[i][2],p);

            if(px!=py){
                uni(px,py,p);
                wt+=ed[i][0];
                count++;
                
            }

            i++;


        }

        if(count!=N-1) return INT_MAX;

        return wt;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int N, vector<vector<int>>& edges) {

        int n=edges.size();

        vector<vector<int>>ed;

        for(int i=0;i<n;i++){

            vector<int> temp={edges[i][2],edges[i][0],edges[i][1],i};

            ed.push_back(temp);
            
        }

        sort(ed.begin(),ed.end());

        vector<int>parent(N,0);

        for(int i=0;i<N;i++){
            parent[i]=i;
        }

        int count=0;

        int cost=0;

        int i=0;

        while(count<N-1 && i<n){

            

            int px=getparent(ed[i][1],parent);
            int py=getparent(ed[i][2],parent);

            if(px!=py){
                uni(px,py,parent);
                cost+=ed[i][0];
                count++;
                
            }

            i++;
            
        }

        vector<int> c;
        vector<int> pc;

        for(int i=0;i<n;i++){

            vector<int> p(N,0);
            

            if(kruskal(i,-1,ed,n,N)>cost){
                c.push_back(ed[i][3]);
            }

            else if(kruskal(-1,i,ed,n,N)==cost){
                pc.push_back(ed[i][3]);
            }


        }

        vector<vector<int>>ans;

        ans.push_back(c);
        ans.push_back(pc);

        return ans;
        
    }
};