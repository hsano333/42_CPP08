#include "MutantStack.hpp"
#include <iostream>
#include <stack>
#include <deque>

using std::cout;
using std::endl;


template <typename T>
//class TestStack : virtual public std::stack<T> , virtual public std::deque<T>
class TestStack :  public std::deque<T>
{

};


int main(void)
{

    /*
    s.push_back(105);
    s.push_back(110);
    s.push_back(115);
    //s.push(5);
    //s.push(10);
    //s.push(15);
    //s.push(20);
    //cout << s.top() << endl;
    //s.pop();


    //std::deque<int> &d = dynamic_cast<std::deque<int>& > (s);
    std::deque<int> &d = reinterpret_cast<std::deque<int>& > (s);
    //cout << s.front() << endl;
    //cout << s.back() << endl;
    cout << d[0] << endl;
    cout << d[1] << endl;
    cout << d[2] << endl;
    */


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
    cout << "test:it:" << *it << ", " << &it << endl;
    cout << "test:ite:" << *ite << ", " << &ite << endl;
    ++it;
    cout << "test0:" << *it << endl;
    --it;
    cout << "test1:" << *it << endl;
    //while (it != ite)
    if (it != ite)
    {
        cout << "test2:" << *ite << endl;
        //cout << "test1" << endl;
        std::cout << *it << std::endl;
        ++it;
        cout << "test3:" << *it << endl;
    }
    std::stack<int> s(mstack);
    return 0;
}
