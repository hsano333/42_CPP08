#include "Span.hpp"
#include <algorithm>
#include <iterator>
#include <iostream>
#include <cstdio>
#include <ctime>

using std::cout;
using std::endl;


Span::Span(size_t N) : pos(0) , shortest(UINT_MAX)
{
    if (N > UINT_MAX)
        throw std::invalid_argument("Span Constructor Exception: range 0 to UINT_MAX");
    this->N = N;
    this->item = new std::multiset<int>;
}
Span::Span() : N(0), pos(0) , shortest(UINT_MAX)
{
}
Span::~Span()
{
    delete this->item;
}

void Span:: copy(std::multiset<int> *dst, std::multiset<int> *src) const
{
    std::multiset<int>::iterator ite = src->begin();
    std::multiset<int>::iterator end_ite= src->begin();

    for (; ite != end_ite; ite++)
    {
        dst->insert(*ite);
    }
}

Span::Span(const Span &s)
{
    this->item = new std::multiset<int>;
    copy(this->item, (s.item));
    this->N = s.N;
    this->pos = s.pos;
    this->shortest = s.shortest;
}

Span& Span::operator=(const Span &s)
{
    if (this->item != s.item)
    {
        try{
            std::multiset<int> *tmp = new std::multiset<int>;
            copy(tmp, (s.item));
            this->N = s.N;
            this->pos = s.pos;
            this->shortest = s.shortest;
            delete (this->item);
            this->item = tmp;
        }catch (std::exception){
            std::cerr << "Error: Span() Copy Assignment" << endl;
        }
    }
    return (*this);
}

void Span::setShortest(int num)
{
    std::multiset<int>::iterator cur = this->item->find(num);
    std::multiset<int>::iterator ite = cur;
    std::multiset<int>::iterator pre;
    std::multiset<int>::iterator next;
    std::multiset<int>::iterator begin = this->item->begin();
    std::multiset<int>::iterator end = this->item->end();
    ssize_t min;

    if (this->item->size() <= 2)
        return ;
    if (ite == begin)
    {
        next = ++ite;
        min = (ssize_t)*next - *cur;
        if (this->shortest > min)
            this->shortest = min;
        return ;
    }
    next = ++ite;
    if (next == end)
    {
        --ite;
        pre = --ite;
        min = (ssize_t)*cur - *pre;
        if (this->shortest > min)
            this->shortest = min;
        return ;
    }
    ite--;
    ite--;
    pre = ite;
    min = std::min((ssize_t)*next - *cur, (ssize_t)*cur - *pre);
    if (this->shortest > min)
        this->shortest = min;
}

void Span::addNumber(int num)
{
    if (this->pos == this->N)
        throw std::length_error("addNumber Error:excced Max size");
    this->item->insert(num);
    this->setShortest(num);
    this->pos++;
}

/*
void Span::addNumber(int&num)
{
    this->addNumber(num.first);
}
*/

int addRandomNumber(void)
{
    static int random_int = 0;
    int rand_value = 0;

    random_int++;
    srand((unsigned int)(time(NULL)) * random_int);
    rand_value = (int)(((int)rand() - INT_MIN )) * 2;
    return (rand_value);
}


void Span::addNumbers()
{
    while (this->item->size() != this->N)
    {
        this->addNumber(addRandomNumber());
    }
    this->pos = this->N;
}

void Span::addNumbers(std::multiset<int>::iterator begin, std::multiset<int>::iterator end)
{
    std::multiset<int>::iterator iter;
    for(iter = begin; iter != end; iter++)
        this->addNumber(*iter);
}

ssize_t Span::longestSpan()
{
    if (this->pos < 2)
        throw std::out_of_range("longestSpan Error:Span size is lack");
    //sort(this->item->begin(), this->item->end());
    std::multiset<int>::iterator end_iter = this->item->end();
    end_iter--;
    return (static_cast<ssize_t>((*end_iter)) - static_cast<ssize_t>((*(this->item->begin()))));
}

ssize_t Span::shortestSpan()
{
    if (this->pos < 2)
        throw std::out_of_range("shortestSpan Error:Span size is lack");
    return (this->shortest);
    /*

    ssize_t min = UINT_MAX;
    ssize_t tmp;

    std::multiset<int>::iterator begin_iter = this->item->begin();
    std::multiset<int>::iterator end_iter = this->item->end();
    std::multiset<int>::iterator next_iter;
    end_iter--;
    for(std::multiset<int>::iterator i = begin_iter; i != end_iter; i++)
    {
        next_iter = i;
        next_iter++;
        tmp = static_cast<ssize_t>((*next_iter)) - static_cast<ssize_t>((*i));
        if (min > tmp)
        {
            min = tmp;
        }
    }
    if (this->shortest != min)
    {
        cout  << "Error shorttest" << this->shortest << ", min=" << min  << endl;
        cout  << "Error shorttest" << endl;
        cout  << "Error shorttest" << endl;
        cout  << "Error shorttest" << endl;
        cout  << "Error shorttest" << endl;
        cout  << "Error shorttest" << endl;
        cout  << "Error shorttest" << endl;
        cout  << "Error shorttest" << endl;
        exit(1);
    }
    return (min);
    */
}

unsigned int Span::getSize()
{
    return (this->pos);
}

void print(const int&value)
{
    std::cout << value << std::endl;
}

/*
template <typename T1, typename T2>
bool std::pair<T1, T2>::operator>=(std::pair<T1, T2> &b) const
{
    return (this->first >= b.first);
}
*/

void Span::sort_print(void)
{
    if (this->pos == 0)
        return ;
    std::multiset<int>::iterator begin_iter = this->item->begin();
    std::multiset<int>::iterator end_iter = this->item->end();
    std::for_each(begin_iter, end_iter, print);
}

std::multiset<int>::iterator Span::begin(void)
{
    return (this->item->begin());
}

std::multiset<int>::iterator Span::begin(void) const
{
    return (this->item->begin());
}

std::multiset<int>::iterator Span::end(void)
{
    return (this->item->end());
}

std::multiset<int>::iterator Span::end(void) const
{
    return (this->item->end());
}

