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
    this->pos = reinterpret_cast<uintptr_t>(&iter);
    //this = iter;
}

template <typename T>
typename MutantStack<T>::iterator& MutantStack<T>::iterator::operator=(const iterator & iter)
{
    this->pos = reinterpret_cast<uintptr_t&>(iter);
    //this = iter;
    return (*this);
}

template <typename T>
typename MutantStack<T>::iterator& MutantStack<T>::iterator::operator++()
{
    typename std::deque<T>::iterator *iter = reinterpret_cast<typename std::deque<T>::iterator *>(this->pos);
    return *(reinterpret_cast<MutantStack<T>::iterator *>(++iter));
}

template <typename T>
typename MutantStack<T>::iterator& MutantStack<T>::iterator::operator++(int n)
{
    n = 0;
    //MutantStack<T>::iterator &iter = reinterpret_cast<std::deque<int>::iterator &>(this->pos);
    typename std::deque<T>::iterator *iter = reinterpret_cast<typename std::deque<T>::iterator *>(this->pos);
    //return (iter++);
    return *(reinterpret_cast<MutantStack<T>::iterator *>(iter++));
}

template <typename T>
typename MutantStack<T>::iterator& MutantStack<T>::iterator::operator--()
{
    typename std::deque<T>::iterator *iter = reinterpret_cast<typename std::deque<T>::iterator *>(this->pos);
    //MutantStack<T>::iterator &iter = reinterpret_cast<std::deque<int> &>(this->pos);
    //return (--this);
    return *(reinterpret_cast<MutantStack<T>::iterator *>(--iter));
}

template <typename T>
typename MutantStack<T>::iterator& MutantStack<T>::iterator::operator--(int n)
{
    n = 0;
    //MutantStack<T>::iterator &iter = reinterpret_cast<std::deque<int> &>(this->pos);
    typename std::deque<T>::iterator *iter = reinterpret_cast<typename std::deque<T>::iterator *>(this->pos);
    return *(reinterpret_cast<MutantStack<T>::iterator *>(iter--));
    //return (this--);
}

template <typename T>
bool MutantStack<T>::iterator::operator!=(const iterator &iter)
{
    const typename std::deque<T>::iterator &iter_tmp = reinterpret_cast<const typename std::deque<T>::iterator &>(iter);
    typename std::deque<T>::iterator *tmp = reinterpret_cast<typename std::deque<T>::iterator *>(this->pos);
    return ((*tmp != iter_tmp));
}

template <typename T>
T& MutantStack<T>::iterator::operator*() const
{
    typename std::deque<T>::iterator* this_tmp = reinterpret_cast<typename std::deque<T>::iterator *>(this->pos);
    //iterator *ite = reinterpret_cast<iterator*>(this_tmp);
    return (**this_tmp);
}

#endif
