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
MutantStack<T>::MutantStack(const MutantStack &stack) : std::stack<T>()
{
    MutantStack::const_iterator begin = stack.begin();
    MutantStack::const_iterator end = stack.end();
    for(; begin != end; begin++)
    {
        this->push(*begin);
    }
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack &stack)
{
    if (*this != stack)
    {
        //MutantStack::iterator it;
        MutantStack::const_iterator begin = this->begin();
        MutantStack::const_iterator end = this->end();
        for(; begin != end; begin++)
        {
            this->pop();
        }
        begin = stack.begin();
        end = stack.end();
        for(; begin != end; begin++)
        {
            this->push(*begin);
        }

    }
    return (*this);
}


template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return (this->c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
    return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
    return (this->c.end());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
    return (this->c.rbegin());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
    std::cout << "rend No.1" << std::endl;
    return (this->c.rend());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const
{
    return (this->c.rbegin());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const
{
    std::cout << "rend No.2" << std::endl;
    return (this->c.rend());
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
