#pragma once

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <map>
#include <set>
#include <vector>

namespace _
{
    template <typename Iterator, typename Predicate>
    bool any(Iterator begin, Iterator end, Predicate predicate)
    {
        while (begin != end)
        {
            if (predicate(*begin)) return true;

            begin++;
        }
        return false;
    }

    template <typename Container, typename Predicate>
    bool any(const Container &container, Predicate predicate)
    {
        return any(container.begin(), container.end(), predicate);
    }

    template <typename Iterator, typename Data>
    bool contains(Iterator begin, Iterator end, const Data &data)
    {
        while (begin != end)
        {
            if (*begin == data) return true;
            begin++;
        }
        return false;
    }

    template <typename Container, typename Data>
    bool contains(const Container &container, const Data &data)
    {
        return contains(container.begin(), container.end(), data);
    }

    template <typename Iterator, typename X, typename Y>
    bool contains(Iterator begin, Iterator end, const std::pair<X, Y> &p)
    {
        while (begin != end)
        {
            if ((*begin).first == p.first and (*begin).second == p.second) return true;
            begin++;
        }
        return false;
    }

    template <typename Container, typename X, typename Y>
    bool contains(const Container &container, const std::pair<X, Y> &p)
    {
        return contains(container.begin(), container.end(), p);
    }

    template <typename Iterator, typename Predicate>
    size_t count_by(Iterator begin, Iterator end, Predicate predicate)
    {
        size_t count = 0;
        while (begin != end)
        {
            if (predicate(*begin))
            {
                count++;
            }
            begin++;
        }
        return count;
    }

    template <typename Container, typename Predicate>
    size_t count_by(const Container &container, Predicate predicate)
    {
        return count_by(container.begin(), container.end(), predicate);
    }

    // forward declaration out of alphabetical order b/c count_by uses group_by
    template <typename Container, typename Function>
    auto group_by(Container &container, Function function)
    -> std::map<decltype(function(*container.begin())),
            std::vector<typename Container::value_type>>;

    template <typename Container, typename Function>
    auto count_by(Container &container, Function function)
    -> std::map<decltype(function(*container.begin())), size_t>
    {
        std::map<decltype(function(*container.begin())), size_t> result;
        std::map<decltype(function(*container.begin())),
                std::vector<typename Container::value_type>>
                grouped_by = group_by(container, function);
        for (auto &kv : grouped_by)
        {
            result[kv.first] = kv.second.size();
        }
        return result;
    }

    template <typename Iterator, typename Function>
    void each(Iterator begin, Iterator end, Function function)
    {
        while (begin != end)
        {
            function(*begin);
            begin++;
        }
    }

    template <typename Container, typename Function>
    void each(const Container &container, Function function)
    {
        each(container.begin(), container.end(), function);
    }

    template <typename Iterator, typename Predicate>
    bool every(Iterator begin, Iterator end, Predicate predicate)
    {
        while (begin != end)
        {
            if (predicate(*begin) == false) return false;
            begin++;
        }
        return true;
    }

    template <typename Container, typename Predicate>
    bool every(const Container &container, Predicate predicate)
    {
        return every(container.begin(), container.end(), predicate);
    }

    template <typename Container, typename Function>
    Container filter_accept(const Container &container, Function function)
    {
        Container result;
        typename Container::iterator first_begin, result_begin = result.begin();
        for (first_begin = container.begin(); first_begin != container.end(); ++first_begin)
        {
            if (function(*first_begin))
            {
                result.insert(result.end(), *first_begin);
            }
        }
        return result;
    }

    template <typename Container, typename Function>
    Container filter_reject(const Container &container, Function function)
    {
        Container result;
        typename Container::iterator first_begin, result_begin = result.begin();
        for (first_begin = container.begin(); first_begin != container.end(); ++first_begin)
        {
            if (!function(*first_begin))
            {
                result.insert(result.end(), *first_begin);
            }
        }
        return result;
    }

    template <typename Iterator, typename Predicate>
    Iterator find_if(Iterator begin, Iterator end, Predicate predicate)
    {
        while (begin != end)
        {
            if (predicate(*begin))
            {
                return begin;
            }
            begin++;
        }
        return end;
    }

