// Question Link : https://leetcode.com/problems/delete-operation-for-two-strings/

// Level : medium 

class Solution {
public:
    int dp[1001][1001];
    int LCS(string word1, string word2, int n, int m){
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(word1[i]==word2[j]){
                        dp[i+1][j+1]= 1+dp[i][j];
                    }
                    else{
                        dp[i+1][j+1]= max(dp[i][j+1],dp[i+1][j]);
                    }
                }
            }
        return dp[n][m];
    }
    int minDistance(string word1, string word2) {
        int n = word1.size(); int m=word2.size();
        for(int i=0;i<1001;i++){
            for(int j=0;j<1001;j++){
                dp[i][j]=0;
            }
        }
        int cunt = LCS(word1,word2,n,m); cout<<cunt<<endl;
        return (n-cunt)+(m-cunt);
    }
};