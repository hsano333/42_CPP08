#include "MutantStack.hpp"
#include <iostream>
#include <stack>
#include <deque>
#include <typeinfo> 

using std::cout;
using std::endl;

int main(void)
{
    {
        cout << "Test1 " << endl;
        MutantStack<int> mstack;
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
        std::list<int> mstack;
        //MutantStack<int, std::list<int>, std::list<int> > mstack;
        mstack.push_back(3);
        mstack.push_back(5);
        mstack.push_back(737);
        mstack.push_back(0);
        cout << "test2" << endl;
        
        std::list<int>::const_iterator it = mstack.begin();
        cout << "test3" << endl;
        std::list<int>::const_iterator ite = mstack.end();
        cout << "test4" << endl;
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
