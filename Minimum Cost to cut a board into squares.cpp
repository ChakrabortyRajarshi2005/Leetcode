Minimum Cost to cut a board into squares
Difficulty: MediumAccuracy: 60.83%Submissions: 27K+Points: 4
Given a board of dimensions n × m that needs to be cut into n*m squares. The cost of making a cut along a horizontal or vertical edge is provided in two arrays:

x[]: Cutting costs along the vertical edges (length-wise).
y[]: Cutting costs along the horizontal edges (width-wise).
Find the minimum total cost required to cut the board into squares optimally.

Examples:

Input: n = 4, m = 6, x[] = [2, 1, 3, 1, 4], y[] = [4, 1, 2]
Output: 42
Explanation:

Initially no. of horizontal segments = 1 & no. of vertical segments = 1.
Optimal way to cut into square is:
• Pick 4 (from x) -> vertical cut, Cost = 4 × horizontal segments = 4,
  Now, horizontal segments = 1, vertical segments = 2.
• Pick 4 (from y) -> horizontal cut, Cost = 4 × vertical segments = 8,
  Now, horizontal segments = 2, vertical segments = 2.
• Pick 3 (from x) -> vertical cut, Cost = 3 × horizontal segments = 6,
  Now, horizontal segments = 2, vertical segments = 3.
• Pick 2 (from x) -> vertical cut, Cost = 2 × horizontal segments = 4,
  Now, horizontal segments = 2, vertical segments = 4.
• Pick 2 (from y) -> horizontal cut, Cost = 2 × vertical segments = 8,
  Now, horizontal segments = 3, vertical segments = 4.
• Pick 1 (from x) -> vertical cut, Cost = 1 × horizontal segments = 3,
  Now, horizontal segments = 3, vertical segments = 5.
• Pick 1 (from x) -> vertical cut, Cost = 1 × horizontal segments = 3,
  Now, horizontal segments = 3, vertical segments = 6.
• Pick 1 (from y) -> horizontal cut, Cost = 1 × vertical segments = 6,
  Now, horizontal segments = 4, vertical segments = 6.
So, the total cost = 4 + 8 + 6 + 4 + 8 + 3 + 3 + 6 = 42.
Input: n = 4, m = 4, x[] = [1, 1, 1], y[] = [1, 1, 1]
Output: 15
Explanation: 

Initially no. of horizontal segments = 1 & no. of vertical segments = 1.
Optimal way to cut into square is: 
• Pick 1 (from y) -> horizontal cut, Cost = 1 × vertical segments = 1,
  Now, horizontal segments = 2, vertical segments = 1.
• Pick 1 (from y) -> horizontal cut, Cost = 1 × vertical segments = 1,
  Now, horizontal segments = 3, vertical segments = 1.
• Pick 1 (from y) -> horizontal cut, Cost = 1 × vertical segments = 1,
  Now, horizontal segments = 4, vertical segments = 1.
• Pick 1 (from x) -> vertical cut, Cost = 1 × horizontal segments = 4,
  Now, horizontal segments = 4, vertical segments = 2.
• Pick 1 (from x) -> vertical cut, Cost = 1 × horizontal segments = 4,
  Now, horizontal segments = 4, vertical segments = 3.
• Pick 1 (from x) -> vertical cut, Cost = 1 × horizontal segments = 4,
  Now, horizontal segments = 4, vertical segments = 4
So, the total cost = 1 + 1 + 1 + 4 + 4 + 4 = 15.
Constraints:
2 ≤ n, m ≤ 103
1 ≤ x[i], y[j] ≤103



Topic Tags
Related Articles
C++ (12)

        


 

Custom Input
If you are facing any issue on this page. Please let us know.
Hint 1

Hint 2

 Full Solution

class Solution {
  public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        // Sort the cutting costs in ascending order
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        int hCount = 1, vCount = 1;
        int i = x.size() - 1, j = y.size() - 1;
        int totalCost = 0;

        while (i >= 0 && j >= 0) {

            // Choose the larger cost cut to
            // minimize future costs
            if (x[i] >= y[j]) {
                totalCost += x[i] * hCount;
                vCount++;
                i--;
            } else {
                totalCost += y[j] * vCount;
                hCount++;
                j--;
            }
        }

        // Process remaining vertical cuts
        while (i >= 0) {
            totalCost += x[i] * hCount;
            vCount++;
            i--;
        }

        // Process remaining horizontal cuts
        while (j >= 0) {
            totalCost += y[j] * vCount;
            hCount++;
            j--;
        }

        return totalCost;
    }
};
