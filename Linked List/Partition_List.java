// LEETCODE - 86. Partition List

// C++ CODE
//BRUTE FORCE APPROACH
// I have created a new linked list and first of all add all the nodes which are less than x and then add all the nodes which are greater than or equal to x. Finally, I will return the new linked list.
// TC : O(2n) = O(n)
// SC : O(n)
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* prev = dummyNode;

        ListNode* temp = head;
        while (temp != NULL){
            if (temp->val < x){
                ListNode* newNode = new ListNode(temp->val);
                prev->next = newNode;
                prev = newNode;
            }
            temp = temp->next;
        }

        temp = head;
        while (temp != NULL){
            if (temp->val >= x){
                ListNode* newNode = new ListNode(temp->val);
                prev->next = newNode;
                prev = newNode;
            }
            temp = temp->next;
        }

        return dummyNode->next;
    }
};


// BETTER APPROACH
// JAVA CODE
// I have created two dummy nodes, one for the nodes which are less than x and another for the nodes which are greater than or equal to x. Then I will traverse the original linked list and add the nodes to the respective dummy nodes. Finally, I will connect the two dummy nodes and return the new linked list.
// TC : O(3n) = O(n)
// SC : O(1)
class Solution {
    public ListNode partition(ListNode head, int x) {
        ListNode d1 = new ListNode(-1);
        ListNode p1 = d1;
        ListNode temp = head;
        while (temp != null && !(temp.val < x)) {
            temp = temp.next;
        }
        p1.next = temp;


        ListNode d2 = new ListNode(-1);
        ListNode p2 = d2;
        temp = head;
        while (temp != null && !(temp.val >= x)){
            temp = temp.next;
        }
        p2.next = temp;

        temp = head;
        while (temp != null){
            if (temp.val < x){
                p1.next = temp;
                p1 = temp;
            }else{
                p2.next = temp;
                p2 = temp;
            }
            temp = temp.next;
        }
        p1.next = d2.next;
        p2.next = null;

        return d1.next;
    }
}


// OPTIMAL APPROACH
// JAVA CODE
// I have created two dummy nodes, one for the nodes which are less than x and another for the nodes which are greater than or equal to x. Then I will traverse the original linked list and add the nodes to the respective dummy nodes. Finally, I will connect the two dummy nodes and return the new linked list.
// TC : O(n)
// SC : O(1)
class Solution {
    public ListNode partition(ListNode head, int x) {
        ListNode d1 = new ListNode(-1);
        ListNode p1 = d1;
        ListNode d2 = new ListNode(-1);
        ListNode p2 = d2;

        ListNode temp = head;
        while (temp != null) {
            if (temp.val < x) {
                p1.next = temp;
                p1 = temp;
            } else {
                p2.next = temp;
                p2 = temp;
            }
            temp = temp.next;
        }
        p1.next = d2.next;
        p2.next = null;

        return d1.next;
    }
}