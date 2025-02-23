#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>


/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates).
 *  Both functions should run in time O(n*log(n)) and not O(n^2)
 */
template <typename T>
std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2)
{
  // general idea for this: have two iterators, compare them to each other 
  // move one at a time or both at a time (with if else statements)
  // while loop would be n and statements aere log n 
  // since the sets are ordered, you can move dorward or back to compensate
  // this means that you do not have to continuously loop 
  std::set<T> intersected; 
  // stores the final 
  typename std::set<T>::iterator it1 = s1.begin(); 
  typename std::set<T>::iterator it2 = s2.begin(); 
  // declare iterators 
  //create while loop that iterates both iterators now 
  while(it1 != s1.end() && it2 != s2.end()){
    if (*it1 > *it2){
      // increment it2 up 
      ++it2;
    }
    if (*it2 > *it1){
      // increment it1 up 
      ++it1;
    }
    if (*it1 == *it2){
      // this is if they are equal which means they have intersected
      intersected.insert(*it1);
      ++it1;
      ++it2; 
    }
  }
  return intersected; 
  // return result 
}
template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
{
  // idea for this code: start with one set that is already set 1 
  // loop through set 2 and use insert to add anything that was not also in set 1 
  // insert allow so there is no duplicates 
  std::set<T> unioned = s1; 
  // create final that begins as s1 
  typename std::set<T>::iterator it = s2.begin(); 
  // iterator for set 2 
  while (it != s2.end()){
    unioned.insert(*it);
    ++it;
  }
  return unioned; 
}

/***********************************************/
/* Prototypes of functions defined in util.cpp */
/***********************************************/

std::string convToLower(std::string src);

std::set<std::string> parseStringToWords(std::string line);

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// Removes any leading whitespace
std::string &ltrim(std::string &s) ;

// Removes any trailing whitespace
std::string &rtrim(std::string &s) ;

// Removes leading and trailing whitespace
std::string &trim(std::string &s) ;
#endif
