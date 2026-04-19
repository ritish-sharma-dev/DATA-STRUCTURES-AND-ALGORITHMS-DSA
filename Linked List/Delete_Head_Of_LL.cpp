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

Node* deleteHeadFromALL(Node* head){
    Node* temp = head; 
    head = head->next;
    delete temp;
    return head;
}

int main()
{
    vector <int> arr = {1, 2, 3, 4, 5 };

    Node* head = convertArrayToLL(arr);
    traversalInALL(head);

    head = deleteHeadFromALL(head);
    traversalInALL(head);
    return 0;
}