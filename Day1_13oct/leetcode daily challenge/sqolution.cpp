class Solution {
public:

 int solve(vector<int>&cost  , int i  , vector<int>&dp){
     if(i==cost.size()-1 || i== cost.size()-2) return cost[i];
     if(dp[i] != -1) return dp[i];
     int a = solve(cost , i+1 , dp );
     int b =  solve(cost , i+2 , dp);
     dp[i]= min(a , b) + cost[i];
     return dp[i];


 } 
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(10000 , -1);
     
    int a = solve(cost  , 0 , dp);
     int b = solve(cost  , 1 , dp);
   
   return min(a , b);
        
    }
};
