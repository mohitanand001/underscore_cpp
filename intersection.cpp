#include <bits/stdc++.h>
using namespace std; 
  
// The main function that receives a set of sets as parameter and 
// returns a set containing intersection of all sets 
vector <int> getIntersection(vector < vector <int> > &sets) 
{ 
    vector <int> result;  // To store the reaultant set 
    int smallSetInd = 0;  // Initialize index of smallest set 
    int minSize = sets[0].size(); // Initialize size of smallest set 
  
    // sort all the sets, and also find the smallest set 
    for (int i = 1 ; i < sets.size() ; i++) 
    { 
        // sort this set 
        sort(sets[i].begin(), sets[i].end()); 
  
        // update minSize, if needed 
        if (minSize > sets[i].size()) 
        { 
            minSize = sets[i].size(); 
            smallSetInd = i; 
        } 
    } 
  
    map<int,int> elementsMap; 
  
    // Add all the elements of smallest set to a map, if already present, 
    // update the frequency 
    for (int i = 0; i < sets[smallSetInd].size(); i++) 
    { 
        if (elementsMap.find( sets[smallSetInd][i] ) == elementsMap.end()) 
            elementsMap[ sets[smallSetInd][i] ] = 1; 
        else
            elementsMap[ sets[smallSetInd][i] ]++; 
    } 
  
    // iterate through the map elements to see if they are present in 
    // remaining sets 
    map<int,int>::iterator it; 
    for (it = elementsMap.begin(); it != elementsMap.end(); ++it) 
    { 
        int elem = it->first; 
        int freq = it->second; 
  
        bool bFound = true; 
  
        // Iterate through all sets 
        for (int j = 0 ; j < sets.size() ; j++) 
        { 
            // If this set is not the smallest set, then do binary search in it 
            if (j != smallSetInd) 
            { 
                // If the element is found in this set, then find its frequency 
                if (binary_search( sets[j].begin(), sets[j].end(), elem )) 
                { 
                   int lInd = lower_bound(sets[j].begin(), sets[j].end(), elem) 
                                                            - sets[j].begin(); 
                   int rInd = upper_bound(sets[j].begin(), sets[j].end(), elem) 
                                                            - sets[j].begin(); 
  
                   // Update the minimum frequency, if needed 
                   if ((rInd - lInd) < freq) 
                       freq = rInd - lInd; 
                } 
                // If the element is not present in any set, then no need  
                // to proceed for this element. 
                else
                { 
                    bFound = false; 
                    break; 
                } 
            } 
        } 
  
        // If element was found in all sets, then add it to result 'freq' times 
        if (bFound) 
        { 
            for (int k = 0; k < freq; k++) 
                result.push_back(elem); 
        } 
    } 
    return result; 
} 
  
// A utility function to print a set of elements 
void printset(vector <int> set) 
{ 
    for (int i = 0 ; i < set.size() ; i++) 
        cout<<set[i]<<" "; 
} 
  
  
// Test case 
void TestCase1() 
{ 
    vector < vector <int> > sets; 
    vector <int> set1; 
    set1.push_back(1); 
    set1.push_back(1); 
    set1.push_back(2); 
    set1.push_back(2); 
    set1.push_back(5); 
  
    sets.push_back(set1); 
  
    vector <int> set2; 
    set2.push_back(1); 
    set2.push_back(1); 
    set2.push_back(4); 
    set2.push_back(3); 
    set2.push_back(5); 
    set2.push_back(9); 
  
    sets.push_back(set2); 
  
    vector <int> set3; 
    set3.push_back(1); 
    set3.push_back(1); 
    set3.push_back(2); 
    set3.push_back(3); 
    set3.push_back(5); 
    set3.push_back(6); 
  
    sets.push_back(set3); 
  
    vector <int> r = getIntersection(sets); 
  
    printset(r); 
  
} 
  
// Driver program to test above functions 
int main() 
{ 
    TestCase1(); 
    return 0; 
} 