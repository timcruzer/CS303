//Tim Cruz
//tcc3t7@umsystem.edu
//CS303
//Assignment 2
//3/06/2023
#include "list.h"
#include "company.h"
#include <iostream>
using namespace std;


int main(){
    Single_Linked_List list;
    string userChoice, userValue, userValue2; 
    bool running = true;
  
    cout << "Welcome, choose your option below:\n";
    cout << "1. Linked List\n" "2. Employee Data\n"; // choose which one
    cin >> userChoice;
    if (userChoice == "1"){
        while (running == true){
        
            cout << "\n-----\nWhat would you like to do?\n1. Push front.\n2. Push back.\n3. Pop front.\n4. Pop back.\n5. Front.\n6. Back.\n7. Empty list.\n8. Insert at index.\n9. Remove at index.\n10. Find value.\n0. Quit.\nSelect: ";
            cin >> userChoice;

        
            switch (stoi(userChoice)){
                case 1:
                    cout << "Enter value to push to front: ";
                    cin >> userValue;
                    list.push_front(stoi(userValue));
                    break;
                
                case 2:
                    cout << "Enter value to push to back: ";
                    cin >> userValue;
                    list.push_back(stoi(userValue));
                    break;

                case 3:
                    list.pop_front();
                    break;

                case 4:
                    list.pop_back();
                    break;

                case 5:
                    list.front();
                    break;
                
                case 6:
                    list.back();
                    break;

                case 7:
                    list.empty();
                    break;

                case 8:
                    cout << "Enter index you want to insert at: ";
                    cin >> userValue;
                    cout << "Enter value to place at index: ";
                    cin >> userValue2;
                    list.insert(stol(userValue), stoi(userValue2));
                    break;

                case 9:
                    cout << "Enter index you want to remove: ";
                    cin >> userValue;
                    list.remove(stol(userValue));
                    break;

                case 10:
                    cout << "Enter value you want to find: ";
                    cin >> userValue;
                    list.find(stoi(userValue));
                    break;

                case 0:
                    running = false;
                    break;

                default:
                    cout << "Invalid number given.";
                    break;
            }
        }
    }
    if (userChoice == "2"){
        while (running == true){

            string firstname, lastname, hoursworked, hourlyrate;

            cout << "Enter employee's first name: ";
            cin >> firstname;
            cout << "Enter employee's last name: ";
            cin >> lastname;
            cout << "Enter employee's hours worked this week: ";
            cin >> hoursworked;
            cout << "Enter employee's hourly rate: ";
            cin >> hourlyrate;
            int numworked = stoi(hoursworked);
            int numrate = stoi(hourlyrate);
            cout << "Is employee a 1. professional or 2. nonprofessional?: ";
            cin >> userChoice;
            if (userChoice == "1"){
                // Professional
                Employee* person = new ProfessionalEmployee(firstname, lastname, numworked, numrate);
                cout << "-----\n";
                int moneymade = person->weeklySalary(numworked, numrate); 
                cout << "\n-----\n";
                person->healthCare(moneymade);
                cout << "\n-----\n";
                person->vacationDays(numworked);
                running = false;
            }
            if (userChoice == "2"){
                // Nonprofessional
                Employee* person = new NonProfessionalEmployee(firstname, lastname, numworked, numrate);
                cout << "-----\n";
                int moneymade = person->weeklySalary(numworked, numrate);
                cout << "\n-----\n";
                person->healthCare(moneymade);
                cout << "\n-----\n";
                person->vacationDays(numworked);
                running = false;
                
            }
            else{
                cout << "Invalid input. Try again.";
            }
        }
    }
    
    return 0;
}
