#include "Node.h"
using namespace std;

//Declare starting (Head) node
struct Node* head = nullptr;

//Insert node at start
void ListNode::insertNode(int n) {
    struct Node* newNode = new Node;
    newNode->number = n;
    newNode->next = head;
    head = newNode;
}

//Delete node from start
void ListNode::deleteItem() {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    cout << head->number << " is removed." << endl;
    head = head->next;
}

//Traverse/ display all nodes (print items)
void ListNode::display() {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    struct Node* temp = head;
    while (temp != nullptr) {
        cout << temp->number << " ";
        temp = temp->next;
    }
    cout << endl;
}