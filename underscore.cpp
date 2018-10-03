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


template <typename Collection>
Collection intersect(Collection collection) 
{
	return collection;
}

template <typename Collection>
Collection intersect(Collection collection1, Collection collection2)
{
	Collection result;

	sort(collection1.begin(), collection1.end());
	sort(collection2.begin(), collection2.end());

	typename Collection::const_iterator first_begin = collection1.begin(), second_begin = collection2.begin();
	
	while(first_begin != collection1.end() && second_begin != collection2.end()) 
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

template <typename Collection, typename ... Collections>
Collection intersect(Collection collection1, Collection collection2, Collections ... others) 
{
	return intersect(intersect(collection1, collection2), intersect(others...));
}

	
template <typename Collection>
Collection set_union(const Collection &collection1)
{
	return collection1;
}

template <typename Collection>
Collection set_union(const Collection &collection1, const Collection &collection2)
{
  Collection result;

	sort(collection1.begin(), collection1.end());
	sort(collection2.begin(), collection2.end());

	typename Collection::const_iterator first_begin = collection1.begin(), second_begin = collection2.begin();

	while(first_begin != collection1.end() && second_begin != collection2.end()) 
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
  // if collection2 done and collection1 remains... just add the rest of
  // collection1 to end of result
  if(first_begin != collection1.end()){
    while(first_begin != collection1.end()){
      result.insert(result.end(), *first_begin);
      first_begin++;
    }
  } else { // otherwise add the rest of collection2 to the result
    while(second_begin != collection2.end()){
      result.insert(result.end(), *second_begin);
      second_begin++;
    }
  }

	return result;
}

// TODO: Do the above algorithm with all collections provided at once - instead
// of recursively calling
template <typename Collection, typename ... Collections>
Collection set_union(Collection collection1, Collection collection2, Collections ... others)
{
	return set_union(set_union(collection1, collection2), others...);
}


}
