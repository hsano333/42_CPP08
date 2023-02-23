#include "Span.hpp"
#include <algorithm>
#include <iterator>
#include <iostream>
#include <cstdio>
#include <ctime>

using std::cout;
using std::endl;

void init(std::pair<int, bool> pair)
{
    pair.first = 0;
    pair.second= false;
}

Span::Span(unsigned int N) : N(N), pos(0)
{
    cout << "Defualt const" << endl;
    this->item = new std::vector<std::pair<int, bool> >(N);
    for_each(this->item->begin(), this->item->end(), init);
}
Span::Span() : N(0), pos(0)
{
    cout << "const" << endl;
    //this->item = new std::vector<int>(0);
    this->item = new std::vector<std::pair<int, bool> >(0);
    for_each(this->item->begin(), this->item->end(), init);
}
Span::~Span()
{
    delete this->item;
}

Span::Span(const Span &s)
{
    cout << "Copy const" << endl;
    if (this->item != s.item)
    {
        delete (this->item);
        this->item = new std::vector<std::pair<int, bool> >(s.item->size());
        for (unsigned long i=0; i<s.item->size();i++)
        {
            this->item[i] = s.item[i];
            std::cout << "s=" << &s.item[i] << ", item=" << &this->item[i] << endl;
        }
        this->N = s.N;
        this->pos = s.pos;
    }
}

Span& Span::operator=(const Span &s)
{
    cout << "Copy assingment" << endl;
    if (this->item != s.item)
    {
        delete (this->item);
        this->item = new std::vector<std::pair<int, bool> >(s.item->size());
        for (unsigned long i=0; i<s.item->size();i++)
            this->item[i] = s.item[i];
    }
    this->N = s.N;
    this->pos = s.pos;
    return (*this);
}

void Span::addNumber(int num)
{
    if (this->pos == this->N)
        throw std::exception();
    std::vector<std::pair<int, bool> >::iterator iter = this->valid_end();
    (*iter).second= true;
    (*iter).first = num;
    this->pos++;
}

void Span::addNumber(std::pair<int, bool> &num)
{
    this->addNumber(num.first);
}

void addRandomNumber(std::pair<int, bool>&value)
{
    static int random_int = 0;
    int rand_value = 0;

    random_int++;
    srand((unsigned int)(time(NULL)) * random_int);
    rand_value = (int)(((int)rand() - INT_MIN )) * 2;
    value = std::make_pair(rand_value, true);
}


void Span::addNumbers()
{

    std::vector<std::pair<int, bool> >::iterator begin  = this->valid_end();
    std::vector<std::pair<int, bool> >::iterator end = this->item->end();
    std::for_each(begin, end, addRandomNumber);
    //this->pos = this->N;
    this->pos = this->item->size();
}


//template <typename T>
//void Span::addNumbers(typename Container<int>::iterator begin, typename Container<int>::iterator end)
//void Span::addNumbers(std::iterator begin, std::iterator end)
//template <template <typename> class Container>
//void Span::addNumbers(typename std::iterator<std::forward_iterator_tag, Container<int>> begin, typename std::iterator<std::forward_iterator_tag, Container<int>> end)
//template<typename It> 
//void Span::addNumbers(It begin, It end)
//void Span::addNumbers(std::iterator<std::forward_iterator_tag, std::vector<int> > begin, std::iterator<std::forward_iterator_tag, std::vector<int> > end)
void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    std::vector<int>::iterator iter;
    //std::vector<int>::iterator begin_iter  = std::next(this->item->begin(), this->pos);
    //std::vector<int>::iterator end_iter = this->item->end();
    for(iter = begin; iter != end; iter++)
        this->addNumber(*iter);
    //this->pos = this->N;
    //this->pos = this->item->size();
}

ssize_t Span::longestSpan()
{
    if (this->pos < 2)
        throw std::exception();
    //this->item->sort();
    std::vector<std::pair<int, bool> >::iterator end_iter = this->item->end();
    end_iter--;
    return (static_cast<ssize_t>((*end_iter).first) - static_cast<ssize_t>((*(this->item->begin())).first));
}

ssize_t Span::shortestSpan()
{
    if (this->pos < 2)
        throw std::exception();
    ssize_t min;
    ssize_t tmp;
    //this->item->sort();
    std::vector<std::pair<int, bool> >::iterator begin_iter = this->item->begin();
    std::vector<std::pair<int, bool> >::iterator end_iter = this->item->end();
    std::vector<std::pair<int, bool> >::iterator next_iter;
    end_iter--;
    for(std::vector<std::pair<int, bool> >::iterator i = begin_iter; i != end_iter; i++)
    {
        next_iter = i;
        next_iter++;
        tmp = static_cast<ssize_t>((*next_iter).first) - static_cast<ssize_t>((*i).first);
        if (min > tmp)
        {
            min = tmp;
        }
    }
    return (min);
}

unsigned int Span::getSize()
{
    unsigned long cnt = 0;
    for(unsigned long i = 0; i< this->item->size(); i++)
    {
        if ((*(this->item))[i].second)
            cnt++;
    }
    return (cnt);
}

void print(const std::pair<int, bool> &value)
{
    std::cout << value.first << std::endl;
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
    //this->item->sort();
    //sort(this->valid_begin(), this->valid_end());
    sort(this->begin(), this->end());
    std::vector<std::pair<int, bool> >::iterator begin_iter = this->valid_begin();
    std::vector<std::pair<int, bool> >::iterator end_iter = this->valid_end();
    std::for_each(begin_iter, end_iter, print);
}

std::vector<std::pair<int, bool> >::iterator Span::begin(void)
{
    return (this->item->begin());
}

std::vector<std::pair<int, bool> >::iterator Span::begin(void) const
{
    return (this->item->begin());
}

std::vector<std::pair<int, bool> >::iterator Span::end(void)
{
    return (this->item->end());
}

std::vector<std::pair<int, bool> >::iterator Span::end(void) const
{
    return (this->item->end());
}

std::vector<std::pair<int, bool> >::iterator Span::valid_begin(void)
{
    std::vector<std::pair<int, bool> >::iterator begin = this->item->begin();
    std::vector<std::pair<int, bool> >::iterator end = this->item->end();
    while (begin != end)
    {
        if ((*begin).second == true)
            break;
        begin++;
    }
    return (begin);
}

std::vector<std::pair<int, bool> >::iterator Span::valid_end(void)
{
    std::vector<std::pair<int, bool> >::iterator begin = this->begin();
    std::vector<std::pair<int, bool> >::iterator end = this->end();
    while (begin != end)
    {
        --end;
        if ((*end).second == true)
            break;
    }
    end++;
    return (end);
}
