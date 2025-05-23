790. Domino and Tromino Tiling
DescriptionHintsSubmissionsDiscussSolutions
You have two types of tiles: a 2 x 1 domino shape and a tromino shape. You may rotate these shapes.


Given an integer n, return the number of ways to tile an 2 x n board. Since the answer may be very large, return it modulo 109 + 7.

In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.

 

Example 1:


Input: n = 3
Output: 5
Explanation: The five different ways are show above.
Example 2:

Input: n = 1
Output: 1
 

Constraints:

1 <= n <= 1000
Seen this question in a real interview before?  


class Solution {
private:
    static const int mod = 1e9 + 7;
    vector<vector<long long>> multiply(const vector<vector<long long>> &A, const vector<vector<long long>> &B) {
        vector<vector<long long>> C(3, vector<long long>(3, 0));
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                long long sum = 0;
                for (int k = 0; k < 3; k++) {
                    sum = (sum + A[i][k] * B[k][j]) % mod;
                }
                C[i][j] = sum;
            }
        }
        return C;
    }

    vector<vector<long long>> power(vector<vector<long long>> base, long long exp) {
        vector<vector<long long>> result = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
        while (exp > 0) {
            if (exp & 1) result = multiply(result, base);
            base = multiply(base, base);
            exp >>= 1;
        }
        return result;
    }

    public:
        int numTilings(int n) {
            if (n == 0) return 1;
            if (n == 1) return 1;
            if (n == 2) return 2;

            vector<vector<long long>> temp = {{2, 0, 1}, {1, 0, 0}, {0, 1, 0}};
            vector<vector<long long>> powered = power(temp, n - 2);
            long long answer = (powered[0][0] * 2 + powered[0][1] * 1 + powered[0][2] * 1) % mod;

            return answer;
        }
    };
