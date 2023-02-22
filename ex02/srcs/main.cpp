#include "MutantStack.hpp"
#include <iostream>
#include <stack>
#include <deque>

using std::cout;
using std::endl;


template <typename T>
//class TestStack : virtual public std::stack<T> , virtual public std::deque<T>
//class TestStack : virtual public std::stack<T>
class TestStack : public std::stack<T>
//class TestStack :  public std::deque<T>
{
    public:
        TestStack();
        uintptr_t con;
        void Test();

};

template <typename T>
TestStack<T>::TestStack()
{
    //this->con = this->C;
    //this->con = reinterpret_cast<uintptr_t>(C);
    //stack<T>();
}

template <typename T>
void TestStack<T>::Test()
{
    std::cout << "Test():" << *(this->c.begin()) << endl;
    //this->con = this->C;
    //this->con = reinterpret_cast<uintptr_t>(C);
    //stack<T>();
}

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

    //std::stack<int> s;
    TestStack<int> s;
    s.push(5);
    s.push(10);
    s.push(15);
    s.push(20);

    s.Test();
    /*
    std::stack<int> &d = reinterpret_cast<std::deque<int>& >(s.c);
    //std::deque<int> &d = reinterpret_cast<std::deque<int>& > (s.c);
    d.push_back(105);
    d.push_back(110);
    d.push_back(115);
    std::cout << d[0] << std::endl;
    std::cout << d[1] << std::endl;
    std::cout << d[2] << std::endl;
    std::cout << d[3] << std::endl;
    std::cout << d[4] << std::endl;
    std::cout << d[5] << std::endl;
    std::cout << d[6] << std::endl;
    std::cout << d[7] << std::endl;
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
    //MutantStack<int>::iterator it = mstack.begin();
    //MutantStack<int>::iterator ite = mstack.end();
    MutantStack<int>::reverse_iterator it = mstack.rbegin();
    MutantStack<int>::reverse_iterator ite = mstack.rend();
    //MutantStack<int>::const_reverse_iterator it = mstack.begin();
    //MutantStack<int>::const_reverse_iterator ite = mstack.end();
    cout << "test0:" << *it << endl;
    cout << "test1:" << *ite << endl;
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
    //std::stack<int> s(mstack);
    return 0;
}
