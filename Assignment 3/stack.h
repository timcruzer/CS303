#include <string>
#include <stack>

using namespace std;

class Infix{
    public:
        
        bool isOperator(char input); // see if operator
        bool isOperand(char input); // see if operand
        bool greaterOrEqual(char operand1, char operand2); // compare priorities
        
        int priority(char operand); // see which number for priority

        string convertToPostfix(string infix); // convert to postfix


    private:
        string infix, postfix;
};
