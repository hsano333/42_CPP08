#ifndef EASYFING_H
#define EASYFING_H

#include <iostream>
#include <algorithm>
#include <queue>

template <template <typename, typename> class Container>
bool easyfind_(Container<int, std::allocator<int> > &container, int search)
{
    if (std::find(container.begin(), container.end(), search) == container.end())
        throw std::invalid_argument("Exception:not find");
    return (true);
}

template <template <typename, typename> class Container>
bool easyfind_(Container<int, std::allocator<int> > const &container, int search)
{
    if (std::find(container.begin(), container.end(), search) == container.end())
        throw std::invalid_argument("Exception:not find");
    return (true);
}

template <template <typename, typename> class Container>
bool easyfind_(Container<int, std::deque<int> > const &container, int search)
{
    Container<int, std::deque<int> > cp(container);

    int tmp;
    bool result = false;
    size_t size = cp.size();
    for (size_t i = 0; i < size; i++)
    {
        tmp = cp.front();
        cp.pop();
        if (tmp == search)
            result = true;
    }
    if (!result)
        throw std::invalid_argument("Exception:not find");
    return (result);
}


template <template <typename, typename> class Container>
bool easyfind_(Container<int, std::deque<int> > &container, int search)
{
    const Container<int, std::deque<int> > cp(container);
    return easyfind_(cp, search);
}


template <template <typename, typename> class T, typename A>
bool easyfind(T<int, A> &Container, int search)
{
    return (easyfind_(Container, search));
}

template <template <typename, typename> class T, typename A>
bool easyfind(T<int, A> const &Container, int search)
{
    return (easyfind_(Container, search));
}

#endif
