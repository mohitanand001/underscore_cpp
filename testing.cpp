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
	std::vector<int> vec = {1, 2, 3};
	std::vector<int> rec = {2, 34, 43};
	std::vector<int> lec = {3, 54, 1};

	std::vector<int> sec = _::set_union(vec, rec, lec);
	_::each(vec.begin(), vec.end(), display);
	std::cout << std::endl;
	_::each(rec.begin(), rec.end(), display);
	std::cout << std::endl;
	_::each(lec.begin(), lec.end(), display);
	std::cout << std::endl;

	_::each(sec.begin(), sec.end(), display);
	std::cout << std::endl;
	// std::vector<int> vec = {1, 2, 45};
	// std::vector<int> lec;
	// std::map<int, int> mp;
	// mp[1] = 3, mp[2] = 21;
	// std::pair<const int, int> p {1, 3} ;
	// std::unordered_set<int> s; s.insert(1); s.insert(2); s.insert(23);
	// std::cout << _::contains(s.begin(), s.end(), 1212) << "\n";
	// std::cout << _::contains(mp.begin(), mp.end(), p) << "\n";
	// std::vector<int> v ={-999,1,3}, c = {-999, 1, 11, 3}, x = {-999, 1, 3, 4, 5};
	// std::cout << _::min(v) - v.begin() << "\n";
	// std::cout << *_::min(v) << "\n";
	// std::cout << _::max(v) - v.begin() << "\n";
	// std::cout << *_::max(v) << "\n";
	// std::cout <<	_::size(v)<<"\n";
	// std::vector<int> result = _::intersect(v, v, c, x);
	// std::vector<int> 
	// for(auto n : result) {
	// 	std::cout << n << " ";
	// }
	// result = _::set_union(v, c, x);
	// for(auto n : result)
	// {
	// 	std::cout << n << " ";
	// }

	std::cout << std::endl;
	std::map<int, std::vector<int> > mp = _::group_by(vec, is_odd);
	for(auto it = mp.begin(); it != mp.end(); ++it)
	{
		std:: cout << (it->first) << " " ;
		for(int j = 0; j < (it->second).size(); j++)
			std::cout << (it->second)[j] << " ";
		std::cout << std::endl;
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
