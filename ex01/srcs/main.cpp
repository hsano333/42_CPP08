#include "Span.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::pair;

int main(void)
{

    /*
    cout << "test No.1" << endl;
    std::multiset<int> tmp;
    tmp.insert(1);
    cout << "test No.2" << endl;
    std::multiset<int>::iterator ite = tmp.begin();
    cout << "test No.3" << endl;
    --ite;
    cout << "test No.4" << endl;
    --ite;
    cout << "test No.5" << endl;
    --ite;
    */


    {
        cout << "Test1" << endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
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
        //std::multiset<int>::iterator begin_iter  = std::next(this->item->begin(), this->pos);
        std::multiset<int>::iterator end_iter = sp.end();
        end_iter--;
        end_iter--;
        end_iter--;

        std::multiset<int> veint;
        veint.insert(10);
        veint.insert(15);
        veint.insert(27);
        veint.insert(40);

        sp.addNumbers(++veint.begin(), (--veint.end()));
        //sp.addNumbers();
        std::cout << "size:" << sp.getSize() << std::endl ;
        std::cout << "sort and print" << std::endl;
        sp.sort_print();
        std::cout << "short:" << sp.shortestSpan() << std::endl;
        std::cout << "long:" << sp.longestSpan() << std::endl;


        Span sp2 = Span(sp);
        sp2 = sp;
        cout << endl << "Test3 sp2" << endl;
        sp2.sort_print();

        cout << endl << "Test4 sp3" << endl;
        Span sp3 = Span(3);
        sp3 = sp;
        //sp3.test();
        sp3.sort_print();

        cout << endl << "Test5 sp4" << endl;
        Span *sp4 = new Span(4);
        sp4->addNumbers();
        sp = *sp4;
        //sp4->test();
        sp4->sort_print();
        sp.sort_print();
        delete sp4;
        sp.sort_print();

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
            cout << "Exception Test shortestSpan()" << endl;
            cout << e.what() << endl;
        } catch (std::exception &e){
            cout << e.what() << endl;
        }
        try{
            std::cout << "long:" << sp5.longestSpan() << std::endl;
        } catch (std::out_of_range &e){
            cout << "Exception Test longestSpan()" << endl;
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
            e.what();
        }
        try {
            Span sp = Span(-1);
        } catch (std::invalid_argument &e){
            e.what();
        }
    }
    {
        cout << endl << "Test8" << endl;
        Span sp = Span(100000);
        sp.addNumbers();
        std::cout << "short:" << sp.shortestSpan() << std::endl;
        std::cout << "long:" << sp.longestSpan() << std::endl;
        size_t cnt = 0;
        cout << "cnt:" << cnt << endl;
    }
    {
        cout << endl << "Test9" << endl;
        int size_max = 5;
        Span sp = Span(size_max);
        for (int i=0; i< size_max;i++)
        {
            sp.addNumber((double)rand()/RAND_MAX * INT_MAX);
            if (i>2)
            {
                std::cout << "short:" << sp.shortestSpan() << std::endl;
                std::cout << "long:" << sp.longestSpan() << std::endl;
            }
        }
        //sp.sort_print();
    }
    //system("leaks Span");
}
