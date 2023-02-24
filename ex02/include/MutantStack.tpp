#ifndef MUTANTSTACK_T
#define MUTANTSTACK_T

#include "MutantStack.hpp"
#include <algorithm>
#include <typeinfo>

using std::cout;
using std::endl;

//template <typename T, class Iter, typename C,  template <class A, class B> class Inherit >
template <typename T, class Iter, typename C,  template <class A, class B> class Inherit >
std::ostream& operator<<(std::ostream& os, const MutantStack<T, Iter,C, Inherit >& f);
//template <typename T, class Iter, typename C,  template <class A, class B> class Inherit >
template <typename T, class Iter, typename C,  template <class A, class B> class Inherit >
std::ostream& operator<<(std::ostream& os, MutantStack<T, Iter,C, Inherit >& f);

//template <typename T, class Iter, typename C,  template <class A, class B> class Inherit >
//template <typename T, class Iter, typename C,  template <class A, class B> class Inherit >
template <typename T, class Iter, typename C,  template <class A, class B> class Inherit >
MutantStack<T, Iter,C, Inherit >::MutantStack()
{
}

template <typename T, class Iter, typename C,  template <class A, class B> class Inherit >
MutantStack<T, Iter,C, Inherit >::~MutantStack()
{
}


/*
template <typename T, class Iter, typename C,  template <class A, class B> class Inherit >
void MutantStack<T, Iter,C, Inherit >::mypush(iterator iter)
{
    this->push(*iter);
}
*/

template <typename T, class Iter, typename C,  template <class A, class B> class Inherit >
MutantStack<T, Iter,C, Inherit >::MutantStack(const MutantStack &stack) : std::stack<T>()
{
    MutantStack::iterator begin = stack.begin();
    MutantStack::iterator end = stack.end();
    for(; begin != end; begin++)
    {
        this->push(*begin);
    }
}

template <typename T, class Iter, typename C,  template <class A, class B> class Inherit >
MutantStack<T, Iter,C, Inherit >& MutantStack<T, Iter,C, Inherit >::operator=(const MutantStack &stack)
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

template <typename T, class Iter, typename C,  template <class A, class B> class Inherit >
template <template <typename, typename> class Container>
void MutantStack<T, Iter,C, Inherit >::Test(Container<T, Iter> &obj)
{
    cout << "Test():" << &obj << endl;
}

/*
template <typename T, class Iter, typename C,  template <class A, class B> class Inherit >
template <template <typename> class Container>
void MutantStack<T, Iter,C, Inherit >::Test(Container<T> &obj)
{
    cout << "Test():" << &obj << endl;
}
*/

template <typename T, class Iter, typename C,  template <class A, class B> class Inherit >
//template <template <typename, typename> class Container>
template <template <typename> class Container>
void MutantStack<T, Iter,C, Inherit >::Test(Container<T> &obj)
{
    cout << "Test():" << &obj << endl;
}

/*
template <typename T, class Iter, typename C,  template <class A, class B> class Inherit >
template <template <typename, typename> class Container>
void MutantStack<T, Iter,C, Inherit >::Test(Container<T, Iter > &obj)
{
    cout << "Test():" << &obj << endl;
}
*/


template <typename T, class Iter, typename C,  template <class A, class B> class Inherit >
template < template <typename, typename, typename> class Container>
typename MutantStack<T, Iter,C, Inherit >::iterator MutantStack<T, Iter,C, Inherit >::getBeginIte(Container<T, Iter, Inherit<T, std::deque<T> > > &obj)
{
    if (&obj == this)
        return (this->c.begin());
    return (this->c.begin());
}

template <typename T, class Iter, typename C,  template <class A, class B> class Inherit >
template < template <typename, typename, typename> class Container>
typename MutantStack<T, Iter,C, Inherit >::iterator MutantStack<T, Iter,C, Inherit >::getBeginIte(Container<T, Iter, Inherit<T,C>> &obj)
{
    if (&obj == this)
        return Iter::begin();
    return Iter::begin();
}

template <typename T, class Iter, typename C,  template <class A, class B> class Inherit >
template < template <typename, typename, typename> class Container>
typename MutantStack<T, Iter,C, Inherit >::iterator MutantStack<T, Iter,C, Inherit >::getEndIte(Container<T, std::deque<T>, std::stack<T> > &obj)
{
    if (&obj == this)
        return (this->c.end());
    return (this->c.end());
}
template <typename T, class Iter, typename C,  template <class A, class B> class Inherit >
template < template <typename, typename, typename> class Container>
typename MutantStack<T, Iter,C, Inherit >::iterator MutantStack<T, Iter,C, Inherit >::getEndIte(Container<T, Iter, Inherit<T,C>> &obj)
{
    if (&obj == this)
        return Iter::end();
    return Iter::end();
}

