#include <iostream>
#include <stack>
#include <cctype>
#include <string>
#include <stdexcept>
using namespace std;

// Function to define operator precedence
int precedence(char op) {
    if(op == '+'||op == '-') return 1;
    if(op == '*'||op == '/') return 2;
    return 0;
}

// Function to perform arithmetic operations
int applyOp(int a, int b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if(b == 0) throw runtime_error("Error: Division by zero.");
            return a / b;
    }
    return 0;
}

// Function to evaluate the expression
int evaluate(const string& expression) {
    stack<int> values;
    stack<char> ops;

    for(int i = 0; i < expression.length(); i++) {
        if(expression[i] == ' ') continue;

        // If current token is '(', push it to ops
        if(expression[i] == '(') {
            ops.push(expression[i]);
        }

        // If number, extract full number
        else if(isdigit(expression[i])) {
            int val = 0;
            while(i < expression.length() && isdigit(expression[i])) {
                val = (val * 10) + (expression[i] - '0');
                i++;
            }
            values.push(val);
            i--; // Adjust index
        }

        // If closing bracket, solve entire bracket
        else if(expression[i] == ')') {
            while(!ops.empty() && ops.top() != '(') {
                int val2 = values.top(); values.pop();
                int val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            if(!ops.empty()) ops.pop(); // Remove '('
            else throw runtime_error("Error: Mismatched parentheses.");
        }

        // If operator
        else if(expression[i] == '+' || expression[i] == '-' ||
                expression[i] == '*' || expression[i] == '/') {
            while(!ops.empty() && precedence(ops.top()) >= precedence(expression[i])) {
                int val2 = values.top(); values.pop();
                int val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            ops.push(expression[i]);
        }

        // Invalid character
        else {
            throw runtime_error(string("Error: Invalid character '") + expression[i] + "'.");
        }
    }

    // Final evaluation
    while(!ops.empty()) {
        if(values.size() < 2)
            throw runtime_error("Error: Invalid expression.");
        int val2 = values.top(); values.pop();
        int val1 = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(applyOp(val1, val2, op));
    }

    if(values.size() != 1)
        throw runtime_error("Error: Invalid expression.");

    return values.top();
}

int main() {
    string expr;
    cout << "Enter an arithmetic expression : ";
    getline(cin, expr);

    try {
        int result = evaluate(expr);
        cout << "Result = " << result << endl;
    } catch(const exception& e) {
        cerr << e.what() << endl;
    }

    return 0;
}

