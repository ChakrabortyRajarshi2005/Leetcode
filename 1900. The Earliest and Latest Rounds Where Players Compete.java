1900. The Earliest and Latest Rounds Where Players Compete
Solved
Hard
Topics
premium lock icon
Companies
Hint
There is a tournament where n players are participating. The players are standing in a single row and are numbered from 1 to n based on their initial standing position (player 1 is the first player in the row, player 2 is the second player in the row, etc.).

The tournament consists of multiple rounds (starting from round number 1). In each round, the ith player from the front of the row competes against the ith player from the end of the row, and the winner advances to the next round. When the number of players is odd for the current round, the player in the middle automatically advances to the next round.

For example, if the row consists of players 1, 2, 4, 6, 7
Player 1 competes against player 7.
Player 2 competes against player 6.
Player 4 automatically advances to the next round.
After each round is over, the winners are lined back up in the row based on the original ordering assigned to them initially (ascending order).

The players numbered firstPlayer and secondPlayer are the best in the tournament. They can win against any other player before they compete against each other. If any two other players compete against each other, either of them might win, and thus you may choose the outcome of this round.

Given the integers n, firstPlayer, and secondPlayer, return an integer array containing two values, the earliest possible round number and the latest possible round number in which these two players will compete against each other, respectively.

 

Example 1:

Input: n = 11, firstPlayer = 2, secondPlayer = 4
Output: [3,4]
Explanation:
One possible scenario which leads to the earliest round number:
First round: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
Second round: 2, 3, 4, 5, 6, 11
Third round: 2, 3, 4
One possible scenario which leads to the latest round number:
First round: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
Second round: 1, 2, 3, 4, 5, 6
Third round: 1, 2, 4
Fourth round: 2, 4
Example 2:

Input: n = 5, firstPlayer = 1, secondPlayer = 5
Output: [1,1]
Explanation: The players numbered 1 and 5 compete in the first round.
There is no way to make them compete in any other round.
 

Constraints:

2 <= n <= 28
1 <= firstPlayer < secondPlayer <= n
class Solution {

    private int[][][] F = new int[30][30][30];
    private int[][][] G = new int[30][30][30];

    private int[] dp(int n, int f, int s) {
        if (F[n][f][s] != 0) {
            return new int[] { F[n][f][s], G[n][f][s] };
        }
        if (f + s == n + 1) {
            return new int[] { 1, 1 };
        }
        // F(n,f,s) = F(n, n + 1 - s, n + 1 - f)
        if (f + s > n + 1) {
            int[] res = dp(n, n + 1 - s, n + 1 - f);
            F[n][f][s] = res[0];
            G[n][f][s] = res[1];
            return new int[] { F[n][f][s], G[n][f][s] };
        }

        int earliest = Integer.MAX_VALUE;
        int latest = Integer.MIN_VALUE;
        int n_half = (n + 1) / 2;
        if (s <= n_half) {
            // On the left or in the middle
            for (int i = 0; i < f; ++i) {
                for (int j = 0; j < s - f; ++j) {
                    int[] res = dp(n_half, i + 1, i + j + 2);
                    earliest = Math.min(earliest, res[0]);
                    latest = Math.max(latest, res[1]);
                }
            }
        } else {
            // s on the right
            int s_prime = n + 1 - s;
            int mid = (n - 2 * s_prime + 1) / 2;
            for (int i = 0; i < f; ++i) {
                for (int j = 0; j < s_prime - f; ++j) {
                    int[] res = dp(n_half, i + 1, i + j + mid + 2);
                    earliest = Math.min(earliest, res[0]);
                    latest = Math.max(latest, res[1]);
                }
            }
        }

        F[n][f][s] = earliest + 1;
        G[n][f][s] = latest + 1;
        return new int[] { F[n][f][s], G[n][f][s] };
    }

    public int[] earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        // F(n,f,s) = F(n,s,f)
        if (firstPlayer > secondPlayer) {
            int temp = firstPlayer;
            firstPlayer = secondPlayer;
            secondPlayer = temp;
        }

        int[] res = dp(n, firstPlayer, secondPlayer);
        return new int[] { res[0], res[1] };
    }
}
