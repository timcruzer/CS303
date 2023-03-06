#include <string>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) { // constructor
        data = value;
        next = nullptr;
    }

    ~Node() { // destructor
        delete next;
    }
};

class Single_Linked_List{
    public:
    void push_front(int value);
    void push_back(int value);
    void pop_front();
    void pop_back();
    void front();
    void back();
    void empty();

    void insert(size_t index, const int item);
    // insert item at position index
    
    bool remove(size_t index);
    // remove the item at position index, true if successful, false if not

    size_t find(const int item);
    // return the position of the first occurrence of item if it is found, return size if not found

    Single_Linked_List(); // constructor

    private:
    int listSize = 0;
    Node* head = nullptr;
    Node* tail = nullptr;
};
