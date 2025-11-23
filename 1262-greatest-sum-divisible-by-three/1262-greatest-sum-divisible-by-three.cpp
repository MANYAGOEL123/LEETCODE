#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        // dp[r] = maximum sum we can get such that sum % 3 == r
        // Initialize with very small numbers (impossible states)
        const int NEG_INF = INT_MIN / 2;  // avoid overflow
        vector<int> dp(3, NEG_INF);
        
        dp[0] = 0;  // sum = 0 is possible and 0 % 3 == 0
        
        for (int x : nums) {
            vector<int> newDp = dp;  // start from current bests
            
            for (int r = 0; r < 3; r++) {
                if (dp[r] == NEG_INF) continue;  // this remainder not reachable yet
                
                int newRemainder = (r + x) % 3;
                int newSum = dp[r] + x;
                
                newDp[newRemainder] = max(newDp[newRemainder], newSum);
            }
            
            dp = newDp;
        }
        
        // We want the largest sum which is divisible by 3
        return dp[0];
    }
};
