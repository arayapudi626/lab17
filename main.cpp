//COMSC 210 | Lab 17 | Anisha Rayapudi
#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

void output(Node *);
void addfront(Node *&head, float value);
void addback(Node * &head, float value);
void deleteNode(Node *&head, int pos);
void insertNode(Node *&head, int pos, float value);
void deleteEntire(Node *&head);

int main() {
    Node *head = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    cout << "Adding to head" << endl;
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        addfront(head, tmp_val);
    }
    cout << "List: \n";
    output(head);

    //adding a node to the back
    cout <<"Adding 1000 to the back" << endl;
    addback(head, 1000);
    cout << "List after adding to tail:\n ";
    output(head);

    // deleting a node
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;
    deleteNode(head, entry);
    cout << "List after deletion:\n ";
    output(head);

    // insert a node
    cout << "After which node to insert 10000? " << endl;
    count = 1;
    Node * current = head;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;
    insertNode(head, entry, 1000.0f);
    cout << "List after entry: \n";
    output(head);


    // deleting the linked list
     cout << "Deleting entire list: ";
     deleteEntire(head);
     output(head);

    return 0;
}

//outputs linked list
//argument: pointer to node object
//return: none
void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

//add node to front of list
//argument: pointer to node object, float value
//return: none
void addfront (Node *&head, float value) {
    Node *newVal = new Node;
    newVal->value = value;
    newVal->next = head;
    head=newVal;
}

//add node to back of list
//argument: pointer to node object, float value
//return: none
void addback (Node *&head, float value) {
    Node *newVal = new Node;
    newVal->value = value;
    newVal->next = nullptr;
    if (!head) {
        head = newVal;
        return;
    }
    Node *current = head;
    while (current->next){
        current = current->next;
    }
    current->next = newVal;
}

//deletes a node
//argument: pointer to node object, int position in list
//return: none
void deleteNode(Node *&head, int pos) {
    Node *current = head;
    Node *prev = head;
    for (int i = 0; i < (pos - 1); i++){
        if (i==0){
            current = current->next;
        }
        else{
            current = current->next;
            prev = prev->next;
        }
        if (current) {
            prev->next = current->next;
            delete current;
        }
    }
}

//inserts a node
//argument: pointer to node object, int position in list, float valye
//return: none
void insertNode(Node *&head, int pos, float value){
    Node *current = head;
    Node *prev = head;
    for (int i = 0; i < (pos-1); i++){
        if (i==0){
        current = current->next;
        }
        else{
            current = current->next;
            prev = prev->next;
        }
    }
    Node *n = new Node;
    n->value = 1000;
    n->next = current;
    prev->next = n;
}

//deletes entire list
//argument: pointer to node object
//return: none
void deleteEntire(Node *&head){
    Node * current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
}