#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

#include <stack>
#include <iterator>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{

    public:

        /*
        //class iterator : public std::iterator<std::forward_iterator_tag, T>
        class iterator : public std::deque<T>::iterator
        {
            private:
                uintptr_t pos;
                //iterator pos;
            public:
                iterator();
                ~iterator();
                iterator(const iterator & iter);
                iterator& operator=(const iterator & iter);
                iterator& operator++();
                iterator& operator++(int n);
                iterator& operator--();
                iterator& operator--(int n);
                bool operator!=(const iterator &iter);
                bool operator==(const iterator &iter);
                T& operator*() const;
        };
        */
        //typename std::stack<T>::iterator iterator;
        //typename std::stack<T>::iterator itc();
        MutantStack();
        MutantStack(const MutantStack &stack);
        MutantStack& operator=(const MutantStack &stack);
        virtual ~MutantStack();
        //typedef typename std::iterator<std::forward_iterator_tag, T> iterator;
        typedef typename std::deque<T>::iterator iterator;

        //iterator begin(void);
        iterator begin(void);
        iterator end(void);
    private:
        //void mypush(iterator iter);
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const MutantStack<T>& stack);
template <typename T>
std::ostream& operator<<(std::ostream& os, MutantStack<T>& stack);

template <typename T>
std::ostream& operator<<(std::ostream& os, const typename MutantStack<T>::iterator& ite);
template <typename T>
std::ostream& operator<<(std::ostream& os, typename MutantStack<T>::iterator& ite);


#include "MutantStack.tpp"
//#include "iterator.tpp"


#endif
