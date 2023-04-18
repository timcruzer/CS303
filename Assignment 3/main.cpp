#include <string>
#include <iostream>
#include "stack.h"
#include "queue.h"

using namespace std;

int main(){  
    string givenInfix, choice1, choice2, str;
    Infix object;
    queue myQueue;
    bool running = true;

    
    cout << "Welcome, would you like to:\n1. Convert infix to postfix\n2. Implemented stack\n";
    cin >> choice1;
    getline(cin, choice2);

    if (choice1 == "1") {
        cout << "Enter an infix expression: ";
        getline(cin, givenInfix);

        cout << "Your postfix expression is: " << object.convertToPostfix(givenInfix) << "\n";
    } 
        
    else if (choice1 == "2") {
        while (running == true){
            cout << "Welcome, would you like to:\n1. Insert a new element\n2. Remove front element\n3. Return front element\n4. Check if queue is empty\n5. Return number of elements\n6. Quit\n";
            cin >> choice2;
            switch (stoi(choice2)){
                case 1:
                    cout << "What string would you like to insert?: ";
                    cin >> str;
                    myQueue.insertRear(str);
                    break;
                case 2:
                    cout << "Removed " << myQueue.removeFront() << " from front of queue.\n";
                    break;
                case 3:
                    cout << "The front element is: " << myQueue.popFront() << "\n";
                    break;
                case 4:
                    if (myQueue.queueEmpty()){
                        cout << "Queue is empty.\n";
                    }
                    else{
                        cout << "Queue is not empty.\n";
                    }
                    break;
                case 5:
                    cout << "There are " << myQueue.queueSize() << " elements.\n";
                    break;
                case 6:
                    running = false;
                    break;
                default:
                    cout << "Please use one of the valid options\n";
            }
        }
    }
    
    else {
        cout << "Invalid answer";
    }
    
    return 0;
}
