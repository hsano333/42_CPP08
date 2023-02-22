#include "Span.hpp"
#include <iostream>

int main(void)
{
    Span sp = Span(10);

    //sp.addNumber(INT_MAX);
    //sp.addNumber(INT_MIN);
    sp.addNumbers();
    std::cout << "size:" << sp.getSize() << std::endl ;
    std::cout << "sort and print" << std::endl;
    sp.sort_print();
    std::cout << "short:" << sp.shortestSpan() << std::endl;
    std::cout << "long:" << sp.longestSpan() << std::endl;
}
