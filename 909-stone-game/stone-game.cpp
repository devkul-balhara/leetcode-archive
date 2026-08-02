class Solution {
public:
    // if alice wins from curr till end 
    /*bool rec(int s, int e, int sum, vector<int>& piles, vector<vector<vector<int>>>& dp, int& tot){
        if(s == e){
            int a_sum = sum, b_sum = tot-sum;
            return (a_sum > b_sum);
        }
        if(dp[s][e][sum] != -1) return dp[s][e][sum];
        bool ans = false;
        // if its alice turn
        if((e-s+1)%2 == 0){
            // option 1
            int x = piles[s];
            ans |= rec(s+1, e, sum+x, piles, dp, tot);
            // option 2
            int y = piles[e];
            ans |= rec(s, e-1, sum+y, piles, dp, tot);
        }
        else{
            // option 1
            ans |= rec(s+1, e, sum, piles, dp, tot);
            // option 2
            ans |= rec(s, e-1, sum, piles, dp, tot);
        }
        return dp[s][e][sum] = ans;
    }*/

    bool stoneGame(vector<int>& piles) {
        /*int n = piles.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n, vector<int>(250*n,-1)));
        int tot = accumulate(piles.begin(), piles.end(), 0);
        return rec(0,n-1,0,piles,dp,tot);*/
        return true;
    }
};