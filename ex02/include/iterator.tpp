#ifndef ITERATOR_H
#define ITERATOR_H

#include <MutantStack.hpp>


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
/*
template <typename Iter, typename T>
iterator<Iter, T>::iterator()
{
}
*/


#endif
