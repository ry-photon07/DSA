class Solution {
public:
    typedef pair<int,int> ppp;
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n=points.size();

        vector<int> vis(n,0);

        vector<int> dis(n,INT_MAX);

        

        dis[0]=0;

        int ans=0;

        priority_queue<ppp,vector<ppp>,greater<ppp>> pq;

        pq.push({0,0});

        int count=0;

        while(count<n && !pq.empty()){

            ppp f=pq.top();
            pq.pop();

            int ni=f.second;

            if (vis[ni]) continue;

            vis[ni]=1;

            ans+=f.first;
            count++;

            for(int i=0;i<n;i++){

                if(vis[i]==0){

                    int nodei=points[ni][0];
                    int nodej=points[ni][1];

                    int nbi=points[i][0];
                    int nbj=points[i][1];

                    int dist=abs(nodei-nbi)+abs(nodej-nbj);

                    if(dis[i]>=dist){
                        dis[i]=dist;
                        pq.push({dis[i],i});
                    }
                }
            }
        }

        return ans;


        
    }
};