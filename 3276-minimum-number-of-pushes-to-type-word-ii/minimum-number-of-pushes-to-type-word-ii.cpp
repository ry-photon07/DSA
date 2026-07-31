class Solution {
public:
    int minimumPushes(string word) {


        unordered_map<char,int> mp;

        for(int i=0;i<word.size();i++){

            mp[word[i]]++;
        }

        priority_queue<int> heap;

        for(auto it : mp){

            heap.push(it.second);
        }


        int i=1;

        int count=1;

        int press=0;

        while(!heap.empty()){

            int x=heap.top();
            heap.pop();

            press+=(x*(i));
            count++;

            if(count==9){
                i++;
                count=1;
            }
        }

        return press;
        
    }
};