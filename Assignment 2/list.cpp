#include <string>
#include <list>
#include <iostream>
#include "list.h"
using namespace std;

Single_Linked_List::Single_Linked_List(){

}

void Single_Linked_List::push_front(int value){
// push to front
    Node* newItem = new Node(value); 
    if (head == nullptr){
        tail = newItem; 
    }
    newItem->next = head; 
    head = newItem;
    listSize++;
    cout << "Added " << value << " to front of list.";
}

void Single_Linked_List::push_back(int value){
// push to back
    Node* newItem = new Node(value); 

    if (head == nullptr) { 
        head = newItem;
        tail = newItem;
    } else {
        tail->next = newItem; 
        tail = newItem; 
    }

    listSize++; 
    cout << "Added " << value << " to back of list.";
}

void Single_Linked_List::pop_front(){
// remove front
    Node* curr = head;
    curr = curr->next;
    cout << "Deleted first item " << curr->data;
    delete curr;
    listSize--;
}

void Single_Linked_List::pop_back(){
// remove back
    if (head == nullptr) {
        cout << "List is empty.";
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        tail = nullptr;
        listSize--;
        cout << "List is empty.";
    }

    Node* curr = head;
    while (curr->next != tail) {
        curr = curr->next;
    }

    cout << "Deleting last item, " << tail->data;
    delete tail;
    tail = curr;
    tail->next = nullptr;
    
}

void Single_Linked_List::front(){
// return front
    cout << "The item at the front of the list is: " << head->data;
}

void Single_Linked_List::back(){
// return back
    cout << "The item at the end of the list is: " << tail->data;
}

void Single_Linked_List::empty(){
// delete list
    Node* curr = head;
    Node* next;
    while (curr != nullptr){ 
        next = curr->next;
        delete curr;
        curr = next; 
    }
    head = nullptr;
    tail = nullptr;
    cout << "List is empty.";
}

void Single_Linked_List::insert(size_t index, const int item){
    if (index < 0 || index > listSize) {
        // index is out of bounds
        cout << "Index is out of bounds.";
    }

    Node* curr = head;
    Node* prev = nullptr;

    for (int i = 0; i < index; i++) { 
        prev = curr;
        curr = curr->next;
    }

    Node* newNode = new Node(item);

    if (prev == nullptr) {
        newNode->next = head;
        head = newNode;
    } else {
        prev->next = newNode;
        newNode->next = curr;
    }

    listSize++;
    cout << "Inserted item at given index.";
}

bool Single_Linked_List::remove(size_t index){
    if (head == nullptr) {
        cout << "List is empty.";
        return false;
    }

    if (index == 0) {
        Node* nodeToRemove = head;
        head = head->next;
        cout << "Deleted item " << nodeToRemove->data;
        delete nodeToRemove;
        return true;
    }

    Node* curr = head;
    Node* prev = nullptr; 
    int i = 0;

    while (curr != nullptr && i < index) { 
        prev = curr;
        curr = curr->next;
        i++;
    }

    if (curr == nullptr) { 
        cout << "Index out of bounds.";
    }

    prev->next = curr->next; 
    cout << "Deleting item " << curr->data << " at given index.";
    delete curr;
}

size_t Single_Linked_List::find(const int item){
    bool foundit = false;
    if (head == nullptr) {
        cout << "List is empty.";
    }
    Node* curr = head;
    int iterator = 0;

    while (curr != nullptr){ 
        if (curr->data == item){
            cout << "Found " << item << " at index " << iterator;
            foundit = true;
        }
        curr = curr->next;
        iterator++;
    }
    if (foundit == false){
        cout << "Item not found. List size is " << iterator;
    }
}
