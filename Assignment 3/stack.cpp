#include <string>
#include <stack>
#include <iostream>
#include "stack.h"

using namespace std;

bool Infix::isOperator(char input){
    // see if operator
    if(input == '+' || input == '-' || input == '*' || input == '/' || input == '^' ) {
        return true;
    }
    else{
        return false;  
    }
}

bool Infix::isOperand(char input){
    // see if operand
    if (input >= '0' && input <= '9'){
        return true;  
    }
    else if (input >= 'A' && input <= 'Z'){
        return true;
    }
    else if (input >= 'a' && input <= 'z'){
        return true;
    }
    else{
        return false; 
    }
}

bool Infix::greaterOrEqual(char operand1, char operand2){
    // compare priorities
    int priority1 = priority(operand1);
    int priority2 = priority(operand2);
    
    if (priority1 == priority2){
        if (operand1 == '^'){
            return false;
        }
        return true;
    }
    return (priority1 > priority2 ? true : false);
}

int Infix::priority(char operand){
    // lowest priority
    if(operand == '+' || operand == '-'){
        return 1;
    }
    // mid priority
    if (operand == '*' || operand == '/'){
        return 2;
    }
    // highest priority
    if(operand == '^'){
        return 3;
    }
    return 0; 
}

string Infix::convertToPostfix(string infix){
    // :(
    stack <char> S; 
    string postfix = ""; 
    char ch; 
    
    S.push( '(' );
    infix += ')';  
    
    for(int i = 0; i<infix.length(); i++){
        ch = infix[i];  
        
        if(ch == ' '){ // skip if statement is blank
            continue;  
        } 
        else if(ch == '('){ // push if parenthesis open
            S.push(ch);  
        }
        else if(isOperand(ch)){ 
            postfix += ch;
        }
        else if (isOperator(ch)){ 
            while(!S.empty() && greaterOrEqual(S.top(), ch)){ 
                postfix += S.top(); // add top of stack to postfix
                S.pop(); // pop top
            }
            S.push(ch); 
        }
        else if (ch == ')'){ // if closed, not empty and closed parenthesis
            while (!S.empty() && S.top() != '('){ 
                postfix += S.top(); // add top of stack to postfix
                S.pop(); // pop top
            }
            S.pop();
        }
    }
    return postfix; 
}
