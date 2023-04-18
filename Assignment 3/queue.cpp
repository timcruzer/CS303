#include <string>
#include <iostream>
#include "queue.h"

using namespace std;

void queue::insertRear(string value){
    Node* newNode = new Node(value);

    if (queueEmpty() == true){ // if empty, set head and tail to new
        head = tail = newNode;
    }
    else{ // if not empty
        tail->next = newNode;
        tail = newNode;
    }
    queuesize++;
    cout << "Operation completed.\n";
}

string queue::popFront(){
    if (queueEmpty() == true){ // if empty
        cout << "Queue is empty. Cannot return data.";
    }
    else { 
        return head->data;
    }
}

string queue::removeFront(){
    string poppedData;
    if (queueEmpty() == true){
        cout << "Queue is empty. Cannot pop front.";
    }
    else { // move the variable to a temp and delete it
        poppedData = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        queuesize--;

        return poppedData;
    }
}

bool queue::queueEmpty(){
    return queuesize < 1; 
}

int queue::queueSize(){
    return queuesize;
}

queue::queue(){
    head = nullptr;
    tail = nullptr;
    queuesize = 0;
}
