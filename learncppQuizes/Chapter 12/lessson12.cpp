#include <iostream>
#include <functional>

int getInteger()
{
    std::cout << "Enter a num: ";
    int num {};
    std::cin >> num;
    
    return num;
}

char getOperation()
{
   
   char input{};
   do 
   {
   std::cout << "Enter a valid operation (‘+’, ‘-‘, ‘*’, ‘/’)";
   std::cin >> input;
   }
   while (input != '+' && input != '-' && input != '*' && input != '/');
   return input;
}

int add(int x, int y)
{
    return x+y;
}
int subtract(int x, int y)
{
    return x-y;
}
int multiply(int x, int y)
{
    return x*y;
}
int divide(int x, int y)
{
    return x/y;
}

using ArithmeticFunction = std::function<int(int, int)>;

ArithmeticFunction getArithmeticFunction(char op)
{
    switch(op)
    {
        case '+': return &add;
        case '-': return &subtract;
        case '*': return &multiply;
        case '/': return &divide;
        default: std::cout << "Not valid.";
    }
    return nullptr;
}

int main()
{
    int number {getInteger()};
    char bruh {getOperation() };
    int num2 {getInteger()};
    
    ArithmeticFunction ff { getArithmeticFunction(bruh) };
    
    std::cout << ff(number, num2);
    return 0;
}
