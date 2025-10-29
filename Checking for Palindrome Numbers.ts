Checking for Palindrome Numbers
EASY

Tags

Companies

Hints
Given an integer x, return true if x is a palindrome, and false otherwise.

Example 1:
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
Constraints
2^31 <= x <= 2^31 - 1

class Solution {
  isPalindrome(x: number): boolean {
    if (x < 0) return false;
    const str = x.toString();
    const reversed = str.split('').reverse().join('');
    return str === reversed;
  }
}

const sol = new Solution();
console.log(sol.isPalindrome(121));
console.log(sol.isPalindrome(-121));
console.log(sol.isPalindrome(10));
