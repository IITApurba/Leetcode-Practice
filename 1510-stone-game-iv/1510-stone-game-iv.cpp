class Solution {
public:
    bool isPerfectSquare(int n) {
        if(n<=0)return false;
        int root=sqrt(n);
        return (root*root==n);
    }
    bool winnerSquareGame(int n) {
        vector<bool> dp(n+1,false);
        for(int i=1;i<=n;i++){
            for(int k=1;k*k<=i;k++){
                if(dp[i-k*k]==false){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n];
    }
};