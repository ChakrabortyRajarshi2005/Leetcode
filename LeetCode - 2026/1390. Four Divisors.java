1390. Four Divisors
Medium
Topics
premium lock icon
Companies
Given an integer array nums, return the sum of divisors of the integers in that array that have exactly four divisors. If there is no such integer in the array, return 0.

 

Example 1:

Input: nums = [21,4,7]
Output: 32
Explanation: 
21 has 4 divisors: 1, 3, 7, 21
4 has 3 divisors: 1, 2, 4
7 has 2 divisors: 1, 7
The answer is the sum of divisors of 21 only.
Example 2:

Input: nums = [21,21]
Output: 64
Example 3:

Input: nums = [1,2,3,4,5]
Output: 0
 

Constraints:

1 <= nums.length <= 104
1 <= nums[i] <= 105

class Solution {
    private boolean[] sieve;

    private void buildSieve(int n) {
        sieve = new boolean[n + 1];
        java.util.Arrays.fill(sieve, true);
        if (n >= 0) sieve[0] = false;
        if (n >= 1) sieve[1] = false;
        for (int i = 2; i * i <= n; i++) {
            if (sieve[i]) {
                for (int j = i * i; j <= n; j += i) {
                    sieve[j] = false;
                }
            }
        }
    }

    public int sumFourDivisors(int[] nums) {
        int maxNum = 0;
        for (int x : nums) {
            if (x > maxNum) maxNum = x;
        }
        if (maxNum < 2) return 0;
        buildSieve(maxNum);

        int total = 0;
        for (int x : nums) {
            int p = (int) Math.round(Math.cbrt(x));
            if ((long) p * p * p == x && p >= 0 && p < sieve.length && sieve[p]) {
                total += 1 + p + p * p + x;
                continue;
            }

            for (int i = 2; i * i <= x; i++) {
                if (x % i == 0) {
                    int j = x / i;
                    if (i != j && i < sieve.length && j < sieve.length && sieve[i] && sieve[j]) {
                        total += 1 + i + j + x;
                    }
                    break;
                }
            }
        }
        return total;
    }
}