template <typename T, class Iter, typename C,  template <class A, class B> class Inherit >
template < template <typename, typename, typename> class Container>
typename MutantStack<T, Iter,C, Inherit >::const_iterator MutantStack<T, Iter,C, Inherit >::getBeginIte(Container<T, std::deque<T>, std::stack<T> > &obj) const
{
    if (&obj == this)
        return (this->c.begin());
    return (this->c.begin());
}

template <typename T, class Iter, typename C,  template <class A, class B> class Inherit >
template < template <typename, typename, typename> class Container>
typename MutantStack<T, Iter,C, Inherit >::const_iterator MutantStack<T, Iter,C, Inherit >::getBeginIte(Container<T, Iter, Inherit<T,C>> &obj) const
{
    if (&obj == this)
        return Iter::begin();
    return Iter::begin();
}

template <typename T, class Iter, typename C,  template <class A, class B> class Inherit >
template < template <typename, typename, typename> class Container>
typename MutantStack<T, Iter,C, Inherit >::const_iterator MutantStack<T, Iter,C, Inherit >::getEndIte(Container<T, std::deque<T>, std::stack<T> > &obj) const
{
    if (&obj == this)
        return (this->c.end());
    return (this->c.end());
}
template <typename T, class Iter, typename C,  template <class A, class B> class Inherit >
template < template <typename, typename, typename> class Container>
typename MutantStack<T, Iter,C, Inherit >::const_iterator MutantStack<T, Iter,C, Inherit >::getEndIte(Container<T, Iter, Inherit<T,C>> &obj) const
{
    if (&obj == this)
        return Iter::end();
    return Iter::end();
}



/*
template <typename T, class Iter, typename C,  template <class A, class B> class Inherit >
template <template <typename, typename> class Container>
const typename MutantStack<T, Iter,C, Inherit >::const_iterator MutantStack<T, Iter,C, Inherit >::getBeginIte(Container<T, Iter > &obj) const
{
    if (&obj == this)
        return (this->c.begin());
    return (this->c.begin());
}
template <typename T, class Iter, typename C,  template <class A, class B> class Inherit >
template <template <typename, typename> class Container>
typename MutantStack<T, Iter,C, Inherit >::const_iterator MutantStack<T, Iter,C, Inherit >::getBeginIte(Container<T, std::allocator<T> > &obj) const
{
    if (&obj == this)
        return (this->begin());
    return (this->begin());
}

template <typename T, class Iter, typename C,  template <class A, class B> class Inherit >
template <template <typename, typename> class Container>
typename Iter::const_iterator MutantStack<T, Iter,C, Inherit >::getEndIte(Container<T, Iter > &obj) const
{
    if (&obj == this)
        return (this->c.end());
    return (this->c.end());
}
template <typename T, class Iter, typename C,  template <class A, class B> class Inherit >
template <template <typename, typename> class Container>
typename Iter::const_iterator MutantStack<T, Iter,C, Inherit >::getEndIte(Container<T, std::allocator<T> > &obj) const
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

template <typename T, class Iter, typename C,  template <class A, class B> class Inherit >
template <template <typename, typename> class Container>
typename Iter::reverse_iterator MutantStack<T, Iter,C, Inherit >::getRBeginIte(Container<T, Iter > &obj)
{
    if (&obj == this)
        return (this->c.rbegin());
    return (this->c.rbegin());
}
template <typename T, class Iter, typename C,  template <class A, class B> class Inherit >
template <template <typename, typename> class Container>
typename Iter::reverse_iterator MutantStack<T, Iter,C, Inherit >::getRBeginIte(Container<T, std::allocator<T> > &obj)
{
    if (&obj == this)
        return (this->rbegin());
    return (this->rbegin());
}

template <typename T, class Iter, typename C,  template <class A, class B> class Inherit >
template <template <typename, typename> class Container>
typename Iter::reverse_iterator MutantStack<T, Iter,C, Inherit >::getREndIte(Container<T, Iter > &obj)
{
    if (&obj == this)
        return (this->c.rend());
    return (this->c.rend());
}
template <typename T, class Iter, typename C,  template <class A, class B> class Inherit >
template <template <typename, typename> class Container>
typename Iter::reverse_iterator MutantStack<T, Iter,C, Inherit >::getREndIte(Container<T, std::allocator<T> > &obj)
{
    if (&obj == this)
        return (this->rend());
    return (this->rend());
}

template <typename T, class Iter, typename C,  template <class A, class B> class Inherit >
template <template <typename, typename> class Container>
typename Iter::const_reverse_iterator MutantStack<T, Iter,C, Inherit >::getRBeginIte(Container<T, Iter > &obj) const
{
    if (&obj == this)
        return (this->c.rbegin());
    return (this->c.rbegin());
}
template <typename T, class Iter, typename C,  template <class A, class B> class Inherit >
template <template <typename, typename> class Container>
typename Iter::const_reverse_iterator MutantStack<T, Iter,C, Inherit >::getRBeginIte(Container<T, std::allocator<T> > &obj) const
{
    if (&obj == this)
        return (this->rbegin());
    return (this->rbegin());
}

template <typename T, class Iter, typename C,  template <class A, class B> class Inherit >
template <template <typename, typename> class Container>
typename Iter::const_reverse_iterator MutantStack<T, Iter,C, Inherit >::getREndIte(Container<T, Iter > &obj) const
{
    if (&obj == this)
        return (this->c.rend());
    return (this->c.rend());
}
template <typename T, class Iter, typename C,  template <class A, class B> class Inherit >
template <template <typename, typename> class Container>
typename Iter::const_reverse_iterator MutantStack<T, Iter,C, Inherit >::getREndIte(Container<T, std::allocator<T> > &obj) const
{
    if (&obj == this)
        return (this->rend());
    return (this->rend());
}
*/


