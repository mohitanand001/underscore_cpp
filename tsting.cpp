#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include <bits/stdc++.h>
#include "underscore.cpp"

void display(int x)
{
	std:: cout << x << " " ;
}

int incr(int x)
{
	x = x + 1;
	return x;
}

int mulp(int x)
{
	return x*10;
}

bool is_odd(int x)
{
	return x % 2 == 1;
}

int main()
{
	std::vector<int> vec = {1, 2, 45}; 
	std::vector<int> lec;
	std::map<int, int> mp; 
	mp[1] = 3, mp[2] = 21;
	std::pair<const int, int> p {1, 3} ;
	std::unordered_set<int> s; s.insert(1); s.insert(2); s.insert(23);
	std::cout << underscore::contains(s.begin(), s.end(), 1212);
	std::cout << underscore::contains(mp.begin(), mp.end(), p);
	std::vector<int> v ={-999,1,3}, c = {1,3,5}, x = {-10,2,-999,3,5, -2};
	std::cout << underscore::min(v) - v.begin();
	std::cout << *underscore::min(v);
	std::cout << underscore::max(v) - v.begin();
	std::cout << *underscore::max(v) << "\n";
	std::vector<int> result = underscore::set_union(v, c, x);
	for(auto n : result)
	{
		std::cout << n << " ";
	}
	// auto x = std::find(mp.begin(), mp.end(), p) != mp.end();
	// std::cout << x << std::endl;
	// std::cout << x << std::endl;


	// std::cout << contains(vec.begin(), vec.end(), 1);

	// each(vec.begin(), vec.end(), display);
	// each(vec.begin(), vec.end(), incr);
	// each(vec.begin(), vec.end(), display);

	// transform(vec.begin(), vec.end(), lec.begin(), incr);
	// each(lec.begin(), lec.end(), display);
	// std::cout << std::endl;
	// transform(vec.begin(), vec.end(), lec.begin(), mulp);
	// each(lec.begin(), lec.end(), display);

	// lec = filter_accept(vec, is_odd);
	// each(lec.begin(), lec.end(), display);
	// std::cout << std::endl;

	// lec = filter_reject(vec, is_odd);
	// each(lec.begin(), lec.end(), display);
	// std::cout << std::endl;

	return 0;
}	
