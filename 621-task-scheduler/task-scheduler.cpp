class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        vector<int> freq(26,0);

        for(int i=0;i<tasks.size();i++){
            freq[tasks[i]-'A']++;
        }

        priority_queue<int> maxh;

        for(int i=0;i<26;i++){

            if(freq[i]>0){

                maxh.push(freq[i]);
            }
        }

        int time=0;

        while(!maxh.empty()){

            vector<int> temp;

            //if(maxh.top()-1>0)   temp.push_back(maxh.top()-1);

            //maxh.pop();

            for(int i=0;i<=n;i++){

                if(!maxh.empty()){

                    temp.push_back(maxh.top()-1);
                    maxh.pop();

                }
            }

            for(int i=0;i<temp.size();i++){

                if(temp[i]>0){
                    maxh.push(temp[i]);
                }
            }

            if(maxh.size()>0){
                time+=n+1;
            }

            else{
                time+=temp.size();
            }

            
        }

        return time;
        
    }
};