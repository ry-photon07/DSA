class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {


        int n=nums.size();


        vector<int> presum(n,0);

        int j=0;

        int result=INT_MAX;

        deque<int> dq;

        while(j<n){

            if(j==0){

                presum[j]=nums[j];
            }

            else{

                presum[j]=presum[j-1]+nums[j];
            }

            if(presum[j]>=k){
                result=min(result,j+1);//j-i+1 i==>0
            }

            while(!dq.empty() && presum[j]-presum[dq.front()]>=k){

                result=min(result,j-dq.front());
                dq.pop_front();
            }

            while(!dq.empty() && presum[j]<=presum[dq.back()]){
                dq.pop_back();
            }

            dq.push_back(j);
            j++;
        }

        return (result==INT_MAX) ? -1 : result;
        
    }
};