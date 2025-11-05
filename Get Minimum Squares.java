Get Minimum Squares
Difficulty: MediumAccuracy: 45.22%Submissions: 50K+Points: 4
Given a positive integer n, find the minimum number of perfect squares (square of an integer) that sum up to n.

Note: Every positive integer can be expressed as a sum of square numbers since 1 is a perfect square, and any number can be represented as 1*1 + 1*1 + 1*1 + ....

Examples:

Input: n = 100
Output: 1
Explanation: 10 * 10 = 100
Input: n = 6
Output: 3
Explanation = 1 * 1 + 1 * 1 + 2 * 2 = 6 
Constraints:
1 ≤ n ≤ 104class Solution {
    public boolean isSquare(int x) {
        int sqRoot = (int)Math.sqrt(x);
        return (sqRoot * sqRoot == x);
    }

    public int minSquares(int n) {
        if (isSquare(n)) {
            return 1;
        }
        for (int i = 1; i * i <= n; i++) {
            if (isSquare(n - (i * i))) {
                return 2;
            }
        }

        while (n > 0 && n % 4 == 0) {
            n /= 4;
        }
        if (n % 8 == 7) {
            return 4;
        }
        return 3;
    }
}
