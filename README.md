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

underscore::each(vec, display);
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
underscore::transform(vec, increment_by_one);
underscore::each(vec, display);
```
Output: 2 3 4 

## Contribution Guidelines
For contributing fork the repository make the appropriate changes and create a pull request. Before starting to work on an issue, please ask it to be assigned to yourself, since we do not want more than one person to work on the same issue.
