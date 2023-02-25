#ifndef MUTANTSTACK_T
#define MUTANTSTACK_T

#include "MutantStack.hpp"
#include <algorithm>
#include <typeinfo>
#include <iomanip>

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
void MutantStack<T, Iter, Inherit>::TTest()
{

    cout << "TEST()" << endl;
    //for (size_t i=0; i<src.size(); i++){
        //cout << "copy push" << endl;
        //dst.push(src.c.at(i));
    //}

}

template <typename T, class Iter, class Inherit>
void MutantStack<T, Iter, Inherit>::copys(MutantStack<T, std::deque<T>, std::stack<T> > &dst, MutantStack<T, std::deque<T>, std::stack<T> > const &src)
{
    cout << "copy start" << src.size() << endl << std::flush;
    for (size_t i=0; i<src.size(); i++){
        //cout << "copy push" << endl;
        dst.push(src.c.at(i));
    }
        cout << "copy end" << endl;
}

template <typename T, class Iter, class Inherit>
void MutantStack<T, Iter, Inherit>::copys(MutantStack<T, Iter, Iter> &dst, MutantStack<T, Iter, Iter> const &src)
{
    if (dst == src)
        return ;
    cout << "copy start 2" << src.size() << endl << std::flush;
    for (size_t i=0; i<src.size(); i++){
        this->push_back(src[i]);
    }
}

template <typename T, class Iter, class Inherit>
void MutantStack<T, Iter, Inherit>::clear(MutantStack<T, std::deque<T>, std::stack<T> > &obj)
{
    cout << "clear()" << endl;
    while (!(obj.empty()))
    {
        cout << "not empty pop" << endl;
        obj.pop();
    }
        cout << "endl clear empty pop" << endl;
}

template <typename T, class Iter, class Inherit>
void MutantStack<T, Iter, Inherit>::clear(MutantStack<T, Iter, Iter> &obj)
{
    obj.clear();
}

/*
template <typename T, class Iter, class Inherit>
template < template <typename, typename, typename> class Container>
void MutantStack<T, Iter, Inherit>::clear(Container<T, std::deque<T>, std::stack<T> > &obj)
{
    obj.clear();
}

template <typename T, class Iter, class Inherit>
template < template <typename, typename, typename> class Container>
void MutantStack<T, Iter, Inherit>::clear(Container<T, Iter, Iter> &obj)
{
    iterator ite = src.begin();
    iterator end_ite = src.end();
    for (; ite != end_ite;ite++){
        dst.push_back(*ite);
    }
}
*/

template <typename T, class Iter, class Inherit>
MutantStack<T, Iter, Inherit>::MutantStack(const MutantStack<T, Iter, Inherit> &stack) : Inherit()
{
    //cout << "Copy COnst No.1" << endl;
    this->copys(*this, stack);
    //this->TTest();
    cout << "Copy COnst No.2" << &stack << endl;
    /*
    MutantStack::const_iterator begin = stack.begin();
    MutantStack::const_iterator end = stack.end();
    for(; begin != end; begin++)
    {
        this->push(*begin);
    }
    */
}

