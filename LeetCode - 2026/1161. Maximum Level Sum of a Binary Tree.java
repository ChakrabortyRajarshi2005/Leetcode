1161. Maximum Level Sum of a Binary Tree
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

Return the smallest level x such that the sum of all the values of nodes at level x is maximal.

 

Example 1:


Input: root = [1,7,0,7,-8,null,null]
Output: 2
Explanation: 
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.
Example 2:

Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
Output: 2
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-105 <= Node.val <= 105class Solution {
    public void dfs(TreeNode node, int level, List<Integer> sumOfNodesAtLevel) {
        if (node == null) {
            return;
        }

        if (sumOfNodesAtLevel.size() == level) {
            sumOfNodesAtLevel.add(node.val);
        } else {
            sumOfNodesAtLevel.set(level, sumOfNodesAtLevel.get(level) + node.val);
        }

        dfs(node.left, level + 1, sumOfNodesAtLevel);
        dfs(node.right, level + 1, sumOfNodesAtLevel);
    }

    public int maxLevelSum(TreeNode root) {
        List<Integer> sumOfNodesAtLevel = new ArrayList<>();
        dfs(root, 0, sumOfNodesAtLevel);

        int maxSum = Integer.MIN_VALUE;
        int ans = 0;

        for (int i = 0; i < sumOfNodesAtLevel.size(); i++) {
            if (maxSum < sumOfNodesAtLevel.get(i)) {
                maxSum = sumOfNodesAtLevel.get(i);
                ans = i + 1;
            }
        }

        return ans;
    }
}
