3027. Find the Number of Ways to Place People II
Solved
Hard
Topics
premium lock icon
Companies
Hint
You are given a 2D array points of size n x 2 representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

We define the right direction as positive x-axis (increasing x-coordinate) and the left direction as negative x-axis (decreasing x-coordinate). Similarly, we define the up direction as positive y-axis (increasing y-coordinate) and the down direction as negative y-axis (decreasing y-coordinate)

You have to place n people, including Alice and Bob, at these points such that there is exactly one person at every point. Alice wants to be alone with Bob, so Alice will build a rectangular fence with Alice's position as the upper left corner and Bob's position as the lower right corner of the fence (Note that the fence might not enclose any area, i.e. it can be a line). If any person other than Alice and Bob is either inside the fence or on the fence, Alice will be sad.

Return the number of pairs of points where you can place Alice and Bob, such that Alice does not become sad on building the fence.

Note that Alice can only build a fence with Alice's position as the upper left corner, and Bob's position as the lower right corner. For example, Alice cannot build either of the fences in the picture below with four corners (1, 1), (1, 3), (3, 1), and (3, 3), because:

With Alice at (3, 3) and Bob at (1, 1), Alice's position is not the upper left corner and Bob's position is not the lower right corner of the fence.
With Alice at (1, 3) and Bob at (1, 1), Bob's position is not the lower right corner of the fence.

 

Example 1:


Input: points = [[1,1],[2,2],[3,3]]
Output: 0
Explanation: There is no way to place Alice and Bob such that Alice can build a fence with Alice's position as the upper left corner and Bob's position as the lower right corner. Hence we return 0. 
Example 2:


Input: points = [[6,2],[4,4],[2,6]]
Output: 2
Explanation: There are two ways to place Alice and Bob such that Alice will not be sad:
- Place Alice at (4, 4) and Bob at (6, 2).
- Place Alice at (2, 6) and Bob at (4, 4).
You cannot place Alice at (2, 6) and Bob at (6, 2) because the person at (4, 4) will be inside the fence.
Example 3:


Input: points = [[3,1],[1,3],[1,1]]
Output: 2
Explanation: There are two ways to place Alice and Bob such that Alice will not be sad:
- Place Alice at (1, 1) and Bob at (3, 1).
- Place Alice at (1, 3) and Bob at (1, 1).
You cannot place Alice at (1, 3) and Bob at (3, 1) because the person at (1, 1) will be on the fence.
Note that it does not matter if the fence encloses any area, the first and second fences in the image are valid.
 

Constraints:

2 <= n <= 1000
points[i].length == 2
-109 <= points[i][0], points[i][1] <= 109
All points[i] are distinct.

class Solution {

    static class Point {

        int x;
        int y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) {
                return true;
            }
            if (o == null || getClass() != o.getClass()) {
                return false;
            }
            Point point = (Point) o;
            return x == point.x && y == point.y;
        }

        @Override
        public int hashCode() {
            return Objects.hash(x, y);
        }
    }

    public int numberOfPairs(int[][] points) {
        Map<Integer, Integer> col = new HashMap<>();
        Map<Integer, Integer> row = new HashMap<>();
        Map<Point, int[]> coordinatesMap = new HashMap<>();

        for (int[] point : points) {
            int x = point[0];
            int y = point[1];
            col.put(x, 0);
            row.put(y, 0);
        }
        List<Integer> colKeys = new ArrayList<>(col.keySet());
        Collections.sort(colKeys);
        for (int i = 0; i < colKeys.size(); i++) {
            col.put(colKeys.get(i), i + 1);
        }
        List<Integer> rowKeys = new ArrayList<>(row.keySet());
        Collections.sort(rowKeys);
        for (int i = 0; i < rowKeys.size(); i++) {
            row.put(rowKeys.get(i), i + 1);
        }

        int nc = col.size() + 1;
        int nr = row.size() + 1;
        int[][] m = new int[nc][nr];
        int[][] prefixSum = new int[nc][nr];

        for (int[] point : points) {
            int x = point[0];
            int y = point[1];
            int c = col.get(x);
            int r = row.get(y);
            Point key = new Point(x, y);
            coordinatesMap.put(key, new int[] { c, r });
            m[c][r] = 1;
        }
        for (int i = 1; i < nc; i++) {
            for (int j = 1; j < nr; j++) {
                prefixSum[i][j] =
                    prefixSum[i - 1][j] +
                    prefixSum[i][j - 1] -
                    prefixSum[i - 1][j - 1] +
                    m[i][j];
            }
        }

        int ans = 0;
        Arrays.sort(points, (a, b) -> {
            if (a[0] == b[0]) {
                return Integer.compare(b[1], a[1]);
            }
            return Integer.compare(a[0], b[0]);
        });

        int n = points.length;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (points[i][1] >= points[j][1]) {
                    Point key1 = new Point(points[i][0], points[i][1]);
                    Point key2 = new Point(points[j][0], points[j][1]);
                    int[] coord1 = coordinatesMap.get(key1);
                    int[] coord2 = coordinatesMap.get(key2);
                    int c1 = coord1[0];
                    int r1 = coord1[1];
                    int c2 = coord2[0];
                    int r2 = coord2[1];
                    int cnt =
                        prefixSum[c2][r1] -
                        prefixSum[c1 - 1][r1] -
                        prefixSum[c2][r2 - 1] +
                        prefixSum[c1 - 1][r2 - 1];
                    if (cnt == 2) {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
}
