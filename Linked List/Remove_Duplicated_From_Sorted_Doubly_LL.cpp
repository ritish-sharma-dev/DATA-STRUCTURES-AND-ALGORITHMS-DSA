// Problem statement
// A doubly-linked list is a data structure that consists of sequentially linked nodes, and the nodes have reference to both the previous and the next nodes in the sequence of nodes.

// You are given a sorted doubly linked list of size 'n'.

// Remove all the duplicate nodes present in the linked list.

// Example :
// Input: Linked List: 1 <-> 2 <-> 2 <-> 2 <-> 3
// Output: Modified Linked List: 1 <-> 2 <-> 3
// Explanation: We will delete the duplicate values ‘2’ present in the linked list.

// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1 :
// 5
// 1 2 2 2 3
// Sample Output 1 :
// 1 2 3
// Explanation For Sample Input 1 :
// We will delete the duplicate values ‘2’ present in the linked list.

// Sample Input 2 :
// 4
// 1 2 3 4
// Sample Output 2 :
// 1 2 3 4
// Explanation For Sample Input 2 :
// The list contains no duplicates, so the final list is unchanged.

// Expected time complexity :
// The expected time complexity is O('n').

// Constraints :
// 1 <= 'n' <= 10^5
// 1 <= 'data' in any node <= 10^6

// Time limit: 1 sec


/**
 * Definition of doubly linked list:
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this->data = data;
 *          this->prev = prev;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node * removeDuplicates(Node *head)
{
    // OPTIMAL APPROACH
    // we will maintain two pointers, one will point to the current node and the other will point to the next node. if the data of current node and the next node are same, then we will delete the next node and update the next pointer of current node to point to the next of next node. if the data of current node and the next node are different, then we will move both the pointers to the next nodes.
    // TC : O(n)
    // SC : O(1)
    if (head == NULL || head->next == NULL) return head;

    Node* curr = head;
    Node* front = curr->next;

    while (curr->next != NULL){
        if (curr->data == front->data){
            curr->next = front->next;
            if (front->next != NULL) front->next->prev = curr;
            delete front;
            front = curr->next;
        }else{
            curr = front;
            front = curr->next;
        }
    }
    return head;
}

// OPTIMAL APPROACH
// Two pointers approach
// we will maintain two pointers, one will point to current node and the other will point to the front node. If the data of current node and the front node are same, then we will update the front node of current node to point to the front of front node. If the data of current node and the front node are different, then current node next node value will be updated to front node value and we will move both the pointers to the next nodes. Finally, we will update the next pointer of current node to NULL.
// TC : O(n)
// SC : O(1)
Node * removeDuplicates(Node *head)
{
  if (head == NULL || head->next == NULL) return head;
   Node* i = head;
   Node* j = head->next;

   while (j != NULL){
       if (j->data != i->data){
           i->next->data = j->data;
           i = i->next;
       }
       j = j->next;
   }
   i->next = NULL;
   return head;
}


// OPTIMAL APPROACH
// Two pointers approach
// we will maintain two pointers, one will point to current node and the other will point to the front node. If the data of current node and the front node are same, then we will update the front node of current node to point to the front of front node. If the data of current node and the front node are different, then current node next node will change to front node and we will move both the pointers to the next nodes. Finally, we will update the next pointer of current node to NULL.
// TC : O(n)
// SC : O(1)
Node * removeDuplicates(Node *head)
{
   if (head == NULL || head->next == NULL) return head;
   Node* i = head;
   Node* j = head->next;

   while (j != NULL){
       if (j->data != i->data){
           i->next = j;
           j->prev = i;
           i = i->next;
       }
        j = j->next;
   }
   i->next = NULL;

   return head;
    
}

