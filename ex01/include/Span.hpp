#ifndef SPAN_H
#define SPAN_H

#include <set>
#include <list>

class Span
{
    private:
        unsigned int N;
        unsigned int pos;
        std::list<int> *item;

    public:
        Span(unsigned int N);
        Span();
        virtual ~Span();
        Span(const Span &s);
        Span& operator=(const Span &s);
        void addNumber(int num);
        void addNumbers();
        ssize_t shortestSpan(); 
        ssize_t longestSpan();
        unsigned int getSize();
        void sort_print(void);
};

#endif
