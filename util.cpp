#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
  set<string> allwords; 
  // create the set that will contain all the words 
  string curword; 
  // variable that keeps track of the current word 
  size_t num = rawWords.size(); 
  // determine how long to iterate  
  for (size_t i = 0; i < num; i++){
    // loop through all words (including the last one)
    if(std::isalnum(rawWords[i]) || (rawWords[i] == '-' && i > 0 && i < num-1 && std::isalnum(rawWords[i-1]) && std::isalnum(rawWords[i+1]))){
      // check if the word is in bounds (bc of while loop condition)
      // also check if the word is alphanumeric 
      curword += convToLower(std::string(1, rawWords[i]));
      // make it lowercase (this is so it can be case insensitive)
    }
    else {
			if (curword.size() >= 2 || (curword.size() == 1 && std::isdigit(curword[0]))){
      // this runs if not alphanumeric or in the range and it has punct 
      	allwords.insert(curword);
        // check if it is the appropriate length 
			}
      curword.clear(); 
      // reset 
    }
  }
  if (curword.size() >= 2 || (curword.size() == 1 && std::isdigit(curword[0]))){
    // this is for the last word 
    allwords.insert(curword);
  }
  // if (rawWords.size() >= 2 && curword.empty()){
  //   // THIS IS FOR ISBN and movoe grenes (they have different requirements as specified)
  //   allwords.insert(rawWords);
  // }
  return allwords;
}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
