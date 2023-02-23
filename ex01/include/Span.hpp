#ifndef SPAN_H
#define SPAN_H

#include <set>
#include <vector>
#include <iterator>
#include <utility>

class Span
{
    private:
        unsigned int N;
        unsigned int pos;
        std::vector<std::pair<int, bool> > *item;

        std::vector<std::pair<int, bool> >::iterator valid_begin();
        std::vector<std::pair<int, bool> >::iterator valid_end();
        void addNumber(std::pair<int, bool> &num);

    public:
        Span(size_t N);
        Span();
        virtual ~Span();
        Span(const Span &s);
        Span& operator=(const Span &s);
        void addNumber(int num);
        void addNumbers();
        //void test();

        void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        ssize_t shortestSpan(); 
        ssize_t longestSpan();
        unsigned int getSize();
        void sort_print(void);

        std::vector<std::pair<int, bool> >::iterator begin() const;
        std::vector<std::pair<int, bool> >::iterator end() const;
        std::vector<std::pair<int, bool> >::iterator begin();
        std::vector<std::pair<int, bool> >::iterator end();
};

#endif
