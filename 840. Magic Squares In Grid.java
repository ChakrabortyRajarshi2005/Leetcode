840. Magic Squares In Grid
Medium
Topics
premium lock icon
Companies
A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.

Given a row x col grid of integers, how many 3 x 3 magic square subgrids are there?

Note: while a magic square can only contain numbers from 1 to 9, grid may contain numbers up to 15.

 

Example 1:


Input: grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]]
Output: 1
Explanation: 
The following subgrid is a 3 x 3 magic square:

while this one is not:

In total, there is only one magic square inside the given grid.
Example 2:

Input: grid = [[8]]
Output: 0
 

Constraints:

row == grid.length
col == grid[i].length
1 <= row, col <= 10
0 <= grid[i][j] <= 15
class Solution {

    public int numMagicSquaresInside(int[][] grid) {
        int ans = 0;
        int m = grid.length;
        int n = grid[0].length;
        for (int row = 0; row + 2 < m; row++) {
            for (int col = 0; col + 2 < n; col++) {
                if (isMagicSquare(grid, row, col)) {
                    ans++;
                }
            }
        }
        return ans;
    }

    private boolean isMagicSquare(int[][] grid, int row, int col) {
        String sequence = "2943816729438167";
        String sequenceReversed = "7618349276183492";

        StringBuilder border = new StringBuilder();
        int[] borderIndices = new int[] { 0, 1, 2, 5, 8, 7, 6, 3 };
        for (int i : borderIndices) {
            int num = grid[row + i / 3][col + (i % 3)];
            border.append(num);
        }

        String borderConverted = border.toString();

        return (
            grid[row][col] % 2 == 0 &&
            (sequence.contains(borderConverted) ||
                sequenceReversed.contains(borderConverted)) &&
            grid[row + 1][col + 1] == 5
        );
    }
}
