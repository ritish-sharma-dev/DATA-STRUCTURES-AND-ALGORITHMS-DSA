// LEETCODE 2807 - Insert Greatest Common Divisor in Linked List


// BRUTE FORCE APPROACH
// I have taken two pointers, node1 and node2 which will point to the current node and the next node . After this i will find the GCD of the values of node1 and node2 and create a node with the value of GCD and insert it in between the node1 and node2 and move the pointers to the next nodes and repeat the precess until the node2 becomes null. Finally, I will return the head of the linked list.
// TC : O(n * m)
// AS : O(1)
// SC : O(1) (not counting gcd nodes space)
class Solution {
    int findGCD(ListNode node1, ListNode node2) {
        int maxNodeValue = Math.max(node1.val, node2.val);
        int GCD = 1;
        for (int i = maxNodeValue; i > 0; i--) {
            if (node1.val % i == 0 && node2.val % i == 0) {
                GCD = i;
                break;
            }
        }
        return GCD;
    }

    public ListNode insertGreatestCommonDivisors(ListNode head) {
        if (head.next == null) return head;

        ListNode node1 = head;
        ListNode node2 = head.next;
        while (node2 != null) {
            int GCD = findGCD(node1, node2);
            ListNode newNode = new ListNode(GCD);
            node1.next = newNode;
            newNode.next = node2;
            node1 = node2;
            node2 = node1.next;
        }

        return head;
    }
}


// OPTIMIZED APPROACH
// I have used the Euclidean algorithm to find the GCD of two numbers. The Euclidean algorithm is based on the principle that the GCD of two numbers also divides their difference. So, I will keep replacing the larger number with the remainder of the division of the larger number by the smaller number until one of the numbers becomes zero. The non-zero number at that point will be the GCD of the original two numbers. and the rest of the process is same as the brute force approach.
// n is the length of LL and  a and b are adjacent nodes value
// TC : O(n * log(min(a, b)))
// AS : O(1)
// SC : O(1) (not counting gcd nodes space)
class Solution {
    int findGCD(int a, int b) {
       if (a == 0) return b;
       else if (b == 0) return a;

       if (a > b) a = a % b;
       else b = b % a;
       return findGCD(a, b);
    }

    public ListNode insertGreatestCommonDivisors(ListNode head) {
        if (head.next == null) return head;

        ListNode node1 = head;
        ListNode node2 = head.next;
        while (node2 != null) {
            int GCD = findGCD(node1.val, node2.val);
            ListNode newNode = new ListNode(GCD);
            node1.next = newNode;
            newNode.next = node2;
            node1 = node2;
            node2 = node1.next;
        }

        return head;
    }
}