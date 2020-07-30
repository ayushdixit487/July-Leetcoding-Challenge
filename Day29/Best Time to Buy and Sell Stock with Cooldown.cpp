class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<=1)
            return 0;
        
         int dp[n][2];
         memset(dp,-1,sizeof(dp));
        
        return maxProfit(prices ,0,0,dp);
        
    }
    int maxProfit(vector<int> & prices ,int idx ,int buyOrSell ,int dp[][2]){
        if(idx>=prices.size())
            return 0;
        
        if(dp[idx][buyOrSell]!=-1)
            return dp[idx][buyOrSell];
        
        int profit= 0;
        if(buyOrSell==0){
            int buy = maxProfit(prices ,idx+1,1,dp) - prices[idx];
            int noBuy = maxProfit(prices ,idx+1 ,0,dp);
            profit = max(buy,noBuy);
        }else{
            int sell = maxProfit(prices,idx+2,0,dp) + prices[idx];
            int noSell = maxProfit(prices,idx+1 ,1,dp);
            profit = max(sell,noSell);
        }
        
        return dp[idx][buyOrSell] = profit;
    }
};
