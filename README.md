# underscore_cpp
Inspired by [underscore.js](https://underscorejs.org) <br>
## Table of contents:
* [Implementations](./README.md#implementation-of)
* [How to run the file](./README.md#setup)
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
- [x] count_by
- [x] contains
- [x] max
- [x] min
- [x] intersect
- [x] union
- [x] size
## Setup
1. Clone the project using `git clone https://github.com/farziengineer/underscore_cpp` 
2. To run the project you can individually compile the files(.cpp) and link them, or just run the bash file `runn.sh` 
   using `bash runn.sh (on Linux)`. 
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
_::transform(vec, increment_by_one);
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
_::filter_accept(vec, is_odd);
_::each(vec, display);
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
_::filter_reject(vec, is_odd);
_::each(vec, display);
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
std:: cout <<< _::every(vec, is_odd) - vec.begin() << std::endl;
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

### count_by
```C++
int is_odd(int x)
{
   return x % 2 == 1;
}

std::vector<int> vec = {2, 4, 5}; 
std:: cout <<< _::count_by(vec, is_odd)<< std::endl;
```
Output:  2 (counts occurrences where the container returns true over predicate. Here the predicate is is_odd)

### contains
```C++

std::vector<int> vec = {2, 4, 5}; 
std:: cout <<< _::any(vec, 9)<< std::endl;
```
Output:  false (returns true if any container element return true over predicate)

### max
```C++
std::vector<int> vec = {2, 4, 5}; 
std:: cout <<< _::max(vec)<< std::endl;
```
Output:  5

### min
```C++
std::vector<int> vec = {2, 4, 5}; 
std:: cout <<< _::max(vec)<< std::endl;
```
Output:  2



## Contribution Guidelines
For contributing fork the repository make the appropriate changes and create a pull request. Before starting to work on an issue, please ask it to be assigned to yourself, since we do not want more than one person to work on the same issue.
