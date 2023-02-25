#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

#include <stack>
#include <list>
#include <iterator>
#include <iostream>
#include <climits>

//template <typename T, template <typename, typename> class Container>
//template <typename T, class Iter = std::list<T, std::allocator<T> >, class Inherit = std::list<T> >
//template <typename T, class Iter = Iter, class Inherit = std::stack<T> >
//template <typename T>
//template <typename T, class Iter = std::list<T>, class Inherit = std::list<T> >
//template <typename T, class Iter = std::list<T>, class Inherit = std::list<T> >
//
//

//template <typename T, class Iter = std::list<T>, typename C=std::allocator<T>, template <class A=T, class B=std::allocator<T> > class Inherit = std::list>
//class MutantStack : public Inherit<T>

template <typename T, class Iter = std::deque<T>, typename C=std::deque<T>, template <class A=T, class B=C> class Inherit = std::stack >
class MutantStack : public Inherit<T, C>
{
    public:
        MutantStack();
        MutantStack(const MutantStack &stack);
        MutantStack& operator=(const MutantStack &stack);
        virtual ~MutantStack();

        typedef typename Iter::iterator iterator;
        typedef typename Iter::const_iterator const_iterator;
        typedef typename Iter::reverse_iterator reverse_iterator;
        typedef typename Iter::const_reverse_iterator const_reverse_iterator;


        template < template <typename, typename, typename, typename> class Container>
        typename Iter::iterator getBeginIte(Container<T, Iter, C ,Inherit<T,C> > &obj);

        template < template <typename, typename, typename, typename> class Container>
        typename Iter::iterator getEndIte(Container<T, Iter, Inherit<T, C> ,Inherit<T,C> > &obj);

        /*

        template < template <typename, typename, typename> class Container>
        typename Iter::iterator getBeginIte(Container<T, Iter, Inherit<T, std::allocator<T> > > &obj);

        template < template <typename, typename, typename> class Container>
        typename Iter::iterator getEndIte(Container<T, Iter, Inherit<T, std::allocator<T> > > &obj);
        */

        /*
        template < template <typename, typename, typename> class Container>
        typename Iter::const_iterator getBeginIte(Container<T, std::deque<T>, std::stack<T> > &obj) const;

        template < template <typename, typename, typename> class Container>
        typename Iter::const_iterator getEndIte(Container<T, std::deque<T>, std::stack<T> > &obj) const;

        template < template <typename, typename, typename> class Container>
        typename Iter::const_iterator getBeginIte(Container<T, Iter, Inherit> &obj) const;

        template < template <typename, typename, typename> class Container>
        typename Iter::const_iterator getEndIte(Container<T, Iter, Inherit> &obj) const;
        */


        /*
        template <template <typename, typename> class Container>
        typename Iter::const_iterator getBeginIte(Container<T, Iter > &obj) const;
        template <template <typename, typename> class Container>
        typename Iter::const_iterator getBeginIte(Container<T, std::allocator<T> > &obj) const;
        template <template <typename, typename> class Container>
        typename Iter::const_iterator getEndIte(Container<T, Iter > &obj) const;
        template <template <typename, typename> class Container>
        typename Iter::const_iterator getEndIte(Container<T, std::allocator<T> > &obj) const;

        template <template <typename, typename> class Container>
        typename Iter::reverse_iterator getRBeginIte(Container<T, Iter > &obj);
        template <template <typename, typename> class Container>
        typename Iter::reverse_iterator getRBeginIte(Container<T, std::allocator<T> > &obj);
        template <template <typename, typename> class Container>
        typename Iter::reverse_iterator getREndIte(Container<T, Iter > &obj);
        template <template <typename, typename> class Container>
        typename Iter::reverse_iterator getREndIte(Container<T, std::allocator<T> > &obj);

        template <template <typename, typename> class Container>
        typename Iter::const_reverse_iterator getRBeginIte(Container<T, Iter > &obj) const;
        template <template <typename, typename> class Container>
        typename Iter::const_reverse_iterator getRBeginIte(Container<T, std::allocator<T> > &obj) const;
        template <template <typename, typename> class Container>
        typename Iter::const_reverse_iterator getREndIte(Container<T, Iter > &obj) const;
        template <template <typename, typename> class Container>
        typename Iter::const_reverse_iterator getREndIte(Container<T, std::allocator<T> > &obj) const;
        */

        template <template <typename, typename> class Container>
        void Test(Container<T, Iter > &obj);
        template <template <typename> class Container>
        void Test(Container<T> &obj);

        //template <template <typename> class Container>
        //void Test(Container<T> &obj);

        //template <template <template <typename, typename> class Inter>  class Container>
        //void Test(typename MutantStack<T , Container<Inter,  std::allocator<T> >  &obj);

        //template <template <typename, typename> class Container>
        //void Test(Container<T, Iter > &obj);


        iterator begin(void);
        iterator end(void);
        /*
        const_iterator& begin(void) const;
        const_iterator& end(void) const;
        reverse_iterator& rbegin(void);
        reverse_iterator& rend(void);
        const_reverse_iterator& rbegin(void) const;
        const_reverse_iterator& rend(void) const;
        */
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const MutantStack<T>& stack);
template <typename T>
std::ostream& operator<<(std::ostream& os, MutantStack<T>& stack);

/*
template <typename T>
std::ostream& operator<<(std::ostream& os, const typename MutantStack<T>::iterator& ite);
template <typename T>
std::ostream& operator<<(std::ostream& os, typename MutantStack<T>::iterator& ite);
*/


#include "MutantStack.tpp"
#endif
