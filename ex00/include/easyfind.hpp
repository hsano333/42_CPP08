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
bool easyfind_(Container<int, std::deque<int> > &container, int search)
{
    Container<int, std::deque<int> > cp;
    int tmp;
    bool result = false;
    size_t size = container.size();
    for (size_t i = 0; i < size; i++)
    {
        tmp = container.front();
        cp.push(tmp);
        container.pop();
        if (tmp == search)
            result = true;

    }
    if (!result)
        throw std::invalid_argument("Exception:not find");
    container = cp;
    return (result);
}

template <template <typename, typename> class ContainerA, template < typename > class ContainerB>
bool easyfind_(ContainerA<int, ContainerB<int> > &container, int search)
{
    ContainerA<int, ContainerB<int> > cp;
    int tmp;
    bool result = false;
    size_t size = container.size();
    for (size_t i = 0; i < size; i++)
    {
        tmp = container.front();
        cp.push(tmp);
        container.pop();
        if (tmp == search)
            result = true;

    }
    if (!result)
        throw std::invalid_argument("Exception:not find");
    container = cp;
    return (result);
}

template <template <typename, typename> class T, typename A>
bool easyfind(T<int, A> &Container, int search)
{
    return (easyfind_(Container, search));
}

#endif
