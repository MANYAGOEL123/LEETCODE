class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        // dp[i][j][c] = max score at (i, j) with exactly cost 'c'
        // Initialize with -1 to indicate unreachable paths
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));
        
        // Base case: Starting point
        dp[0][0][0] = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Determine the cost and score contribution of the current cell
                int cellCost = (grid[i][j] == 0) ? 0 : 1;
                int cellScore = grid[i][j];
                
                for (int c = cellCost; c <= k; ++c) {
                    int prevScore = -1;
                    
                    // Option 1: Coming from the top
                    if (i > 0) {
                        prevScore = max(prevScore, dp[i-1][j][c - cellCost]);
                    }
                    
                    // Option 2: Coming from the left
                    if (j > 0) {
                        prevScore = max(prevScore, dp[i][j-1][c - cellCost]);
                    }
                    
                    // If we reached this cell from a valid previous state, update score
                    if (prevScore != -1) {
                        dp[i][j][c] = max(dp[i][j][c], prevScore + cellScore);
                    }
                }
            }
        }
        
        // Find the maximum score at the destination (m-1, n-1) for any cost <= k
        int maxScore = -1;
        for (int c = 0; c <= k; ++c) {
            maxScore = max(maxScore, dp[m-1][n-1][c]);
        }
        
        return maxScore;
    }
};