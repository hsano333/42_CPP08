#include "Span.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::pair;

/*
#include <stdio.h>
__attribute__((destructor)) void f(void){
    system("leaks Span");
}
*/
int main(void)
{
    {
        cout << "Test0" << endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "short:" << sp.shortestSpan() << std::endl;
        std::cout << "long:" << sp.longestSpan() << std::endl;
    }
    {
        cout << endl << "Test1" << endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        cout << "size:" << sp.getSize() << endl;
        std::cout << "short:" << sp.shortestSpan() << std::endl;
        std::cout << "long:" << sp.longestSpan() << std::endl;
    }
    {

        Span sp = Span(10);
        cout << endl << "Test 2" << endl << "sp size:" << sp.getSize() << endl;

        sp.addNumber(INT_MAX);
        sp.addNumber(12);
        sp.addNumber(12);
        sp.addNumber(INT_MIN);
        sp.addNumber(-12345);
        cout << "size:" << sp.getSize() << endl;
        std::cout << "short:" << sp.shortestSpan() << std::endl;
        std::cout << "long:" << sp.longestSpan() << std::endl;
        //std::multiset<int>::iterator begin_iter  = std::next(this->item->begin(), this->pos);
        //

        std::multiset<int> veint;
        veint.insert(10);
        veint.insert(15);
        veint.insert(-27);
        veint.insert(40);
        veint.insert(69);
        veint.insert(-29);

        cout << endl << "Test2 addNumbers:" << endl;
        sp.addNumbers(++veint.begin(), (--veint.end()));
        //sp.addNumbers();
        std::cout << "size:" << sp.getSize() << std::endl ;
        std::cout << "sort and print" << std::endl;
        sp.sort_print();
        std::cout << "short:" << sp.shortestSpan() << std::endl;
        std::cout << "long:" << sp.longestSpan() << std::endl;


        Span sp2 = Span(sp);
        sp2 = sp;
        cout << endl << "Test3 Original sp" << endl;
        sp.sort_print();
        cout << endl << "Test3 Copy Assignment sp2" << endl;
        sp2.sort_print();

        cout << endl << "Test4 Copy Constractor sp3" << endl;
        Span sp3 = Span(3);
        sp3 = sp;
        //sp3.test();
        sp3.sort_print();

        cout << endl << "Test5 sp4" << endl;
        Span *sp4 = new Span(4);
        sp4->addNumber(42);
        sp4->addNumbers();
        sp = *sp4;
        //sp4->test();
        sp4->sort_print();
        cout << "sp:" << endl;
        sp.sort_print();
        delete sp4;

        cout << endl << "Test6 sp5" << endl;
        Span sp5 = Span(0);
        try{
            sp5.addNumber(1);
            sp5.sort_print();
        } catch (std::length_error &e){
            cout << "Exception Test addNumber()" << endl;
            cout << e.what() << endl;
        } catch (std::exception &e){
            cout << e.what() << endl;
        }
        try{
            std::cout << "short:" << sp5.shortestSpan() << std::endl;
        } catch (std::out_of_range &e){
            cout << endl << "Exception Test shortestSpan()" << endl;
            cout << e.what() << endl;
        } catch (std::invalid_argument &e){
            cout << e.what() << endl;
        } catch (std::exception &e){
            cout << e.what() << endl;
        }
        try{
            std::cout << "long:" << sp5.longestSpan() << std::endl;
        } catch (std::out_of_range &e){
            cout << endl << "Exception Test longestSpan()" << endl;
            cout << e.what() << endl;
        } catch (std::invalid_argument &e){
            cout << e.what() << endl;
        } catch (std::exception &e){
            cout << e.what() << endl;
        }
    }
    {

        cout << endl << "Test7" << endl;
        try {
            Span sp = Span(UINT_MAX + 10u);
        } catch (std::invalid_argument &e){
            cout << endl << "Exception Test over UINT_MAX" << endl;
            cout << e.what() << endl;
        } catch (std::exception &e){
            cout << e.what() << endl;
        }
        try {
            Span sp = Span(-1);
        } catch (std::invalid_argument &e){
            cout << endl << "Exception Test minus value" << endl;
            cout << e.what() << endl;
        } catch (std::exception &e){
            cout << e.what() << endl;
        }
    }
    {
        cout << endl << "Test8" << endl;
        Span sp = Span(10000);
        sp.addNumbers();
        std::cout << "short:" << sp.shortestSpan() << std::endl;
        std::cout << "long:" << sp.longestSpan() << std::endl;
    }
    {
        cout << endl << "Test9" << endl;
        int size_max = 5;
        Span sp = Span(size_max);
        for (int i=0; i< size_max;i++)
        {
            sp.addNumber((double)rand()/RAND_MAX * INT_MAX);
            if (i >= 2)
            {
                std::cout << "short:" << sp.shortestSpan() << std::endl;
                std::cout << "long:" << sp.longestSpan() << std::endl;
            }
        }
        //sp.sort_print();
    }
}
