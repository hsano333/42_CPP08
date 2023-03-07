#include "MutantStack.hpp"
#include <iostream>
#include <stack>
#include <deque>
#include <typeinfo> 

using std::cout;
using std::endl;

#include <stdio.h>
__attribute__((destructor)) void f(void){
    system("leaks Mutated_abomination");
}

int main(void)
{
    {
        cout << endl << "Test1 " << endl;
        MutantStack<int> mstack;
        //std::stack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }

    {
        cout << endl << "Test2 " << endl;
        MutantStack<int> mstack;
        mstack.push(0);
        mstack.push(1);
        mstack.push(2);
        mstack.push(3);
        mstack.push(4);
        mstack.push(INT_MAX);
        mstack.push(INT_MAX + 1u);
        mstack.push(INT_MIN);
        mstack.push(INT_MIN -1u);
        mstack.push(5);

        MutantStack<int>::reverse_iterator it = mstack.rbegin();
        MutantStack<int>::reverse_iterator ite = mstack.rend();
        for(; it != ite; ++it)
        {
            std::cout << "mstack value= " << *it << endl;
        }

        cout << endl << "Test3 " << endl;
        MutantStack<int> mstack2 = MutantStack<int>(mstack);
        mstack2.pop();
        mstack2.pop();
        it = mstack2.rbegin();
        ite = mstack2.rend();
        for(; it != ite; ++it)
        {
            std::cout << "mstack2 value= " << *it << endl;
        }

        cout << endl << "Test4 " << endl;
        MutantStack<int> mstack3;
        mstack3 = mstack;
        mstack.pop();
        it = mstack.rbegin();
        ite = mstack.rend();
        for(; it != ite; ++it)
        {
            std::cout << "mstack value= " << *it << endl;
        }
        it = mstack3.rbegin();
        ite = mstack3.rend();
        for(; it != ite; ++it)
        {
            std::cout << "mstack3 value= " << *it << endl;
        }
    }
    {
        cout << "Test5:list " << endl;
        //std::list<int> mstack;
        MutantStack<int, std::list<int>, std::list<int> > mstack;
        mstack.push_back(5);
        mstack.push_back(17);
        std::cout << mstack.back() << std::endl;
        mstack.pop_back();
        std::cout << mstack.size() << std::endl;
        mstack.push_back(3);
        mstack.push_back(5);
        mstack.push_back(737);
        mstack.push_back(0);
        MutantStack<int, std::list<int>, std::list<int> >::iterator it = mstack.begin();
        MutantStack<int, std::list<int>, std::list<int> >::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::list<int> s(mstack);
    }
    return 0;
}
