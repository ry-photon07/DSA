class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        int n=grid.size();

        vector<vector<int>> dis(n,vector<int>(n,INT_MAX));

        dis[0][0]=grid[0][0];

        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;

        pq.push({dis[0][0],0,0});

        int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};

        //int ans=grid[0][0];

        while(!pq.empty()){

            auto [f ,x ,y]=pq.top();
            pq.pop();


            for(int i=0;i<4;i++){

                int newx=x+dir[i][0];
                int newy=y+dir[i][1];

                if(newx>=0 && newx<n && newy>=0 && newy<n && dis[newx][newy]>max(f,grid[newx][newy]) ){

                    dis[newx][newy]=max(f,grid[newx][newy]);

                    //ans=max(ans,dis[newx][newy])

                    pq.push({dis[newx][newy],newx,newy});
                }
            }


        }

        return dis[n-1][n-1];

        
    }
};