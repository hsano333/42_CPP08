#ifndef MUTANTSTACK_T
#define MUTANTSTACK_T

#include "MutantStack.hpp"
#include <algorithm>

template <typename T>
std::ostream& operator<<(std::ostream& os, const MutantStack<T>& f);
//template <typename T>
template <typename T>
std::ostream& operator<<(std::ostream& os, MutantStack<T>& f);

template <typename T>
MutantStack<T>::MutantStack()
{
}

template <typename T>
MutantStack<T>::~MutantStack()
{
}


/*
template <typename T>
void MutantStack<T>::mypush(iterator iter)
{
    this->push(*iter);
}
*/

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &stack)
{
    for_each(stack.begin(), stack.end(), this->push);
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack &stack)
{
    for_each(this->begin(), this->end(), this->pop);
    for_each(stack.begin(), stack.end(), this->push);
    return (*this);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    std::deque<int> *deque = reinterpret_cast<std::deque<int>* > (this);
    //this->iterator.pos = reinterpret_cast<uintptr_t>(&(deque[0]));
    return (reinterpret_cast<MutantStack<T>::iterator& >(deque[0]));
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    //return (reinterpret_cast<MutantStack<T>::iterator>(&this->top()));
    std::deque<int> *deque = reinterpret_cast<std::deque<int>* > (this);
    //this->iterator.pos = reinterpret_cast<uintptr_t>(&(deque[0]));
    return (reinterpret_cast<MutantStack<T>::iterator& >(deque[deque->size()-1]));
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const MutantStack<T>& stack)
{
    os << stack;
    return (os);
}
template <typename T>
std::ostream& operator<<(std::ostream& os, MutantStack<T>& stack)
{
    os << stack;
    return (os);
}

/*
template <typename T>
MutantStack<T>::iterator::iterator()
{
}

template <typename T>
MutantStack<T>::iterator::~iterator()
{
}

template <typename T>
MutantStack<T>::iterator::iterator(const iterator & iter)
{
    this = iter;
}

template <typename T>
typename MutantStack<T>::iterator& MutantStack<T>::iterator::operator=(const iterator & iter)
{
    this = iter;
    return (*this);
}

template <typename T>
typename MutantStack<T>::iterator& MutantStack<T>::iterator::operator++()
{
}

template <typename T>
typename MutantStack<T>::iterator& MutantStack<T>::iterator::operator++(const iterator iter)
{
}

template <typename T>
typename MutantStack<T>::iterator& MutantStack<T>::iterator::operator--()
{
}

template <typename T>
typename MutantStack<T>::iterator& MutantStack<T>::iterator::operator--(const iterator iter)
{
}

template <typename T>
bool MutantStack<T>::iterator::operator!=(const iterator &iter)
{
}

template <typename T>
MutantStack<T>& MutantStack<T>::iterator::operator*()
{
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const MutantStack<T>& f)
{
    os << std::string("test");
    return (os);
}
template <typename T>
std::ostream& operator<<(std::ostream& os, MutantStack<T>& f)
{
    os << std::string("test");
    return (os);
}
*/
/*
template <typename Iter, typename T>
iterator<Iter, T>::iterator()
{
}
*/

#endif
