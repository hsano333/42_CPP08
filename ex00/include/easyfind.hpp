#ifndef EASYFING_H
#define EASYFING_H

#include <iostream>
#include <algorithm>
#include <queue>

template <template <typename, typename> class Container>
bool easyfind_(Container<int, std::allocator<int> > &container, int search)
{
    if (std::find(container.begin(), container.end(), search) == container.end())
        throw std::exception();
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
        throw std::exception();
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
        throw std::exception();
    container = cp;
    return (result);
}

template <typename T>
bool easyfind(T &container, int search)
{
    return (easyfind_(container, search));
    //if (std::find(container.begin(), container.end(), search) == container.end())
        //throw std::exception();
    //return (true);
}

#endif
