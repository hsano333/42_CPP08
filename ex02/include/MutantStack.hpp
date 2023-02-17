#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

#include <stack>
#include <iterator>
#include <iostream>

//template <typename T>
template <typename T>
class MutantStack : public std::stack<T>
{
    private:
    public:
        //template <typename Iter>
        class iterator : public std::iterator<std::forward_iterator_tag, T>
        {
            public:
                iterator();
                ~iterator();
                iterator(const iterator & iter);
                iterator& operator=(const iterator & iter);
                iterator& operator++();
                iterator& operator++(iterator iter);
                iterator& operator--();
                iterator& operator--(iterator iter);
                bool operator!=(const iterator &iter);
                MutantStack& operator*();
        };
        MutantStack();
        MutantStack(const MutantStack &stack);
        MutantStack& operator=(const MutantStack &stack);
        virtual ~MutantStack();

        iterator begin(void);
        iterator end(void);

        //static Iter iterator;
         //iterators;

};

template <typename T>
std::ostream& operator<<(std::ostream& os, const MutantStack<T>& f);
//template <typename T>
template <typename T>
std::ostream& operator<<(std::ostream& os, MutantStack<T>& f);


/*
//template <typename T>
template <typename T>
MutantStack<T>::MutantStack()
{
}

template <typename T>
MutantStack<T>::~MutantStack()
{
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &stack)
{
    *this = stack;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack &stack)
{
    *this = stack;
    return (*this);
}

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
