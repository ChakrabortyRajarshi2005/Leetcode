Find length of Loop
Difficulty: MediumAccuracy: 44.26%Submissions: 281K+Points: 4Average Time: 30m
Given the head of a linked list, determine whether the list contains a loop. If a loop is present, return the number of nodes in the loop, otherwise return 0.

Note: Internally, pos(1 based index) is used to denote the position of the node that tail's next pointer is connected to. If pos = 0, it means the last node points to null, indicating there is no loop. Note that pos is not passed as a parameter.

Examples:

Input: pos = 2,
   
Output: 4
Explanation: There exists a loop in the linked list and the length of the loop is 4.
Input: pos = 3,
   
Output: 3
Explanation: The loop is from 19 to 10. So length of loop is 19 → 33 → 10 = 3.
Input: pos = 0,
    
Output: 0
Explanation: There is no loop.
Constraints:
1 ≤ number of nodes ≤ 105
1 ≤ node->data ≤ 104
0 ≤ pos < number of nodes


class Solution {
  public:
    // Returns count of nodes present in loop.
    int countNodes(Node* node) {
        int res = 1;
        Node* curr = node;
        while (curr->next != node) {
            res++;
            curr = curr->next;
        }
        return res;
    }

    int lengthOfLoop(Node* head) {
        Node *slow = head, *fast = head;

        while (slow != nullptr && fast != nullptr && fast->next != nullptr) {

            slow = slow->next;
            fast = fast->next->next;

            // If slow and fast meet at
            // some point then there is a loop
            if (slow == fast)
                return countNodes(slow);
        }

        // Return 0 to indicate that
        // there is no loop
        return 0;
    }
};
