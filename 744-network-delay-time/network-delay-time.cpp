class Solution {
public:
    int getminvertex(vector<int>& visited,vector<int>&dis,int n){

        int minvertex=-1;

        for(int i=0;i<n;i++){

            if(visited[i]==false && (minvertex==-1 || dis[i]<dis[minvertex])){

                minvertex=i;
            }
        }

        return minvertex;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {




        vector<vector<pair<int,int>>> adj(n);


        for(int i=0;i<times.size();i++){

            int s=times[i][0]-1;
            int e=times[i][1]-1;
            int w=times[i][2];

            adj[s].push_back({e,w});
        }

        vector<int> visited(n,0);

        vector<int> dis(n,INT_MAX);

        //visited[k-1]=1;
        dis[k-1]=0;

        for(int i=0;i<n;i++){

            int minvertex=getminvertex(visited,dis,n);

            visited[minvertex]=1;

            for(int i=0;i<adj[minvertex].size();i++){

                pair<int,int> nb=adj[minvertex][i];

                if(visited[nb.first]==false && dis[minvertex] != INT_MAX && dis[nb.first]>dis[minvertex]+adj[minvertex][i].second){

                    dis[nb.first]=dis[minvertex]+adj[minvertex][i].second;
                }
            }
        }


        int ans=0;

        for(int i=0;i<n;i++){

            if(i!=k-1){

                if (dis[i] == INT_MAX)  return -1;

                ans=max(ans,dis[i]);
            }
        }

        return ans;
        
    }
};