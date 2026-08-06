class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans=0;

        sort(intervals.begin(),intervals.end());

        int last=intervals[0][1];

        int n=intervals.size();

        for(int i=1;i<n;i++){

            if(last>intervals[i][0]){
                ans++;
                last=min(intervals[i][1],last);
            }

            else{

                last=intervals[i][1];
            }
        }

        return ans;
        
    }
};