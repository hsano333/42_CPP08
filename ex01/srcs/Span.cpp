#include "Span.hpp"
#include <algorithm>
#include <iterator>
#include <iostream>
#include <cstdio>
#include <ctime>

using std::cout;
using std::endl;

Span::Span(unsigned int N) : N(N), pos(0)
{
    this->item = new std::list<int>(N);
}
Span::Span() : N(0), pos(0)
{
    this->item = new std::list<int>(0);
}
Span::~Span()
{
    delete this->item;
}

Span::Span(const Span &s)
{
    if (this->item != s.item)
    {
        delete (this->item);
        this->item = new std::list<int>(s.item->size());
        for(unsigned int i=0; i < s.pos; i++)
        {
            this->item[i] = s.item[i];
        }
    }
    this->pos = s.pos;
}

Span& Span::operator=(const Span &s)
{
    if (this->item != s.item)
    {
        delete (this->item);
        this->item = new std::list<int>(s.item->size());
        for(unsigned int i=0; i < s.pos; i++)
        {
            this->item[i] = s.item[i];
        }
    }
    this->pos = s.pos;
    return (*this);
}

void Span::addNumber(int num)
{
    if (this->pos == this->N)
        throw std::exception();
    std::list<int>::iterator iter = std::next(this->item->begin(), this->pos);
    *iter = num;
    this->pos++;
}

void addRandomNumber(int &value)
{
    static int random_int = 0;
    int rand_value = 0;

    random_int++;
    srand((unsigned int)(time(NULL)) * random_int);
    rand_value = (int)(((int)rand() - INT_MIN )) * 2;
    value = rand_value;
}

void Span::addNumbers()
{

    std::list<int>::iterator begin_iter  = std::next(this->item->begin(), this->pos);
    std::list<int>::iterator end_iter = this->item->end();
    std::for_each(begin_iter, end_iter, addRandomNumber);
    this->pos = this->N;
}

ssize_t Span::longestSpan()
{
    if (this->pos < 2)
        throw std::exception();
    this->item->sort();
    std::list<int>::iterator end_iter = this->item->end();
    end_iter--;
    return (static_cast<ssize_t>(*end_iter) - static_cast<ssize_t>(*this->item->begin()));
}

ssize_t Span::shortestSpan()
{
    if (this->pos < 2)
        throw std::exception();
    ssize_t min;
    ssize_t tmp;
    this->item->sort();
    std::list<int>::iterator begin_iter = this->item->begin();
    std::list<int>::iterator end_iter = this->item->end();
    std::list<int>::iterator next_iter;
    end_iter--;
    for(std::list<int>::iterator i = begin_iter; i != end_iter; i++)
    {
        next_iter = i;
        next_iter++;
        tmp = static_cast<ssize_t>(*next_iter) - static_cast<ssize_t>(*i);
        if (min > tmp)
        {
            min = tmp;
        }
    }
    return (min);
}

unsigned int Span::getSize()
{
    return (this->item->size());

}

void print(const int &value)
{
    std::cout << value << std::endl;
}

void Span::sort_print(void)
{
    this->item->sort();
    std::list<int>::iterator begin_iter = this->item->begin();
    std::list<int>::iterator end_iter = this->item->end();
    std::for_each(begin_iter, end_iter, print);
}
