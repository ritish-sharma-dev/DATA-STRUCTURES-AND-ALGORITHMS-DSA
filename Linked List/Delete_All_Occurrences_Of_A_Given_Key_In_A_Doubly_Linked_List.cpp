Link : https://www.naukri.com/code360/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list_8160461

// A doubly-linked list is a data structure that consists of sequentially linked nodes, and the nodes have reference to both the previous and the next nodes in the sequence of nodes.

// You’re given a doubly-linked list and a key 'k'.

// Delete all the nodes having data equal to ‘k’.

// Example:
// Input: Linked List: 10 <-> 4 <-> 10 <-> 3 <-> 5 <-> 20 <-> 10 and ‘k’ = 10
// Output: Modified Linked List: 4 <-> 3 <-> 5 <-> 20
// Explanation: All the nodes having ‘data’ = 10 are removed from the linked list.

// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// 7
// 10 4 10 3 5 20 10
// 10
// Sample Output 1:
// 4 3 5 20
// Explanation Of Sample Input 1:
// All the nodes having ‘data’ = 10 are removed from the linked list.


// Sample Input 2:
// 7
// 10 4 10 3 5 20 10
// 30
// Sample Output 2:
// 10 4 10 3 5 20 10
// Explanation Of Sample Input 2:
// The linked list does not have any node with ‘data’ = 30. So the linked list is unchanged.

// Expected Time Complexity:
// The expected time complexity is O(‘n’).

// Constraints:
// 0 <= ‘n’ <= 100000
// 1 <= ‘data’ in any node <= 10^9
// 1 <= ‘k’ <= 10^9

class Solution {
public:
    // BRUTE FORCE APPROACH
    // we can create a new linked list and add all the nodes from the original linked list that do not have data equal to 'k'. Finally, we will return the head of the new linked list.
    // TC : O(N)
    // SC : O(N)
    ListNode * deleteAllOccurrences(ListNode* head, int target) {
        if (head == NULL) return head;
        ListNode* dummyNode = new ListNode(-1);
        ListNode* prev = dummyNode;
        ListNode* temp = head;
        while (temp != NULL){
            if (temp->val != target){
                ListNode* newNode = new ListNode(temp->val,NULL,prev);
                prev->next = newNode;
                prev = newNode;
            }
            temp = temp->next;
        }
        return dummyNode->next;
    }



    // OPTIMAL APPROACH
    // we can use a dummy node to handle the edge case of deleting the head node. We will iterate through the linked list and whenever we find a node with data equal to 'k', we will delete it by adjusting the next and prev pointers of the adjacent nodes. Finally, we will return the next of the dummy node as the new head of the modified linked list.
    // TC : O(N)
    // SC : O(1)
    Node * deleteAllOccurrences(Node* head, int k) {
        if (head == NULL) return head;
        Node* dummyNode = new Node(-1);
        dummyNode->next = head;
        head->prev = dummyNode;

        Node* temp = head;
        while (temp != NULL){
            if (temp->data == k){
                Node* front = temp->next;
                temp->prev->next = temp->next;
                if (temp->next != NULL) temp->next->prev = temp->prev;
                delete temp;
                temp = front;
            } else{
                temp = temp->next;
            }
        }
        return dummyNode->next;                       
    }
    
     // OPTIMAL APPROACH
     // we can iterate through the linked list and whenever we find a node with data equal to 'k', we will delete it by adjusting the next and prev pointers of the adjacent nodes. We will also handle the edge case of deleting the head node by updating the head pointer accordingly. Finally, we will return the modified head of the linked list.
    // TC : O(N)
    // SC : O(1)
    Node * deleteAllOccurrences(Node* head, int k) {
        if (head == NULL) return head;

        Node* currNode = head;
        while (currNode != NULL){
            if (currNode->data == k){
                if (currNode == head){
                head = head->next;
                if (head) head->prev = NULL;
                currNode = head;
            }else{
                Node* prevNode = currNode->prev;
                Node* nextNode = currNode->next;
                if (prevNode) prevNode->next = nextNode;
                if (nextNode) nextNode->prev = prevNode;
                delete currNode;
                currNode = nextNode;
            }
            }else{
                currNode = currNode->next;
            }   
        }
        return head;

}

};