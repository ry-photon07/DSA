class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<int>> grid(n,vector<int>(n,INT_MAX));

        for(int i=0;i<n;i++){
            grid[i][i]=0;
        }

        for(int i=0;i<edges.size();i++){

            grid[edges[i][0]][edges[i][1]]=edges[i][2];
            grid[edges[i][1]][edges[i][0]]=edges[i][2];
        }


        for(int via=0;via<n;via++){

            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){

                    if(grid[i][via]!=INT_MAX && grid[via][j]!=INT_MAX){

                        grid[i][j]=min(grid[i][j],grid[i][via]+grid[via][j]);
                    }
                }
            }
        }

        int canvis=INT_MAX;
        int value=-1;

        for(int i=0;i<n;i++){

            int tempvis=0;
            for(int j=0;j<n;j++){

                if(grid[i][j]<=distanceThreshold){
                    tempvis++;

                }

            }

            if(tempvis<=canvis) {
                canvis=tempvis;
                value=i;
            }

        }
        return value;

        
        
    }
};