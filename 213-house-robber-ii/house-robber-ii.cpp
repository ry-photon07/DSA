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

        if(nums.size()==1){
            
            return nums[0];
        }

        if(nums.size()==2){
            
            return max(nums[0],nums[1]);
        }

        memset(t,-1,sizeof(t));

        int a=dp(0,nums,nums.size()-1);

        memset(t,-1,sizeof(t));

        vector<int> temp(nums.size()-1);

        copy(nums.begin()+1,nums.end(),temp.begin());

        int b=dp(0,temp,temp.size());

        return max(a,b);




        
        
    }
};