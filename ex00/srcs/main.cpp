
#include "easyfind.hpp"
#include <map>
#include <list>
#include <set>
#include <deque>
#include <queue>
//#include <array>
//#include <forward_list>
#include <iostream>
//#include <typeinfo>
//#include <multiset>

using std::vector;
using std::multiset;
using std::set;
using std::list;
//using std::array;
using std::deque;
//using std::forward_list;
using std::queue;
using std::endl;
using std::cout;
//using std::forward_list;


void insert(int& a)
{
    static int value = 0;

    value+=42;
    a = value;
}
void print(int& a)
{

    cout << a << endl;
}


/*
#include <stdio.h>
__attribute__((destructor)) void f(void){
    system("leaks easy_find");
}
*/

int main(void)
{
    queue<int> q_container;
    
    // C++11(not handle)
    //array<int, 10> container;
    //forward_list<int> container;
    
    //associative container(not handle)
    //set<int> container;
    //multiset<int> container;
    //map<int> container;
    
    //init queue
    q_container.push(42);
    q_container.push(43);
    q_container.push(44);
    q_container.push(45);
    q_container.push(46);
    const queue<int> q_const_container(q_container);

    cout << endl << "init container" << endl;
    vector<int> container(10);
    //list<int> container(10);
    //deque<int> container(10);
    std::for_each(container.begin(), container.end(), insert);
    std::for_each(container.begin(), container.end(), print);

    const vector<int> const_container = container;
    //const list<int> const_container(10);
    //const deque<int> const_container(10);
    

    int search = 42;
    cout << endl << "search:" << search << endl;
    try {
        easyfind(container, search);
        cout << search << " is exist in container" << endl;
    }catch(std::exception &e) {
        cout << "Container Error:not find." << endl;
        cout << e.what() << endl;
    }
    try {
        easyfind(q_container, search);
        cout << search << " is exist in queue" << endl;
    }catch(std::exception &e) {
        cout << "Queue Container Error:not find." << endl;
        cout << e.what() << endl;
    }
    try {
        easyfind(const_container, search);
        cout << search << " is exist in const_container" << endl;
    }catch(std::exception &e) {
        cout << "const Container Error:not find." << endl;
        cout << e.what() << endl;
    }
    try {
        easyfind(q_const_container, search);
        cout << search << " is exist in const_queue" << endl;
    }catch(std::exception &e) {
        cout << "const Queue Container Error:not find." << endl;
        cout << e.what() << endl;
    }

    return (0);
}
