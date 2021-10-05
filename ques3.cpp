// Question Link : https://leetcode.com/problems/coin-change/

// Level : medium 

class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int w = amount; 
        
        int dp[w+1];
        dp[0]=0;
        for(int i=1;i<=w;i++){
            dp[i]= INT_MAX;
        }
        
        for(int i=1;i<=w;i++){
            for(int j=0;j<n;j++){
                if(coins[j]<= i){
                    if(dp[i-coins[j]]!= INT_MAX){
                        dp[i] = min(dp[i],1+dp[i-coins[j]]);
                    }
                }
            }
        }
        
        if(dp[w]==INT_MAX){
            return -1;
        }
        else{
            return dp[w];
        }
        
    }
};