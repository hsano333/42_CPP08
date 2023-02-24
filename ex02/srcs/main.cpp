#include "MutantStack.hpp"
#include <iostream>
#include <stack>
#include <deque>
#include <typeinfo> 

using std::cout;
using std::endl;

int main(void)
{
    /*
    {
        cout << "Test1 " << endl;
        MutantStack<int> mstack;
        std::stack<int> test_stack;
        std::list<int> list_stack;
        cout << "mastack type=" << typeid(mstack).name() << endl;
        if (typeid(mstack) == typeid(MutantStack<int>))
            cout << "MutantStack<int>:" << "True" << endl;
        if (typeid(test_stack) == typeid(static_cast<std::stack<int> >(mstack)))
            cout << "stack:" << "True" << endl;
        //if (typeid(mstack) == typeid(list_stack))
        if (typeid(list_stack) == typeid(reinterpret_cast<std::list<int>& >(mstack)))
            cout << "list:" << "True" << endl;
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
    */


    /*
    {
        cout << endl << "Test2 " << endl;
        MutantStack<int> mstack;
        mstack.push(INT_MAX);
        mstack.push(INT_MAX + 1u);
        mstack.push(INT_MIN);
        mstack.push(INT_MIN -1u);
        mstack.push(0);

        MutantStack<int>::reverse_iterator it = mstack.rbegin();
        MutantStack<int>::reverse_iterator ite = mstack.rend();
        for(; it != ite; ++it)
        {
            std::cout << "ite= " << *it << endl;
        }

        cout << endl << "Test2 " << endl;
        MutantStack<int> mstack2 = MutantStack<int>(mstack);
        mstack2.pop();
        mstack2.pop();
        cout <<  "mstack:" << endl;
        it = mstack.rbegin();
        ite = mstack.rend();
        for(; it != ite; ++it)
        {
            std::cout << "ite= " << *it << endl;
        }
        cout <<  endl << "mstack2:" << endl;
        it = mstack2.rbegin();
        ite = mstack2.rend();
        for(; it != ite; ++it)
        {
            std::cout << "ite= " << *it << endl;
        }

        cout << endl << "Test3 " << endl;
        MutantStack<int> mstack3;
        mstack3 = mstack;
        mstack.pop();
        cout <<  "mstack:" << endl;
        it = mstack.rbegin();
        ite = mstack.rend();
        for(; it != ite; ++it)
        {
            std::cout << "ite= " << *it << endl;
        }
        cout <<  endl << "mstack3:" << endl;
        it = mstack3.rbegin();
        ite = mstack3.rend();
        for(; it != ite; ++it)
        {
            std::cout << "ite= " << *it << endl;
        }
    }
    */
    {
        cout << "Test4:list " << endl;
        MutantStack<int> mstack;
        mstack.push_back(5);
        mstack.push_back(17);
        std::cout << mstack.front() << std::endl;
        mstack.pop_back();
        std::cout << mstack.size() << std::endl;
        cout << "test1" << endl;
        mstack.push_back(3);
        mstack.push_back(5);
        mstack.push_back(737);
        mstack.push_back(0);
        cout << "test2" << endl;
        
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        cout << "test3" << endl;
        ++it;
        --it;
        cout << "test4" << endl;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            std::cout << *ite << std::endl;
            ++it;
        }
        std::list<int> s(mstack);
    }
    //system("leaks  Mutated_abomination");
    return 0;
}
