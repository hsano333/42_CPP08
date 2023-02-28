
#include "easyfind.hpp"
#include <map>
#include <list>
#include <set>
//#include <array>
#include <deque>
//#include <forward_list>
#include <queue>
#include <iostream>
#include <typeinfo>
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
    vector<int> container(10);
    //list<int> container(10);
    //deque<int> container(10);
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

    cout << "init container" << endl;
    std::for_each(container.begin(), container.end(), insert);
    std::for_each(container.begin(), container.end(), print);


    int search = 43;
    cout << "search:" << search << endl;
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

    return (0);
}
