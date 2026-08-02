class Solution {
public:
    int getparent(int i,vector<int>& parent){
        if(parent[i]==i) return i;

        return parent[i]=getparent(parent[i],parent);
    }

    void uni(int a,int b,vector<int> & parent){

        int px=getparent(a,parent);
        int py=getparent(b,parent);

        if(px==py) return;

        parent[py]=px;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n=accounts.size();

        vector<int>parent(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }


        sort(accounts.begin(),accounts.end());

        unordered_map<string,int> mpnode;

        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(mpnode.find(accounts[i][j])==mpnode.end()){
                    mpnode[accounts[i][j]]=i;
                }

                else{
                    uni(i,mpnode[accounts[i][j]],parent);
                }
            }
        }

        vector<string> arr[n];

        for(auto it : mpnode){

            string mail=it.first;
            int p=getparent(it.second,parent);
            arr[p].push_back(mail);

            
        }

        vector<vector<string>> ans;

        for(int i=0;i<n;i++){
            if(arr[i].size()==0) continue;

            sort(arr[i].begin(),arr[i].end());
            vector<string> temp;

            temp.push_back(accounts[i][0]);
            for(auto it : arr[i]){
                temp.push_back(it);
            }

            ans.push_back(temp);
        }

        sort(ans.begin(),ans.end());

        return ans;
        
    }
};