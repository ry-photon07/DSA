class Solution {
public:
    int t[101];
    int dp(int i,vector<int>&nums,int n){

        if(i>=n)  return 0;

        if(t[i]!=-1) return t[i];
        int take=0;
        int nottake=0;

        take+=nums[i]+dp(i+2,nums,n);
        nottake=dp(i+1,nums,n);

        return t[i]= max(take,nottake);


    }
    int rob(vector<int>& nums) {


        memset(t,-1,sizeof(t));
        return dp(0,nums,nums.size());
        
    }
};