Link : https://www.naukri.com/code360/problems/find-pair-with-a-given-sum-in-a-doubly-linked-list_1164172

// Problem statement
// A doubly-linked list is a data structure that consists of sequentially linked nodes, and the nodes have reference to both the previous and the next nodes in the sequence of nodes.

// You are given a sorted doubly linked list of size 'n', consisting of distinct positive integers, and a number 'k'.

// Find out all the pairs in the doubly linked list with sum equal to 'k'.

// Example :
// Input: Linked List: 1 <-> 2 <-> 3 <-> 4 <-> 9 and 'k' = 5

// Output: (1, 4) and (2, 3)

// Explanation: There are 2 pairs in the linked list having sum 'k' = 5.
// Detailed explanation ( Input/output format, Notes, Images )
// Sample input 1:
// 5
// 1 2 3 4 9
// 5

// Sample output 1
// 2
// 1 4
// 2 3
// Explanation for sample input 1 :
// There are 2 pairs in the linked list having sum equal to 'k' (= 5).

// Sample input 2:
// 5
// 1 10 11 12 27
// 7
// Sample output 2:
// 0
// Explanation for sample output 2
// There is no pair in the linked list with sum equal to 'k' (= 7).

// Expected time complexity :
// The expected time complexity is O('n').

// Constraints:
// 2 <= 'n' <= 10 ^ 4
// 1 <= 'data' in any node <= 10 ^ 4
// 1 <= 'k' <= 10 ^ 4

// 'data' in every node is distinct.

// Time limit: 1 second


// Brute force approach : Two nested loops
// We can use two nested loops to find the pairs with the given sum in the doubly
// TC : O(n^2)
// SC : O(n)
vector<pair<int, int>> findPairs(Node* head, int k)
{
    vector <pair<int, int>> v;
    Node* i = head;
    while (i != NULL){
        Node* j = i->next;
        while(j != NULL){
            if (i->data + j->data == k){
                v.push_back({i->data, j->data});
            }
            j = j->next;
        }
        i = i->next;
    }

    return v;
    
}

// Optimized approach : Two pointer approach
// We can use two pointer approach to find the pairs with the given sum in the doubly linked list. We can initialize two pointers, one pointing to the head of the linked list and the other pointing to the tail of the linked list. We can then move the pointers towards each other until they meet. If the sum of the values at the two pointers is less than 'k', we can move the left pointer to the right. If the sum is greater than 'k', we can move the right pointer to the left. If the sum is equal to 'k', we can add the pair to our result and move pointers towards each other.
// TC : O(n + n/2) = O(n)
// SC : O(n/2) = O(n)
vector<pair<int, int>> findPairs(Node* head, int k)
{

    vector <pair<int, int>> v;

    Node* start = head;
    Node* end = head;
    while(end->next != NULL){
        end = end->next;
    }

    while (start != end){
        if (start->data + end->data < k){
            start = start->next;
        }else if (start->data + end->data > k){
            end = end->prev;
        }else{
            v.push_back({start->data, end->data});
            start = start->next;
        }
    }

    return v;
}
