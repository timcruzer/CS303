#include <string>

using namespace std;

class Node {
public:
    string data;
    Node* next;

    Node(string value) { // constructor
        data = value;
        next = nullptr;
    }

    ~Node() { // destructor
        delete next;
    }
};

class queue {
public:
    void insertRear(string value);
    string popFront(); // remove front value and subtract queue size
    string removeFront(); // remove front value
    bool queueEmpty(); // check if queue empty
    int queueSize(); // return size
    queue(); 

private:
    int queuesize;
    Node* head;
    Node* tail;
};
