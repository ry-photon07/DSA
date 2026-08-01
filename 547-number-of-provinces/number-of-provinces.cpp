class Solution {
public:
    int getparent(int i,vector<int>& parent){

        if(parent[i]==i) return i;

        return parent[i]=getparent(parent[i],parent);
    }

    void uni(int x,int y,vector<int>& parent){

        int px=getparent(x,parent);
        int py=getparent(y,parent);

        if(px==py) return;

        parent[py]=px;

        return ;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {

        int n=isConnected.size();

        vector<int> parent(n+1,0);

        for(int i=0;i<n+1;i++){
            parent[i]=i;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                if(isConnected[i][j]==1){

                    int x=i+1;
                    int y=j+1;

                    uni(x,y,parent);
                }
            }
        }  

        int ans=0;

        for(int i=1;i<n+1;i++) {

            if(parent[i]==i){
                ans++;
            }
        }

        return ans;

        


        
    }
};