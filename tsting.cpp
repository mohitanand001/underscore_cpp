#include<iostream>
#include<vector>
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