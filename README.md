# underscore_cpp
Inspired by [underscore.js](https://underscorejs.org) <br>
## Table of contents:
* [Implementations](#implementation-of)
* [Setup and Build](#setup-and-build)
* [Usage](./README.md#usage)
* [Contribution Guidelines](./README.md#contribution-guidelines)

<pre>
┬ ┬┌┐┌┌┬┐┌─┐┬─┐┌─┐┌─┐┌─┐┬─┐┌─┐    ┌─┐┌─┐┌─┐
│ ││││ ││├┤ ├┬┘└─┐│  │ │├┬┘├┤     │  ├─┘├─┘
└─┘┘└┘─┴┘└─┘┴└─└─┘└─┘└─┘┴└─└─┘────└─┘┴  ┴  
</pre>
## Implementation of 
- [x] each
- [x] transform
- [x] filter_accept
- [x] filter_reject
- [x] find_if
- [x] find_if_not
- [x] every
- [x] reduce
- [x] count_by
- [x] contains
- [x] max
- [x] min
- [x] intersect
- [x] union
- [x] size
## Setup and build
1. Clone the project using `git clone https://github.com/farziengineer/underscore_cpp` 
2. To first configure the project build you will need cmake (3.8 or higher), from the project's root directory type `cmake .`
3. To build type `make -j 4`

The build will create a shared library:
 - `libunderscore_shared.so` (linux)
 - `libunderscore_shared.dylib` (macos)
 - `libunderscore_shared.dll` (windows)
 
And an executable for the tests `underscore_tests`  
## Usage

### each
```C++
void display(int x)
{
   cout << x << " ";
}

std::vector<int> vec = {1, 2, 3};

_::each(vec, display);
```
Output: 1 2 3

### transform
```C++
int increment_by_one(int x)
{
   return x + 1;
}

void display(int x)
{
   cout << x << " ";
}

std::vector<int> vec = {1, 2, 3}; 
_::transform(vec.begin(), vec.end(), increment_by_one);
_::each(vec, display);
```
Output: 2 3 4 

### filter_accept
```C++
int is_odd(int x)
{
   return x % 2 == 1;
}

void display(int x)
{
   cout << x << " ";
}

std::vector<int> vec = {1, 2, 3}; 
std::vector<int> res = _::filter_accept(vec, is_odd);
_::each(res, display);
```
Output: 1 3 

### filter_reject
```C++
int is_odd(int x)
{
   return x % 2 == 1;
}

void display(int x)
{
   cout << x << " ";
}

std::vector<int> vec = {1, 2, 3}; 
std::vector<int> res = _::filter_reject(vec, is_odd);
_::each(res, display);
```
Output: 2 

### find_if
```C++
int is_odd(int x)
{
   return x % 2 == 1;
}

void display(int x)
{
   cout << x << " ";
}

std::vector<int> vec = {2, 4, 5}; 
int index = _::find_if(vec, is_odd) - vec.begin();
std::cout << vec[index];
```
Output:  5

### find_if_not
```C++
int is_odd(int x)
{
   return x % 2 == 1;
}

void display(int x)
{
   cout << x << " ";
}

std::vector<int> vec = {1, 2, 4, 5}; 
int index = _::find_if_not(vec, is_odd) - vec.begin();
std::cout << vec[index];
```
Output:  2 (returns first index where the container value returns a false over predicate)

### every
```C++
int is_odd(int x)
{
   return x % 2 == 1;
}

std::vector<int> vec = {3, 7, 5}; 
std:: cout <<< _::every(vec, is_odd) << std::endl;
```
Output:  true (returns true if every container element return true over predicate)

### any
```C++
int is_odd(int x)
{
   return x % 2 == 1;
}

std::vector<int> vec = {2, 4, 5}; 
std:: cout <<< _::any(vec, is_odd)<< std::endl;
```
Output:  true (returns true if any container element return true over predicate)

### reduce
```C++
int multiply(int x, int y)
{
	return x * y;
}

std::vector<int> vec = {1, 2, 3, 4, 5};
std::cout << _::reduce(vec, multiply, 1) << std::endl;
```
Output:  120 (applies a function of two arguments cumulatively to the items of an iterable, from left to right, so as to reduce the sequence to a single value)

### count_by
```C++
int is_odd(int x)
{
   return x % 2 == 1;
}

std::vector<int> vec = {2, 4, 5}; 
std:: cout << _::count_by(vec, is_odd) << std::endl;
```
Output:  2 (counts occurrences where the container returns true over predicate. Here the predicate is is_odd)

### contains
```C++

std::vector<int> vec = {2, 4, 5}; 
std:: cout <<< _::contains(vec, 9)<< std::endl;
```
Output:  false (returns true if any container element return true over predicate)

### max
```C++
std::vector<int> vec = {2, 4, 5}; 
std:: cout << _::max(vec)<< std::endl;
```
Output:  5

### min
```C++
std::vector<int> vec = {2, 4, 5}; 
std:: cout << _::max(vec)<< std::endl;
```
Output:  2

### size
```C++
std::vector<int> vec = {2, 4, 5};
std::cout << _::size(vec)<< std::endl;
```
Output: 3


## Contribution Guidelines
For contributing fork the repository make the appropriate changes and create a pull request. Before starting to work on an issue, please ask it to be assigned to yourself, since we do not want more than one person to work on the same issue.
