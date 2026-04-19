#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int val;
    Node* next;

    Node(int val, Node* next){
        this->val = val;
        this->next = next;
    }

    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

Node* convertArrayToLL(vector <int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i=0; i<arr.size()-1; i++){
        Node* temp = new Node(arr[i+1]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void traversalInALL(Node* head){
    if (head == NULL) cout<<head;
    Node* temp = head;
    while (temp != NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* DeleteKthNodeInALL(Node* head, int k){
    if (k==0 || head == NULL) return head;
    if (k==1){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }else{
        int count = 0;
        Node* temp = head;
        Node* prev = NULL;
        while (temp != NULL){
            count++;
            if(count == k){
                prev->next = prev->next->next;
                delete temp;
                break;
            }
            prev = temp;
            temp = temp->next;
        }
        return head;
    }
}

int main()
{
    vector <int> arr = {1,6,3,9};

    Node* head = convertArrayToLL(arr);
    traversalInALL(head);

    int k = 2;
    head = DeleteKthNodeInALL(head,k);
    traversalInALL(head);
    return 0;
}