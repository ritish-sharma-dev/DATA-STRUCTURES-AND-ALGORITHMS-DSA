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


bool searchInLL(Node* head, int key){
    Node* temp = head;
    while (temp != NULL){
        if (temp->val == key){
            return true;
        }
        temp = temp->next;
    }
    return false;
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

    int key;
    cout<<"Enter Key To Search: ";
    cin>>key;

    if (searchInLL(head,key)) cout<<"Key Found In LL"<<endl;
    else cout<<"Key Not Found In LL"<<endl;

    return 0;
}