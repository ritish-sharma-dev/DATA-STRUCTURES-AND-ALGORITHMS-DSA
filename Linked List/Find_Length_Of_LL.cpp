#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int val;
    Node* next;

    Node(int val, Node * next){
        this->val = val;
        this->next = next;
    }

    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

Node* convertArrayToLL(vector <int> &array){
    Node* head = new Node(array[0],NULL);
    Node* mover = head;
    for (int i=1; i<array.size(); i++){
        Node* temp = new Node(array[i],NULL);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int lengthOfLL(Node* head){
    Node* temp = head;
    int count = 0;
    while (temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

int main(){
    int size;
    cout<<"Enter Size Of Array: ";
    cin>>size;

    vector <int> array(size,0);

    cout<<"Enter values: ";
    for (int i=0; i<size; i++){
        cin>>array[i];
    }

    Node* head = convertArrayToLL(array);
    
    cout<<"Length Of LL: ";
    cout<<lengthOfLL(head)<<endl;

    return 0;
}