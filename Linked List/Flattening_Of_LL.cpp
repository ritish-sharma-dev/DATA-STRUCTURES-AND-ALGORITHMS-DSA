// LINK OF QUESTION : https://takeuforward.org/data-structure/flattening-a-linked-list

class Solution {
public:
    // BRUTE FORCE APPROACH
    // TC : O(n*m*log(n*m)) where n is the number of head nodes and m is the maximum number of child nodes in any linked list
    // SC : O(n*m) for storing the values in a vector
    ListNode* flattenLinkedList(ListNode* &head) {
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        while (temp1 != NULL){
            while (temp2->child != NULL){
                temp2 = temp2->child;
            }
            temp2->child = temp1->next;
            temp1 = temp1->next;
            temp2 = temp2->child;
        }

        vector <int> v;
        ListNode* mover = head;
        while (mover != NULL){
            v.push_back(mover->val);
            mover = mover->child;
        }

        sort(v.begin(),v.end());

        mover = head;
        int i = 0;
        while (mover != NULL){
            mover->val = v[i];
            mover = mover->child;
            i++;
        }

        return head;
    }
};