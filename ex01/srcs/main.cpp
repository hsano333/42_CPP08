#include "Span.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::pair;

int main(void)
{
    Span sp = Span(10);
    cout << "sp size:" << sp.getSize() << endl;

    //std::vector<int> ve(10);
    std::vector<pair<int, bool> > ve(10);
    ve[0] = std::make_pair(1,true);
    ve[1] = std::make_pair(2,true);
    ve.push_back(std::make_pair(3,true));
    //std::vector<pair<int,bool> >::iterator ite = ve.begin();
    //cout << "size:" << ve.size() <<  endl;

    sp.addNumber(INT_MAX);
    sp.addNumber(INT_MIN);
    sp.addNumber(12);
    sp.addNumber(5);
    sp.addNumber(-12345);
    cout << "size:" << sp.getSize() << endl;
    //std::vector<int>::iterator begin_iter  = std::next(this->item->begin(), this->pos);
    std::vector<std::pair<int, bool> >::iterator end_iter = sp.end();
    end_iter--;
    end_iter--;
    end_iter--;


    std::vector<int> veint;

    veint.push_back(10);
    veint.push_back(15);
    veint.push_back(27);
    veint.push_back(40);

    sp.addNumbers(veint.begin(), (veint.end()));
    //sp.addNumbers();
    std::cout << "size:" << sp.getSize() << std::endl ;
    std::cout << "sort and print" << std::endl;
    sp.sort_print();
    std::cout << "short:" << sp.shortestSpan() << std::endl;
    std::cout << "long:" << sp.longestSpan() << std::endl;
}
