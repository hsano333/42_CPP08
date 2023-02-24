#ifndef MUTANTSTACK_T
#define MUTANTSTACK_T

#include "MutantStack.hpp"
#include <algorithm>
#include <typeinfo>

using std::cout;
using std::endl;

template <typename T>
std::ostream& operator<<(std::ostream& os, const MutantStack<T>& f);
//template <typename T>
template <typename T>
std::ostream& operator<<(std::ostream& os, MutantStack<T>& f);

//template <typename T>
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
    MutantStack::iterator begin = stack.begin();
    MutantStack::iterator end = stack.end();
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
        MutantStack::iterator begin = this->begin();
        MutantStack::iterator end = this->end();
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
template <template <typename, typename> class Container>
void MutantStack<T>::Test(Container<T, std::deque<T> > &obj)
{
    cout << "Test():" << &obj << endl;
}

/*
template <typename T>
template <template <typename> class Container>
void MutantStack<T>::Test(Container<T> &obj)
{
    cout << "Test():" << &obj << endl;
}
*/

template <typename T>
//template <template <typename, typename> class Container>
template <template <typename> class Container>
void MutantStack<T>::Test(Container<T> &obj)
{
    cout << "Test():" << &obj << endl;
}

/*
template <typename T>
template <template <typename, typename> class Container>
void MutantStack<T>::Test(Container<T, std::deque<T> > &obj)
{
    cout << "Test():" << &obj << endl;
}
*/


template <typename T>
template <template <typename, typename> class Container>
typename MutantStack<T>::iterator MutantStack<T>::getBeginIte(Container<T, std::deque<T> > &obj)
{
    if (&obj == this)
        return (this->c.begin());
    return (this->c.begin());
}

template <typename T>
template <template <typename> class Container>
typename MutantStack<T>::iterator MutantStack<T>::getBeginIte(Container<T> &obj)
{
    if (&obj == this)
        return (this->begin());
    return (this->begin());
}

template <typename T>
template <template <typename, typename> class Container>
typename std::deque<T>::iterator MutantStack<T>::getEndIte(Container<T, std::deque<T> > &obj)
{
    if (&obj == this)
        return (this->c.end());
    return (this->c.end());
}
template <typename T>
template <template <typename> class Container>
typename std::deque<T>::iterator MutantStack<T>::getEndIte(Container<T> &obj)
{
    if (&obj == this)
        return (this->end());
    return (this->end());
}

/*
template <typename T>
template <template <typename, typename> class Container>
const typename MutantStack<T>::const_iterator MutantStack<T>::getBeginIte(Container<T, std::deque<T> > &obj) const
{
    if (&obj == this)
        return (this->c.begin());
    return (this->c.begin());
}
template <typename T>
template <template <typename, typename> class Container>
typename MutantStack<T>::const_iterator MutantStack<T>::getBeginIte(Container<T, std::allocator<T> > &obj) const
{
    if (&obj == this)
        return (this->begin());
    return (this->begin());
}

template <typename T>
template <template <typename, typename> class Container>
typename std::deque<T>::const_iterator MutantStack<T>::getEndIte(Container<T, std::deque<T> > &obj) const
{
    if (&obj == this)
        return (this->c.end());
    return (this->c.end());
}
template <typename T>
template <template <typename, typename> class Container>
typename std::deque<T>::const_iterator MutantStack<T>::getEndIte(Container<T, std::allocator<T> > &obj) const
{
    if (&obj == this)
        return (this->end());
    return (this->end());
}

template <class T, template <typename, typename> class Container, template <typename> class Ite>
typename Ite<T>::reverse_iterator getRBeginIte(Container<T, std::allocator<T> > &obj)
{
    return (obj.rbegin());
}

template <typename T>
template <template <typename, typename> class Container>
typename std::deque<T>::reverse_iterator MutantStack<T>::getRBeginIte(Container<T, std::deque<T> > &obj)
{
    if (&obj == this)
        return (this->c.rbegin());
    return (this->c.rbegin());
}
template <typename T>
template <template <typename, typename> class Container>
typename std::deque<T>::reverse_iterator MutantStack<T>::getRBeginIte(Container<T, std::allocator<T> > &obj)
{
    if (&obj == this)
        return (this->rbegin());
    return (this->rbegin());
}

template <typename T>
template <template <typename, typename> class Container>
typename std::deque<T>::reverse_iterator MutantStack<T>::getREndIte(Container<T, std::deque<T> > &obj)
{
    if (&obj == this)
        return (this->c.rend());
    return (this->c.rend());
}
template <typename T>
template <template <typename, typename> class Container>
typename std::deque<T>::reverse_iterator MutantStack<T>::getREndIte(Container<T, std::allocator<T> > &obj)
{
    if (&obj == this)
        return (this->rend());
    return (this->rend());
}

template <typename T>
template <template <typename, typename> class Container>
typename std::deque<T>::const_reverse_iterator MutantStack<T>::getRBeginIte(Container<T, std::deque<T> > &obj) const
{
    if (&obj == this)
        return (this->c.rbegin());
    return (this->c.rbegin());
}
template <typename T>
template <template <typename, typename> class Container>
typename std::deque<T>::const_reverse_iterator MutantStack<T>::getRBeginIte(Container<T, std::allocator<T> > &obj) const
{
    if (&obj == this)
        return (this->rbegin());
    return (this->rbegin());
}

template <typename T>
template <template <typename, typename> class Container>
typename std::deque<T>::const_reverse_iterator MutantStack<T>::getREndIte(Container<T, std::deque<T> > &obj) const
{
    if (&obj == this)
        return (this->c.rend());
    return (this->c.rend());
}
template <typename T>
template <template <typename, typename> class Container>
typename std::deque<T>::const_reverse_iterator MutantStack<T>::getREndIte(Container<T, std::allocator<T> > &obj) const
{
    if (&obj == this)
        return (this->rend());
    return (this->rend());
}
*/


template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    //this->Test(*this);
    return (getBeginIte(*this));
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return (getEndIte(*this));
}

/*
template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
    return (getBeginIte(*this));
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
    return (getEndIte(*this));
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
    return (getRBeginIte(*this));
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
    return (getREndIte(*this));
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const
{
    return (getRBeginIte(*this));
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const
{
    return (getREndIte(*this));
}
*/

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

#endif
