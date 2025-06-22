# COMPILER DESIGN BASICS

COMPANY : CODTECH IT SOLUTION

NAME : RAHISH KUMAR

INTERN ID : CT04DF599

DOMAIN :  C++ PROGRAMMING

DURATION : 4 WEEKS

MENTOR : NEELA SANTHOSH

Task Overview:

This project implements a basic Arithmetic Expression Evaluator in C++ as part of the fundamental learning of Compiler Design concepts. It reads a mathematical expression from the user, processes it, and returns the correct result after evaluating it. The evaluator supports basic arithmetic operations (+, -, *, /) and handles operator precedence and parentheses properly.

This is a foundational tool that mimics the expression evaluation phase of a compiler, where parsing and interpretation of arithmetic expressions take place. This project is ideal for Computer Science students learning about stacks, expression parsing, and evaluation algorithms.

🎯 Objective
The main goal of this task is to:

Understand how compilers evaluate expressions using stacks.

Implement infix expression evaluation using operator precedence and parentheses.

Handle multi-digit numbers, nested brackets, and operator associativity.

Improve familiarity with error handling, token parsing, and runtime exceptions in C++.

⚙️ Key Features
Supports: +, -, *, / operators

Handles: Parentheses ( and )

Parses: Multi-digit numbers

Error detection:

Invalid characters

Mismatched parentheses

Division by zero

Incorrect expression format (e.g., missing operands/operators)

🧠 How It Works
Token Scanning: The expression is read character by character.

Stacks Used:

values stack stores integers (operands).

ops stack stores operators and parentheses.

Operator Precedence is maintained using a helper function. Multiplication and division have higher precedence than addition and subtraction.

Apply Operation: When a closing bracket or a lower-precedence operator is found, the top two values from the stack are popped, the operation is applied, and the result is pushed back.

Final Evaluation: After parsing the entire string, any remaining operations are processed.

🛡️ Exception Handling
The program uses C++ try-catch blocks and std::runtime_error to gracefully handle:

Division by zero

Invalid characters (like alphabets or symbols)

Unmatched or extra parentheses

Insufficient operands for operations

This not only prevents crashes but also improves user experience by giving helpful error messages.

📥 Sample Input/Output
yaml
Copy
Edit
Input  : (3 + 5) * 2 - 4 / 2
Output : Result = 14
vbnet
Copy
Edit
Input  : 10 / (5 - 5)
Output : Error: Division by zero.
yaml
Copy
Edit
Input  : (2 + 3
Output : Error: Mismatched parentheses.
📚 Topics Covered
Expression parsing

Stack-based evaluation

Operator precedence

Runtime error handling in C++

Basic compiler design principle (Syntax-directed evaluation)

🚀 How to Run
Compile the code:

bash
Copy
Edit
g++ -o evaluator evaluator.cpp
Run the program:

bash
Copy
Edit
./evaluator
🏁 Conclusion
This project helps in building a strong base in expression parsing, an essential topic in compiler construction and interpreters. It is also useful for practicing data structures like stacks and learning structured error handling in C++.

Feel free to fork, improve, or extend this to include support for:

Unary operators

Exponentiation

Variables or symbolic expressions

Postfix/prefix evaluation

OUTPUT-
![Image](https://github.com/user-attachments/assets/4181b664-aee0-464f-8b4f-9cf467b4ed83)
