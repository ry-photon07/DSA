class Solution {
public:
    typedef pair<int,pair<int,int>> ppp;
    int minCost(vector<vector<int>>& grid) {

        int n=grid.size();

        int m=grid[0].size();


        //vector<pair<int,int>> vis(n,vector<int>(n,0));
        
        vector<vector<int>> dis(n,vector<int>(m,INT_MAX));

        dis[0][0]=0;

        priority_queue<ppp,vector<ppp>,greater<ppp>> pq;

        pq.push({0,{0,0}});

        int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

        while(!pq.empty()){

            ppp f=pq.top();
            pq.pop();

            int x=f.second.first;
            int y=f.second.second;
            int wt=f.first;

            //if(vis[x][y]==1) continue;

            //vis[x][y]=1;

            if(wt > dis[x][y]) continue;

            for(int i=0;i<4;i++){

                int newx=x+dir[i][0];
                int newy=y+dir[i][1];

                int nbw=1;

                if(newx>=0 && newx<n && newy>=0 && newy<m){

                    if(grid[x][y]==i+1){
                        nbw=0;

                    }

                    if(dis[newx][newy]>wt+nbw){
                        dis[newx][newy]=wt+nbw;
                        pq.push({dis[newx][newy],{newx,newy}});
                    }
                }
            }
            
        }

        return dis[n-1][m-1];
        
    }
};