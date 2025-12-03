Travelling Salesman Problem
Difficulty: HardAccuracy: 46.35%Submissions: 34K+Points: 8Average Time: 25m
Given a 2d matrix cost[][] of size n where cost[i][j] denotes the cost of moving from city i to city j. Your task is to complete a tour from city 0 (0-based index) to all other cities such that you visit each city exactly once and then at the end come back to city 0 at minimum cost.

Examples:

Input: cost[][] = [[0, 111], 
                [112, 0]]
Output: 223
Explanation: We can visit 0->1->0 and cost = 111 + 112.
Input: cost[][] = [[0, 1000, 5000],
                [5000, 0, 1000],
                [1000, 5000, 0]]
Output: 3000
Explanation: We can visit 0->1->2->0 and cost = 1000 + 1000 + 1000 = 3000
Constraints:
1 ≤ cost.size() ≤ 15
0 ≤ cost[i][j] ≤ 104


class Solution {
    public int tsp(int[][] cost) {
        int n = cost.length;
        if (n <= 1) return n == 1 ? cost[0][0] : 0;

        final int INF = Integer.MAX_VALUE;
        int FULL = 1 << n, fullMask = FULL - 1;
        int[][] dp = new int[FULL][n];
        for (int[] row : dp) Arrays.fill(row, INF);
        dp[1][0] = 0;

        for (int mask = 1; mask < FULL; mask++) {
            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i)) == 0) continue;
                if (dp[mask][i] == INF) continue;
                for (int j = 0; j < n; j++) {
                    if ((mask & (1 << j)) != 0) continue;
                    int nxt = mask | (1 << j);
                    dp[nxt][j] = Math.min(dp[nxt][j], dp[mask][i] + cost[i][j]);
                }
            }
        }

        int ans = INF;
        for (int i = 0; i < n; i++) {
            if (dp[fullMask][i] != INF)
                ans = Math.min(ans, dp[fullMask][i] + cost[i][0]);
        }

        return ans;
    }
}
