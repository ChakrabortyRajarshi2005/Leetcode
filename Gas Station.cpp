Gas Station
Difficulty: MediumAccuracy: 34.79%Submissions: 213K+Points: 4Average Time: 20m
There are n gas stations along a circular tour. You are given two integer arrays gas[] and cost[], where gas[i] is the amount of gas available at station i and cost[i] is the gas needed to travel from station i to station (i+1). You have a car with an unlimited gas tank and start with an empty tank at some station. Your task is to return the index of the starting station if it is possible to travel once around the circular route in a clockwise direction without running out of gas at any station; otherwise, return -1.

Note: If a solution exists, it is guaranteed to be unique.

Examples:

Input: gas[] = [4, 5, 7, 4], cost[]= [6, 6, 3, 5]
Output: 2
Explanation: Start at gas station at index 2 and fill up with 7 units of gas. Your tank = 0 + 7 = 7
Travel to station 3. Available gas = (7 – 3 + 4) = 8.
Travel to station 0. Available gas = (8 – 5 + 4) = 7.
Travel to station 1. Available gas = (7 – 6 + 5) = 6.
Return to station 2. Available gas = (6 – 6) = 0.
Input: gas[] = [3, 9], cost[] = [7, 6]
Output: -1
Explanation: There is no gas station to start with such that you can complete the tour.
Constraints:
1 ≤ n ≤ 106
1 ≤ gas[i], cost[i] ≤ 103

Expected Complexities
Company Tags
ZohoFlipkartMorgan StanleyAmazonMicrosoftFactSetGoogle
Topic Tags
Related Interview Experiences
Related Articles
class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();

        // Variables to track total and current remaining gas
        int totalGas = 0;
        int currGas = 0;
        int startIdx = 0;

        // Traverse through each station to calculate remaining
        // gas in the tank, and total gas
        for (int i = 0; i < n; i++) {
            currGas += gas[i] - cost[i];
            totalGas += gas[i] - cost[i];

            // If currGas is negative, circular tour can't
            // start with this index, so update it to next one
            if (currGas < 0) {
                currGas = 0;
                startIdx = i + 1;
            }
        }

        // No solution exist
        if (totalGas < 0)
            return -1;

        return startIdx;
    }
};
