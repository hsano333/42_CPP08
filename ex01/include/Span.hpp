#ifndef SPAN_H
#define SPAN_H

#include <set>
#include <iterator>
#include <utility>
#include <climits>
#include <cstdio>

class Span
{
    private:
        unsigned int N;
        unsigned int pos;
        ssize_t shortest;
        std::multiset<int> *item;
        void copy(std::multiset<int> *dst, std::multiset<int> *src) const;
        void setShortest(int num);


    public:
        Span(size_t N);
        Span();
        virtual ~Span();
        Span(const Span &s);
        Span& operator=(const Span &s);
        void addNumber(int num);
        void addNumbers();
        //void test();

        void addNumbers(std::multiset<int>::iterator begin, std::multiset<int>::iterator end);
        ssize_t shortestSpan(); 
        ssize_t longestSpan();
        unsigned int getSize();
        void sort_print(void);

        std::multiset<int>::iterator begin() const;
        std::multiset<int>::iterator end() const;
        std::multiset<int>::iterator begin();
        std::multiset<int>::iterator end();
};

#endif
