class Solution {
public:

    int dp[46];
    int  t(int i,int n ){

        if(i>n){
            return 0;
        }

        if(i==n){
            return 1;
        }

        if(dp[i]!=-1) return dp[i];

        int way1=0;
        int way2=0;
        way1=t(i+1,n);
        way2=t(i+2,n);

        return dp[i]=way1+way2;
    }
    int climbStairs(int n) {

        memset(dp,-1,sizeof(dp));
        return t(0,n);
        
    }
};