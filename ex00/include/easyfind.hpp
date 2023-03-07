#ifndef EASYFING_H
#define EASYFING_H

#include <iostream>
#include <algorithm>
#include <queue>

template <template <typename, typename> class Container>
int easyfind_(Container<int, std::allocator<int> > &container, int search)
{
    size_t pos = 0;
    typename Container<int, std::allocator<int> >::iterator ite = container.begin();
    ite = std::find(container.begin(), container.end(), search);
    if (ite == container.end())
        throw std::invalid_argument("Exception:not find");
    typename Container<int, std::allocator<int> >::iterator begin = container.begin();
    for (; begin != ite; begin++)
    {
        pos++;
    }
    return (pos);
}

template <template <typename, typename> class Container>
int easyfind_(Container<int, std::allocator<int> > const &container, int search)
{
    size_t pos = 0;
    typename Container<int, std::allocator<int> >::const_iterator ite = container.begin();
    ite = std::find(container.begin(), container.end(), search);
    if (ite == container.end())
        throw std::invalid_argument("Exception:not find");
    typename Container<int, std::allocator<int> >::const_iterator begin = container.begin();
    for (; begin != ite; begin++)
    {
        pos++;
    }
    return (pos);
}

template <template <typename, typename> class Container>
int easyfind_(Container<int, std::deque<int> > const &container, int search)
{
    Container<int, std::deque<int> > cp(container);

    int tmp;
    int result = false;
    size_t size = cp.size();
    size_t cnt = 0;
    for (size_t i = 0; i < size; i++)
    {
        tmp = cp.front();
        cp.pop();
        if (tmp == search)
        {
            result = true;
            break ;
        }
        cnt++;
    }
    if (!result)
        throw std::invalid_argument("Exception:not find");
    return (cnt);
}

template <template <typename, typename> class Container>
int easyfind_(Container<int, std::deque<int> > &container, int search)
{
    const Container<int, std::deque<int> > cp(container);
    return easyfind_(cp, search);
}


template <template <typename, typename> class T, typename A>
int easyfind(T<int, A> &Container, int search)
{
    return (easyfind_(Container, search));
}

template <template <typename, typename> class T, typename A>
int easyfind(T<int, A> const &Container, int search)
{
    return (easyfind_(Container, search));
}

#endif