template <typename T, class Iter, typename C,  template <class A, class B> class Inherit >
typename MutantStack<T, Iter,C, Inherit >::iterator MutantStack<T, Iter,C, Inherit >::begin()
{
    //this->Test(*this);
    return (getBeginIte(*this));
}

template <typename T, class Iter, typename C,  template <class A, class B> class Inherit >
typename MutantStack<T, Iter,C, Inherit >::iterator MutantStack<T, Iter,C, Inherit >::end()
{
    return (getEndIte(*this));
}

/*
template <typename T, class Iter, typename C,  template <class A, class B> class Inherit >
typename MutantStack<T, Iter,C, Inherit >::const_iterator MutantStack<T, Iter,C, Inherit >::begin() const
{
    return (getBeginIte(*this));
}

template <typename T, class Iter, typename C,  template <class A, class B> class Inherit >
typename MutantStack<T, Iter,C, Inherit >::const_iterator MutantStack<T, Iter,C, Inherit >::end() const
{
    return (getEndIte(*this));
}

template <typename T, class Iter, typename C,  template <class A, class B> class Inherit >
typename MutantStack<T, Iter,C, Inherit >::reverse_iterator MutantStack<T, Iter,C, Inherit >::rbegin()
{
    return (getRBeginIte(*this));
}

template <typename T, class Iter, typename C,  template <class A, class B> class Inherit >
typename MutantStack<T, Iter,C, Inherit >::reverse_iterator MutantStack<T, Iter,C, Inherit >::rend()
{
    return (getREndIte(*this));
}

template <typename T, class Iter, typename C,  template <class A, class B> class Inherit >
typename MutantStack<T, Iter,C, Inherit >::const_reverse_iterator MutantStack<T, Iter,C, Inherit >::rbegin() const
{
    return (getRBeginIte(*this));
}

template <typename T, class Iter, typename C,  template <class A, class B> class Inherit >
typename MutantStack<T, Iter,C, Inherit >::const_reverse_iterator MutantStack<T, Iter,C, Inherit >::rend() const
{
    return (getREndIte(*this));
}
*/

template <typename T, class Iter, typename C,  template <class A, class B> class Inherit >
std::ostream& operator<<(std::ostream& os, const MutantStack<T, Iter,C, Inherit >& stack)
{
    os << stack;
    return (os);
}
template <typename T, class Iter, typename C,  template <class A, class B> class Inherit >
std::ostream& operator<<(std::ostream& os, MutantStack<T, Iter,C, Inherit >& stack)
{
    os << stack;
    return (os);
}

template <typename T, class Iter, typename C,  template <class A, class B> class Inherit >
std::ostream& operator<<(std::ostream& os, const typename MutantStack<T, Iter,C, Inherit >::iterator& ite)
{
    os << ite;
    return (os);
}
template <typename T, class Iter, typename C,  template <class A, class B> class Inherit >
std::ostream& operator<<(std::ostream& os, typename MutantStack<T, Iter,C, Inherit >::iterator& ite)
{
    os << ite;
    return (os);
}

#endif
