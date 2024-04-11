#include "span.hpp"

int main()
{
    try
    {
        Span span(5);

        span.addNumber(18);
        span.addNumber(129);
        span.addNumber(43);
        span.addNumber(-13);
        span.addNumber(1);
        span.printAll();
        std::cout << "Shortest Span: " << span.shortestSpan() << std::endl;
        std::cout << "Longtest Span: " << span.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << std::endl;

    try
    {
        Span span(0);

        span.addNumber(0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << std::endl;

    try
    {
        Span span(1);

        span.addNumber(42);
        std::cout << "Shortest Span: " << span.shortestSpan() << std::endl;
        std::cout << "Longtest Span: " << span.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << std::endl;

    try
    {
        Span span(2);

        span.addNumber(1);
        span.addNumber(2);
        span.addNumber(3);
        std::cout << "Shortest Span: " << span.shortestSpan() << std::endl;
        std::cout << "Longtest Span: " << span.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << std::endl;

    try
    {
        Span span(20, 300);

        span.printAll();
        std::cout << "Shortest Span: " << span.shortestSpan() << std::endl;
        std::cout << "Longtest Span: " << span.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << std::endl;

    try
    {
        Span span(10000, 999999999);

        std::cout << "Shortest Span: " << span.shortestSpan() << std::endl;
        std::cout << "Longtest Span: " << span.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

}