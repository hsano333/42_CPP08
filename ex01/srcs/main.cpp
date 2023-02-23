#include "Span.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::pair;

int main(void)
{
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
        sp.addNumber(5);
        sp.addNumber(INT_MIN);
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
            cout << e.what() << endl;
        } catch (std::exception &e){
            cout << e.what() << endl;
        }

        try{
            std::cout << "short:" << sp5.shortestSpan() << std::endl;
        } catch (std::out_of_range &e){
            cout << e.what() << endl;
        } catch (std::exception &e){
            cout << e.what() << endl;
        }
        try{
            std::cout << "long:" << sp5.longestSpan() << std::endl;
        } catch (std::out_of_range &e){
            cout << e.what() << endl;
        } catch (std::exception &e){
            cout << e.what() << endl;
        }


    }
    //system("leaks Span");
}