template <typename T, class Iter, class Inherit>
MutantStack<T, Iter, Inherit>& MutantStack<T, Iter, Inherit>::operator=(const MutantStack<T, Iter, Inherit> &stack)
{
    cout << "Copy assignment No.1" << endl;
    if (*this != stack)
    {
    cout << "Copy assignment No.2" << endl;
        this->clear(*this);
        this->copys(*this, stack);
        /*
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
        */

    }
    cout << "Copy assignment No.3" << endl;
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
typename MutantStack<T, Iter, Inherit>::iterator MutantStack<T, Iter, Inherit>::getBeginIte(Container<T, Iter, Iter> &obj)
{
    if (&obj == this)
        return Iter::begin();
    return Iter::begin();
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
typename MutantStack<T, Iter, Inherit>::iterator MutantStack<T, Iter, Inherit>::getEndIte(Container<T, Iter, Iter> &obj)
{
    if (&obj == this)
        return Iter::end();
    return Iter::end();
}

template <typename T, class Iter, class Inherit>
template < template <typename, typename, typename> class Container>
typename MutantStack<T, Iter, Inherit>::const_iterator MutantStack<T, Iter, Inherit>::getBeginIte(Container<T, std::deque<T>, std::stack<T> > &obj) const
{
    if (&obj == this)
        return (this->c.begin());
    return (this->c.begin());
}

template <typename T, class Iter, class Inherit>
template < template <typename, typename, typename> class Container>
typename MutantStack<T, Iter, Inherit>::const_iterator MutantStack<T, Iter, Inherit>::getBeginIte(Container<T, Iter, Iter> &obj) const
{
    if (&obj == this)
        return Iter::begin();
    return Iter::begin();
}

template <typename T, class Iter, class Inherit>
template < template <typename, typename, typename> class Container>
typename MutantStack<T, Iter, Inherit>::const_iterator MutantStack<T, Iter, Inherit>::getEndIte(Container<T, std::deque<T>, std::stack<T> > &obj) const
{
    if (&obj == this)
        return (this->c.end());
    return (this->c.end());
}
template <typename T, class Iter, class Inherit>
template < template <typename, typename, typename> class Container>
typename MutantStack<T, Iter, Inherit>::const_iterator MutantStack<T, Iter, Inherit>::getEndIte(Container<T, Iter, Iter> &obj) const
{
    if (&obj == this)
        return Iter::end();
    return Iter::end();
}

template <typename T, class Iter, class Inherit>
template < template <typename, typename, typename> class Container>
typename MutantStack<T, Iter, Inherit>::reverse_iterator MutantStack<T, Iter, Inherit>::getRBeginIte(Container<T, std::deque<T>, std::stack<T> > &obj)
{
    if (&obj == this)
        return (this->c.rbegin());
    return (this->c.rbegin());
}

template <typename T, class Iter, class Inherit>
template < template <typename, typename, typename> class Container>
typename MutantStack<T, Iter, Inherit>::reverse_iterator MutantStack<T, Iter, Inherit>::getRBeginIte(Container<T, Iter, Iter> &obj)
{
    if (&obj == this)
        return Iter::rbegin();
    return Iter::rbegin();
}

template <typename T, class Iter, class Inherit>
template < template <typename, typename, typename> class Container>
typename MutantStack<T, Iter, Inherit>::reverse_iterator MutantStack<T, Iter, Inherit>::getREndIte(Container<T, std::deque<T>, std::stack<T> > &obj)
{
    if (&obj == this)
        return (this->c.rend());
    return (this->c.rend());
}
template <typename T, class Iter, class Inherit>
template < template <typename, typename, typename> class Container>
typename MutantStack<T, Iter, Inherit>::reverse_iterator MutantStack<T, Iter, Inherit>::getREndIte(Container<T, Iter, Iter> &obj)
{
    if (&obj == this)
        return Iter::rend();
    return Iter::rend();
}

template <typename T, class Iter, class Inherit>
template < template <typename, typename, typename> class Container>
typename MutantStack<T, Iter, Inherit>::const_reverse_iterator MutantStack<T, Iter, Inherit>::getRBeginIte(Container<T, std::deque<T>, std::stack<T> > &obj) const
{
    if (&obj == this)
        return (this->c.rbegin());
    return (this->c.rbegin());
}

template <typename T, class Iter, class Inherit>
template < template <typename, typename, typename> class Container>
typename MutantStack<T, Iter, Inherit>::const_reverse_iterator MutantStack<T, Iter, Inherit>::getRBeginIte(Container<T, Iter, Iter> &obj) const
{
    if (&obj == this)
        return Iter::rbegin();
    return Iter::rbegin();
}

template <typename T, class Iter, class Inherit>
template < template <typename, typename, typename> class Container>
typename MutantStack<T, Iter, Inherit>::const_reverse_iterator MutantStack<T, Iter, Inherit>::getREndIte(Container<T, std::deque<T>, std::stack<T> > &obj) const
{
    if (&obj == this)
        return (this->c.rend());
    return (this->c.rend());
}
template <typename T, class Iter, class Inherit>
template < template <typename, typename, typename> class Container>
typename MutantStack<T, Iter, Inherit>::const_reverse_iterator MutantStack<T, Iter, Inherit>::getREndIte(Container<T, Iter, Iter> &obj) const
{
    if (&obj == this)
        return Iter::rend();
    return Iter::rend();
}




template <typename T, class Iter, class Inherit>
typename MutantStack<T, Iter, Inherit>::iterator MutantStack<T, Iter, Inherit>::begin()
{
    return (getBeginIte(*this));
}

template <typename T, class Iter, class Inherit>
typename MutantStack<T, Iter, Inherit>::iterator MutantStack<T, Iter, Inherit>::end()
{
    return (getEndIte(*this));
}

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
