class Solution {
public:
    typedef pair<int,double> pp;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {

        vector<vector<pp>> adj(n);

        for(int i=0;i<edges.size();i++){

            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});

        }

        vector<double> dis(n,INT_MIN);

        dis[start_node]=1;

        priority_queue<pair<double,int>> pq;

        pq.push({1,start_node});

        while(!pq.empty()){

            auto f= pq.top();
            pq.pop();

            double wt=f.first;
            int node=f.second;

            

            for(int i=0;i<adj[node].size();i++){

                int nb=adj[node][i].first;
                double nwt=adj[node][i].second;

                if(dis[nb]<wt*nwt){

                    dis[nb]=wt*nwt;
                    pq.push({dis[nb],nb});
                }
            }

            
        }

        if(dis[end_node]==INT_MIN) return 0;

        return dis[end_node];

      


        
    }
};