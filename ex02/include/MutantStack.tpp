#ifndef MUTANTSTACK_T
#define MUTANTSTACK_T

#include "MutantStack.hpp"
#include <algorithm>
#include <typeinfo>

using std::cout;
using std::endl;

//template <typename T, class Iter, class Inherit>
template <typename T, class Iter, class Inherit>
std::ostream& operator<<(std::ostream& os, const MutantStack<T, Iter, Inherit>& f);
//template <typename T, class Iter, class Inherit>
template <typename T, class Iter, class Inherit>
std::ostream& operator<<(std::ostream& os, MutantStack<T, Iter, Inherit>& f);

//template <typename T, class Iter, class Inherit>
//template <typename T, class Iter, class Inherit>
template <typename T, class Iter, class Inherit>
MutantStack<T, Iter, Inherit>::MutantStack()
{
}

template <typename T, class Iter, class Inherit>
MutantStack<T, Iter, Inherit>::~MutantStack()
{
}


/*
template <typename T, class Iter, class Inherit>
void MutantStack<T, Iter, Inherit>::mypush(iterator iter)
{
    this->push(*iter);
}
*/

template <typename T, class Iter, class Inherit>
MutantStack<T, Iter, Inherit>::MutantStack(const MutantStack &stack) : std::stack<T>()
{
    MutantStack::iterator begin = stack.begin();
    MutantStack::iterator end = stack.end();
    for(; begin != end; begin++)
    {
        this->push(*begin);
    }
}

template <typename T, class Iter, class Inherit>
MutantStack<T, Iter, Inherit>& MutantStack<T, Iter, Inherit>::operator=(const MutantStack &stack)
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

template <typename T, class Iter, class Inherit>
template <template <typename, typename> class Container>
void MutantStack<T, Iter, Inherit>::Test(Container<T, Iter> &obj)
{
    cout << "Test():" << &obj << endl;
}

/*
template <typename T, class Iter, class Inherit>
template <template <typename> class Container>
void MutantStack<T, Iter, Inherit>::Test(Container<T> &obj)
{
    cout << "Test():" << &obj << endl;
}
*/

template <typename T, class Iter, class Inherit>
//template <template <typename, typename> class Container>
template <template <typename> class Container>
void MutantStack<T, Iter, Inherit>::Test(Container<T> &obj)
{
    cout << "Test():" << &obj << endl;
}

/*
template <typename T, class Iter, class Inherit>
template <template <typename, typename> class Container>
void MutantStack<T, Iter, Inherit>::Test(Container<T, Iter > &obj)
{
    cout << "Test():" << &obj << endl;
}
*/


template <typename T, class Iter, class Inherit>
template < template <typename, typename, typename> class Container>
typename MutantStack<T, Iter, Inherit>::iterator MutantStack<T, Iter, Inherit>::getBeginIte(Container<T, std::deque<T>, std::stack<T> > &obj)
{
    if (&obj == this)
        return (this->c.begin());
    return (this->c.begin());
}

template <typename T, class Iter, class Inherit>
template < template <typename, typename, typename> class Container>
typename MutantStack<T, Iter, Inherit>::iterator MutantStack<T, Iter, Inherit>::getBeginIte(Container<T, Iter, Inherit> &obj)
{
    if (&obj == this)
        return Iter::begin();
    return Iter::begin();
        //return *(reinterpret_cast<MutantStack<T, Iter, Inherit>* >(&(*std::list<T>::begin())));
    //return *(reinterpret_cast<MutantStack<T, Iter, Inherit>* >(&(*std::list<T>::begin())));
}

template <typename T, class Iter, class Inherit>
template < template <typename, typename, typename> class Container>
typename MutantStack<T, Iter, Inherit>::iterator MutantStack<T, Iter, Inherit>::getEndIte(Container<T, std::deque<T>, std::stack<T> > &obj)
{
    if (&obj == this)
        return (this->c.end());
    return (this->c.end());
}
template <typename T, class Iter, class Inherit>
template < template <typename, typename, typename> class Container>
typename MutantStack<T, Iter, Inherit>::iterator MutantStack<T, Iter, Inherit>::getEndIte(Container<T, Iter, Inherit> &obj)
{
    if (&obj == this)
        return Iter::end();
    return Iter::end();
}

