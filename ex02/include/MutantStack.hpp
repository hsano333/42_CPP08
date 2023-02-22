#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

#include <stack>
#include <iterator>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack();
        MutantStack(const MutantStack &stack);
        MutantStack& operator=(const MutantStack &stack);
        virtual ~MutantStack();
        typedef typename std::deque<T>::iterator iterator;
        typedef typename std::deque<T>::const_iterator const_iterator;
        typedef typename std::deque<T>::reverse_iterator reverse_iterator;
        typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;

        iterator begin(void);
        iterator end(void);
        const_iterator begin(void) const;
        const_iterator end(void) const;
        reverse_iterator rbegin(void);
        reverse_iterator rend(void);
        const_reverse_iterator rbegin(void) const;
        const_reverse_iterator rend(void) const;
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
