3330. Find the Original Typed String I
Solved
Easy
Topics
premium lock icon
Companies
Hint
Alice is attempting to type a specific string on her computer. However, she tends to be clumsy and may press a key for too long, resulting in a character being typed multiple times.
Although Alice tried to focus on her typing, she is aware that she may still have done this at most once.
You are given a string word, which represents the final output displayed on Alice's screen.
Return the total number of possible original strings that Alice might have intended to type.

Example 1:
Input: word = "abbcccc"
Output: 5
Explanation:
The possible strings are: "abbcccc", "abbccc", "abbcc", "abbc", and "abcccc".
Example 2:
Input: word = "abcd"
Output: 1
Explanation:
The only possible string is "abcd".
Example 3:
Input: word = "aaaa"
Output: 4


Constraints:
1 <= word.length <= 100
word consists only of lowercase English letters.


  
class Solution {
    public int possibleStringCount(String word) {
        // StringBuilder sb = new StringBuilder("");
        // for(int i=0;i<word.length();i++){
        //     int counter = 1;
        //     if(word.charAt(i)!=word.charAt(i+1)){
        //         sb.append(word.charAt(i));
        //         String str = String.valueOf(counter);
        //         sb.append(str);
        //     }
        // }'l9'

        // int possibleCombination  = 0;
        // for(int i=1;i<sb.length();i+=2){
        //     int num = Integer.parseInt(sb.charAt(i)) ;
        //     if( num > 1){
        //         possibleCombination += num -  1;
        //     }
        // }
        
        // return possibleCombination+1;


        if (word == null || word.length() == 0) return 0;

        StringBuilder sb = new StringBuilder("");
        int counter = 1;

        for (int i = 1; i < word.length(); i++) {
            if (word.charAt(i) == word.charAt(i - 1)) {
                counter++;
            } else {
                sb.append(word.charAt(i - 1));
                sb.append(counter);
                counter = 1;
            }
        }

        // Append the last character and its count
        sb.append(word.charAt(word.length() - 1));
        sb.append(counter);

        int possibleCombination = 0;

        // for (int i = 1; i < sb.length(); i += 2) {
        //     int num = Integer.parseInt(String.valueOf(sb.charAt(i)));
        //     if (num > 1) {
        //         possibleCombination += num - 1;
        //     }
        // }

        // return possibleCombination + 1;

         for (int i = 1; i < sb.length(); ) {
            // sb.charAt(i) is a digit, possibly more than one digit
            StringBuilder numBuilder = new StringBuilder();
            while (i < sb.length() && Character.isDigit(sb.charAt(i))) {
                numBuilder.append(sb.charAt(i));
                i++;
            }

            int num = Integer.parseInt(numBuilder.toString());
            if (num > 1) {
                possibleCombination += (num - 1);
            }

            // Skip to the next number (next even index in original logic)
            i++; // Skip the next character (the letter)
        }

        return possibleCombination + 1;
    }
}
