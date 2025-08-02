
Longest Subarray with Majority Greater than K
Difficulty: MediumAccuracy: 52.63%Submissions: 24K+Points: 4
Given an array arr[] and an integer k, the task is to find the length of longest subarray in which the count of elements greater than k is more than the count of elements less than or equal to k.

Examples:

Input: arr[] = [1, 2, 3, 4, 1], k = 2
Output: 3
Explanation: The subarray [2, 3, 4] or [3, 4, 1] satisfy the given condition, and there is no subarray of length 4 or 5 which will hold the given condition, so the answer is 3.
Input: arr[] = [6, 5, 3, 4], k = 2
Output: 4
Explanation: In the subarray [6, 5, 3, 4], there are 4 elements > 2 and 0 elements <= 2, so it is the longest subarray.
Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ 106
0 ≤ k ≤ 106


class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> mp;
        int ans = 0, sum = 0;

        for (int i = 0; i < n; ++i) {
            // Treat elements <= k as -1, elements > k as +1
            if (arr[i] <= k)
                sum--;
            else
                sum++;

            // If overall sum is positive, entire prefix is valid
            if (sum > 0)
                ans = i + 1;
            else {
                // Check if there was a prefix with sum = current_sum - 1
                if (mp.find(sum - 1) != mp.end()) {
                    ans = max(ans, i - mp[sum - 1]);
                }
            }

            // Store the first occurrence of each prefix sum
            if (mp.find(sum) == mp.end()) {
                mp[sum] = i;
            }
        }

        return ans;
    }
};
