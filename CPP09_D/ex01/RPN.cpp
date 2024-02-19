 #include "RPN.hpp"

//--------------------------------------------------------------------------//
//                      - CONSTRUCTORS & DESTRUCTORS -                            //
//--------------------------------------------------------------------------//

RPN::RPN(std::string str) : input(str) 
{

}

RPN::RPN(const RPN &r) 
{
    this->stack = r.stack;
    this->input = r.input;
}

RPN::~RPN()
{

}


//--------------------------------------------------------------------------//
//                               - OPERATORS -                              //
//--------------------------------------------------------------------------//

RPN& RPN::operator=(const RPN &r) 
{
    if (this != &r) 
    {
        this->input = r.input;
        this->stack = r.stack;
    }
    return (*this);
}

//--------------------------------------------------------------------------//
//                           - GETTERS & SETTERS -                          //
//--------------------------------------------------------------------------//

bool RPN::isValidChar(char c) const 
{
    if (isdigit(c) || c == '+' || c == '-' || c == '*' || c == '/')
        return (true);
    return (false);
}

//--------------------------------------------------------------------------//
//                           - MEMBER FUNCTIONS -                           //
//--------------------------------------------------------------------------//

float RPN::calculate(void) 
{
    int first;
    int second;

    for (size_t i = 0; i < input.length(); i += 2) 
    {
        if ((input[i + 1] != ' ' && input[i + 1] != '\0') || !isValidChar(input[i])) 
            throw std::invalid_argument("wrong input format");
        else if (isdigit(input[i]))
            stack.push(input[i] - 48);
        else 
        {
            if (stack.size() < 2)
                throw std::invalid_argument("wrong input format"); 
            second = stack.top();
            stack.pop();
            first = stack.top();
            stack.pop();
            stack.push(operation(first, second, input[i]));
        }
    }
    if (stack.size() != 1)
        throw std::invalid_argument("wrong input format");
    return (stack.top());
}

float RPN::operation(float first, float second, char token) const 
{
    switch (token)
    {
    case ('+') :
        return (first + second);
    case ('-') :
        return (first - second);
    case ('*') :
        return (first * second);
    case ('/') :
        if (second == 0)
            throw std::invalid_argument("wrong input format");
        return (first / second);
    default:
        throw std::invalid_argument("wrong input format");
    }
}