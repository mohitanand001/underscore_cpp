#include <cstddef>
#include <algorithm>
#include "underscore.hpp"
namespace underscore{


template <typename Iterator, typename Function>
void each(Iterator begin, Iterator end, Function function)
{
	while(begin != end)
	{
		function(*begin);
		begin++;
	}
}

template <typename Iterator, typename Function>
void transform(Iterator first_begin, Iterator first_end, Iterator second_begin, Function function)
{
	while(first_begin != first_end)
	{
		(*second_begin) = function(*first_begin);
		first_begin++;
		second_begin++;
	}
}


template <typename Collection, typename Function>
Collection filter_accept(Collection &collection, Function function)
{
	Collection result;
	typename Collection::iterator first_begin, result_begin = result.begin();
	for(first_begin = collection.begin(); first_begin != collection.end(); ++first_begin)
	{
		if(function(*first_begin))
		{
			result.insert(result.end(), *first_begin);
		}
	}

	return result;
}

template <typename Collection, typename Function>
Collection filter_reject(Collection &collection, Function function)
{
	Collection result;
	typename Collection::iterator first_begin, result_begin = result.begin();
	for(first_begin = collection.begin(); first_begin != collection.end(); ++first_begin)
	{
		if(!function(*first_begin))
		{
			result.insert(result.end(), *first_begin);
		}
	}
	return result;
}

template <typename Iterator, typename Predicate>
Iterator find_if(Iterator begin, Iterator end, Predicate predicate)
{
	while(begin != end)
	{
		if(predicate(*begin))
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
	while(begin != end)
	{
		if(!predicate(*begin))
		{
			return begin;
		}
		begin++;
	}

	return end;
}

template <typename Iterator, typename Predicate>
bool every(Iterator begin, Iterator end, Predicate predicate)
{
	while(begin != end)
	{
		if(predicate(*begin) == false)
			return false;
		begin++;
	}

	return true;
}

template <typename Iterator, typename Predicate>
bool any(Iterator begin, Iterator end, Predicate predicate)
{
	while(begin != end)
	{
		if(predicate(*begin))
			return true;

		begin++;
	}

	return false;
}

template <typename Container>
typename Container::const_iterator max(const Container &container)
{
	if(container.begin() == container.end())
		return container.end();

	typename Container::const_iterator max = container.begin();

	for(typename Container::const_iterator it = ++container.begin(); it != container.end(); ++it)
	{
		if((*max) < (*it))
			max = it;
	}

	return max;
}

template <typename Container>
typename Container::const_iterator min(const Container &container)
{
	if(container.begin() == container.end())
		return container.end();

	typename Container::const_iterator min = container.begin();

	for(typename Container::const_iterator it = ++container.begin(); it != container.end(); ++it)
	{
		if((*min) > (*it))
			min = it;
	}

	return min;
}

template <typename Iterator, typename Predicate>
int count_by(Iterator begin, Iterator end, Predicate predicate)
{
	size_t count = 0;
	while(begin != end)
	{
		if(predicate(*begin))
		{
			count++;
		}
		begin++;
	}
	return count;
}

template <typename Iterator, typename Data>
bool contains(Iterator begin, Iterator end, Data data)
{
	while(begin != end)
	{
		if(*begin == data)
			return true;
		begin++;
	}

	return false;

}


template <typename Iterator, typename Data, typename X, typename Y>
bool contains(Iterator begin, Iterator end, std::pair<X, Y> p)
{

	while(begin != end)
	{

		if((*begin).first == p.first and (*begin).second == p.second)
			return true;
		begin++;
	}

	return false;

}

template <typename Container>
typename Container::const_iterator size(const Container &container)
{
		return (container.end()-container.begin())
}
