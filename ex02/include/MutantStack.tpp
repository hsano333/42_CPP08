#ifndef MUTANTSTACK_T
#define MUTANTSTACK_T

#include "MutantStack.hpp"
#include <algorithm>

template <typename T>
std::ostream& operator<<(std::ostream& os, const MutantStack<T>& f);
//template <typename T>
template <typename T>
std::ostream& operator<<(std::ostream& os, MutantStack<T>& f);

//template <typename T>
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

    return (this->c.begin());
    //typename std::deque<T>::iterator deque_iterator = this->c.begin();
    //return static_cast<typename MutantStack<T>::iterator>(deque_iterator);
    //return reinterpret_cast<typename MutantStack<T>::iterator>(deque_iterator);
    //return dynamic_cast<typename MutantStack<T>::iterator>(deque_iterator);
    //return (static_cast<typename MutantStack<T>::iterator>(this->c.begin()));
    //return *(reinterpret_cast<MutantStack<T>::iterator*>(&(this->c.begin())));
    //return (static_cast<MutantStack<T>::iterator>(this->c.begin()));
    //return (this->c.begin());
    //std::deque<T> deque = reinterpret_cast<std::deque<T> > (this);
    //return (reinterpret_cast<MutantStack<T>::iterator>(&this->top()));
    //std::deque<T> *deque = reinterpret_cast<std::deque<T>* > (this->c.begin());
    //std::deque<T> *deque = reinterpret_cast<std::deque<T>* > (c);
    //this->iterator.pos = reinterpret_cast<uintptr_t>(&(deque[0]));
    //return (&(deque[0]));
    //return (reinterpret_cast<MutantStack<T>::iterator& >(&(deque[0])));
    //return (dynamic_cast<MutantStack<T>::iterator& >(deque->begin()));
    //uintptr_t tmp = reinterpret_cast<uintptr_t& >(&(deque->begin()));
    //
    //std::cout << "begin test:" << deque->top() << std::endl;
    //std::cout << "begin test:" << *(deque->begin()) << std::endl;
    //return (reinterpret_cast<MutantStack<T>::iterator& >(deque[deque->size()-1]));
    //return (reinterpret_cast<MutantStack<T>::iterator* >(&deque->begin()));
    //iterator tmp = (reinterpret_cast<MutantStack<T>::iterator& >((deque->begin())));
    //iterator tmp = (dynamic_cast<MutantStack<T>::iterator* >((deque->begin())));
    //return (tmp);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    //return (this->c.begin());
    return (this->c.end());
    //return (reinterpret_cast<MutantStack<T>::iterator>(this->c.end()));
    //std::deque<T> *deque = reinterpret_cast<std::deque<T>* > (this);
    //this->iterator.pos = reinterpret_cast<uintptr_t>(&(deque[0]));
    //return (reinterpret_cast<MutantStack<T>::iterator& >(deque[deque->size()-1]));
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

template <typename T>
std::ostream& operator<<(std::ostream& os, const typename MutantStack<T>::iterator& ite)
{
    os << ite;
    return (os);
}
template <typename T>
std::ostream& operator<<(std::ostream& os, typename MutantStack<T>::iterator& ite)
{
    os << ite;
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
