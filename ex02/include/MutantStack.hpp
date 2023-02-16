#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

#include <stack>
#include <iterator>

//template <typename T>
template <typename T>
class MutantStack : public std::stack<T> , public std::iterator< std::input_iterator_tag, T>
{
    private:
    public:
        //template <typename Iter>
        //class iterator : public std::iterator<Iter, T>
        class iterator : public std::iterator<std::input_iterator_tag, T>
        {
            public:
                iterator(){};
                ~iterator(){};
                iterator(const iterator & iter){};
                iterator& operator=(const iterator & iter){return *this;};
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
template <typename T>
std::ostream& operator<<(std::ostream& os, MutantStack<T>& f);


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


/*
template <typename Iter, typename T>
iterator<Iter, T>::iterator()
{
}
*/


#endif