    template <typename Iterator, typename Predicate>
    Iterator find_if_not(Iterator begin, Iterator end, Predicate predicate)
    {
        while (begin != end)
        {
            if (!predicate(*begin))
            {
                return begin;
            }
            begin++;
        }
        return end;
    }

    template <typename Container, typename Function>
    auto group_by(Container &container, Function function)
    -> std::map<decltype(function(*container.begin())),
            std::vector<typename Container::value_type>>
    {
        std::map<decltype(function(*container.begin())),
                std::vector<typename Container::value_type>>
                result;
        typename Container::iterator begin = container.begin();
        typename Container::iterator end = container.end();
        while (begin != end)
        {
            result[function(*begin)].push_back(*begin);
            begin++;
        }
        return result;
    }

    template <typename Container>
    Container intersect(Container container)
    {
        return container;
    }

    template <typename Container>
    Container intersect(Container container1, Container container2)
    {
        Container result;

        sort(container1.begin(), container1.end());
        sort(container2.begin(), container2.end());

        typename Container::const_iterator first_begin = container1.begin(),
                second_begin = container2.begin();

        while (first_begin != container1.end() && second_begin != container2.end())
        {
            if (*first_begin == *second_begin)
            {
                result.insert(result.end(), *first_begin);
                first_begin++;
                second_begin++;
            }
            else if (*first_begin > *second_begin)
            {
                second_begin++;
            }
            else
            {
                first_begin++;
            }
        }
        return result;
    }

    template <typename Container, typename... Containers>
    Container intersect(Container container1, Container container2, Containers... others)
    {
        return intersect(intersect(container1, container2), intersect(others...));
    }

    template <typename Container>
    typename Container::const_iterator max(const Container &container)
    {
        if (container.begin() == container.end()) return container.end();

        typename Container::const_iterator max = container.begin();

        for (typename Container::const_iterator it = ++container.begin(); it != container.end();
             ++it)
        {
            if ((*max) < (*it)) max = it;
        }
        return max;
    }

    template <typename Container>
    typename Container::const_iterator min(const Container &container)
    {
        if (container.begin() == container.end()) return container.end();

        typename Container::const_iterator min = container.begin();

        for (typename Container::const_iterator it = ++container.begin(); it != container.end();
             ++it)
        {
            if ((*min) > (*it)) min = it;
        }
        return min;
    }

    template <typename Container, typename Operator, typename Operand>
    Operand reduce(const Container &container, Operator operate, Operand base)
    {
        Operand result = base;
        for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it)
            result = operate(result, *it);
        return result;
    }

    template <typename Container>
    Container set_union(const Container &container1)
    {
        return container1;
    }

    template <typename Container>
    Container set_union(const Container &container1, const Container &container2)
    {
        if (container1.size() > 0 && container2.size() == 0)
        {
            return container1;
        }
        if (container2.size() > 0 && container1.size() == 0)
        {
            return container2;
        }
        if (container1 == container2)
        {
            return container1;
        }
        Container result;
        std::set<typename Container::value_type> uniques;
        for (auto elem : container1)
        {
            uniques.emplace(elem);
        }
        for (auto elem : container2)
        {
            uniques.emplace(elem);
        }
        for (auto elem : uniques)
        {
            result.push_back(elem);
        }
        return result;
    }

    // TODO: Do the above algorithm with all containers provided at once - instead
    // of recursively calling
    template <typename Container, typename... Containers>
    Container set_union(const Container &container1, const Container &container2, Containers... others)
    {
        return set_union(set_union(container1, container2), others...);
    }


    template <typename Container>
    int size(const Container &container)
    {
        return (container.end() - container.begin());
    }

    template <typename Iterator, typename Function>
    void transform(Iterator first_begin, Iterator first_end, Iterator second_begin,
                   Function function)
    {
        while (first_begin != first_end)
        {
            (*second_begin) = function(*first_begin);
            first_begin++;
            second_begin++;
        }
    }
}  // namespace _