/*
template <typename T, class Iter, class Inherit>
template <template <typename, typename> class Container>
const typename MutantStack<T, Iter, Inherit>::const_iterator MutantStack<T, Iter, Inherit>::getBeginIte(Container<T, Iter > &obj) const
{
    if (&obj == this)
        return (this->c.begin());
    return (this->c.begin());
}
template <typename T, class Iter, class Inherit>
template <template <typename, typename> class Container>
typename MutantStack<T, Iter, Inherit>::const_iterator MutantStack<T, Iter, Inherit>::getBeginIte(Container<T, std::allocator<T> > &obj) const
{
    if (&obj == this)
        return (this->begin());
    return (this->begin());
}

template <typename T, class Iter, class Inherit>
template <template <typename, typename> class Container>
typename Iter::const_iterator MutantStack<T, Iter, Inherit>::getEndIte(Container<T, Iter > &obj) const
{
    if (&obj == this)
        return (this->c.end());
    return (this->c.end());
}
template <typename T, class Iter, class Inherit>
template <template <typename, typename> class Container>
typename Iter::const_iterator MutantStack<T, Iter, Inherit>::getEndIte(Container<T, std::allocator<T> > &obj) const
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

template <typename T, class Iter, class Inherit>
template <template <typename, typename> class Container>
typename Iter::reverse_iterator MutantStack<T, Iter, Inherit>::getRBeginIte(Container<T, Iter > &obj)
{
    if (&obj == this)
        return (this->c.rbegin());
    return (this->c.rbegin());
}
template <typename T, class Iter, class Inherit>
template <template <typename, typename> class Container>
typename Iter::reverse_iterator MutantStack<T, Iter, Inherit>::getRBeginIte(Container<T, std::allocator<T> > &obj)
{
    if (&obj == this)
        return (this->rbegin());
    return (this->rbegin());
}

template <typename T, class Iter, class Inherit>
template <template <typename, typename> class Container>
typename Iter::reverse_iterator MutantStack<T, Iter, Inherit>::getREndIte(Container<T, Iter > &obj)
{
    if (&obj == this)
        return (this->c.rend());
    return (this->c.rend());
}
template <typename T, class Iter, class Inherit>
template <template <typename, typename> class Container>
typename Iter::reverse_iterator MutantStack<T, Iter, Inherit>::getREndIte(Container<T, std::allocator<T> > &obj)
{
    if (&obj == this)
        return (this->rend());
    return (this->rend());
}

template <typename T, class Iter, class Inherit>
template <template <typename, typename> class Container>
typename Iter::const_reverse_iterator MutantStack<T, Iter, Inherit>::getRBeginIte(Container<T, Iter > &obj) const
{
    if (&obj == this)
        return (this->c.rbegin());
    return (this->c.rbegin());
}
template <typename T, class Iter, class Inherit>
template <template <typename, typename> class Container>
typename Iter::const_reverse_iterator MutantStack<T, Iter, Inherit>::getRBeginIte(Container<T, std::allocator<T> > &obj) const
{
    if (&obj == this)
        return (this->rbegin());
    return (this->rbegin());
}

template <typename T, class Iter, class Inherit>
template <template <typename, typename> class Container>
typename Iter::const_reverse_iterator MutantStack<T, Iter, Inherit>::getREndIte(Container<T, Iter > &obj) const
{
    if (&obj == this)
        return (this->c.rend());
    return (this->c.rend());
}
template <typename T, class Iter, class Inherit>
template <template <typename, typename> class Container>
typename Iter::const_reverse_iterator MutantStack<T, Iter, Inherit>::getREndIte(Container<T, std::allocator<T> > &obj) const
{
    if (&obj == this)
        return (this->rend());
    return (this->rend());
}
*/


template <typename T, class Iter, class Inherit>
typename MutantStack<T, Iter, Inherit>::iterator MutantStack<T, Iter, Inherit>::begin()
{
    //this->Test(*this);
    return (getBeginIte(*this));
}

template <typename T, class Iter, class Inherit>
typename MutantStack<T, Iter, Inherit>::iterator MutantStack<T, Iter, Inherit>::end()
{
    return (getEndIte(*this));
}

/*
template <typename T, class Iter, class Inherit>
typename MutantStack<T, Iter, Inherit>::const_iterator MutantStack<T, Iter, Inherit>::begin() const
{
    return (getBeginIte(*this));
}

template <typename T, class Iter, class Inherit>
typename MutantStack<T, Iter, Inherit>::const_iterator MutantStack<T, Iter, Inherit>::end() const
{
    return (getEndIte(*this));
}

template <typename T, class Iter, class Inherit>
typename MutantStack<T, Iter, Inherit>::reverse_iterator MutantStack<T, Iter, Inherit>::rbegin()
{
    return (getRBeginIte(*this));
}

template <typename T, class Iter, class Inherit>
typename MutantStack<T, Iter, Inherit>::reverse_iterator MutantStack<T, Iter, Inherit>::rend()
{
    return (getREndIte(*this));
}

template <typename T, class Iter, class Inherit>
typename MutantStack<T, Iter, Inherit>::const_reverse_iterator MutantStack<T, Iter, Inherit>::rbegin() const
{
    return (getRBeginIte(*this));
}

template <typename T, class Iter, class Inherit>
typename MutantStack<T, Iter, Inherit>::const_reverse_iterator MutantStack<T, Iter, Inherit>::rend() const
{
    return (getREndIte(*this));
}
*/

template <typename T, class Iter, class Inherit>
std::ostream& operator<<(std::ostream& os, const MutantStack<T, Iter, Inherit>& stack)
{
    os << stack;
    return (os);
}
template <typename T, class Iter, class Inherit>
std::ostream& operator<<(std::ostream& os, MutantStack<T, Iter, Inherit>& stack)
{
    os << stack;
    return (os);
}

template <typename T, class Iter, class Inherit>
std::ostream& operator<<(std::ostream& os, const typename MutantStack<T, Iter, Inherit>::iterator& ite)
{
    os << ite;
    return (os);
}
template <typename T, class Iter, class Inherit>
std::ostream& operator<<(std::ostream& os, typename MutantStack<T, Iter, Inherit>::iterator& ite)
{
    os << ite;
    return (os);
}

#endif
