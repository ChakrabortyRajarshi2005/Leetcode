Smallest window containing all characters
Difficulty: HardAccuracy: 30.19%Submissions: 183K+Points: 8Average Time: 30m
Given two strings s and p. Find the smallest substring in s consisting of all the characters (including duplicates) of the string p. Return empty string in case no such substring is present.
If there are multiple such substring of the same length found, return the one with the least starting index.

Examples:

Input: s = "timetopractice", p = "toc"
Output: "toprac"
Explanation: "toprac" is the smallest substring in which "toc" can be found.
Input: s = "zoomlazapzo", p = "oza"
Output: "apzo"
Explanation: "apzo" is the smallest substring in which "oza" can be found.
Input: s = "zoom", p = "zooe"
Output: ""
Explanation: No substring is present containing all characters of p.
Constraints: 
1 ≤ s.length(), p.length() ≤ 106
s, p consists of lowercase english letters
class Solution {
    public static String smallestWindow(String s, String p) {

        int len1 = s.length();
        int len2 = p.length();

        if (len1 < len2) return "";

        int[] countP = new int[256];
        int[] countS = new int[256];

        // Store occurrence of characters of P
        for (int i = 0; i < len2; i++) countP[p.charAt(i)]++;

        int start = 0, start_idx = -1, min_len = Integer.MAX_VALUE;
        int count = 0;

        for (int j = 0; j < len1; j++) {
            char currChar = s.charAt(j);

            // Count occurrence of characters of string S
            countS[currChar]++;

            // If S's char matches with P's char, increment count
            if (countP[currChar] > 0 && countS[currChar] <= countP[currChar]) {
                count++;
            }

            // If all characters are matched
            if (count == len2) {

                // Try to minimize the window
                char startChar;
                while (countS[startChar = s.charAt(start)] > countP[startChar] ||
                       countP[startChar] == 0) {
                    if (countS[startChar] > countP[startChar]) {
                        countS[startChar]--;
                    }
                    start++;
                }

                // Update window size
                int len = j - start + 1;
                if (min_len > len) {
                    min_len = len;
                    start_idx = start;
                }
            }
        }

        if (start_idx == -1) return "";

        return s.substring(start_idx, start_idx + min_len);
    }
}
