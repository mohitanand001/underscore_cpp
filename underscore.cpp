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


template <typename Container, typename Function>
Container filter_accept(Container &container, Function function)
{
	Container result;
	typename Container::iterator first_begin, result_begin = result.begin();
	for(first_begin = container.begin(); first_begin != container.end(); ++first_begin)
	{
		if(function(*first_begin))
		{
			result.insert(result.end(), *first_begin);
		}
	}

	return result;
}

template <typename Container, typename Function>
Container filter_reject(Container &container, Function function)
{
	Container result;
	typename Container::iterator first_begin, result_begin = result.begin();
	for(first_begin = container.begin(); first_begin != container.end(); ++first_begin)
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
int  size(const Container &container)
{
		return( container.end()-container.begin() );
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

	typename Container::const_iterator first_begin = container1.begin(), second_begin = container2.begin();

	while(first_begin != container1.end() && second_begin != container2.end())
	{
		if(*first_begin == *second_begin)
		{
			result.insert(result.end(), *first_begin);
			first_begin++;
			second_begin++;
		}
		else if(*first_begin > *second_begin)
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

template <typename Container, typename ... containers>
Container intersect(Container container1, Container container2, containers ... others)
{
	return intersect(intersect(container1, container2), intersect(others...));
}


template <typename Container>
Container set_union(const Container &container1)
{
	return container1;
}

template <typename Container>
Container set_union(const Container &container1, const Container &container2)
{
  Container result;

	sort(container1.begin(), container1.end());
	sort(container2.begin(), container2.end());

	typename Container::const_iterator first_begin = container1.begin(), second_begin = container2.begin();

	while(first_begin != container1.end() && second_begin != container2.end())
	{
		if(*first_begin == *second_begin)
		{
			result.insert(result.end(), *first_begin);
			first_begin++;
			second_begin++;
		}
		else if(*first_begin > *second_begin)
		{
			result.insert(result.end(), *second_begin);
			second_begin++;
		}
		else
		{
			result.insert(result.end(), *first_begin);
			first_begin++;
		}
	}
  // if container2 done and container1 remains... just add the rest of
  // container1 to end of result
  if(first_begin != container1.end()){
    while(first_begin != container1.end()){
      result.insert(result.end(), *first_begin);
      first_begin++;
    }
  } else { // otherwise add the rest of container2 to the result
    while(second_begin != container2.end()){
      result.insert(result.end(), *second_begin);
      second_begin++;
    }
  }

	return result;
}

// TODO: Do the above algorithm with all containers provided at once - instead
// of recursively calling
template <typename Container, typename ... containers>
Container set_union(const Container &container1, const Container &container2, const containers & ... others)
{
	return set_union(set_union(container1, container2), others...);
}


}
