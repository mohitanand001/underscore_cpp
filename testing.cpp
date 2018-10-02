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
	std::vector<int> vector1 = {-999, 1, 3};
	std::vector<int> vector2 = {1}; 
	std::vector<int> vector3 = {-999, 1, 11, 3};
	std::vector<int> vector4 = {-3, 1, 3, 4, 5};
	std::map<int, int> mp;
	mp[1] = 3, mp[2] = 21;
	std::pair<const int, int> p {1, 3} ;
	std::unordered_set<int> s; s.insert(1); s.insert(2); s.insert(23);

	std::cout << "Contains function results:\n";
	std::cout << underscore::contains(s.begin(), s.end(), 1212) << "\n";
	std::cout << underscore::contains(mp.begin(), mp.end(), p) << "\n";

	std::cout << "min function results:\n";
	std::cout << underscore::min(vector1) - vector1.begin() << "\n";
	std::cout << *underscore::min(vector1) << "\n";

	std::cout << "max function results:\n";
	std::cout << underscore::max(vector1) - vector1.begin() << "\n";
	std::cout << *underscore::max(vector1) << "\n";

	std::cout << "Intersect function results:\n";
	std::vector<int> result = underscore::intersect(vector1, vector1, vector2, vector3);
	for(auto n : result) {
		std::cout << n << " ";
	}
	std::cout << "\n";

	std::cout << "Set_union function results:\n";
	result = underscore::set_union(vector1, vector3, vector4);
	for(auto n : result)
	{
		std::cout << n << " ";
	}
	std::cout << "\n";

	std::cout << "Difference function results:\n";
	result = underscore::difference(vector4, vector3);
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
