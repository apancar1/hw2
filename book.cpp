#include <sstream>
#include <iomanip>
#include "book.h"
#include "util.h"
// need to include this for the keywords function

using namespace std; 

Book::Book(const std::string name, double price, int qty, std::string isbn, std::string author) :
    Product("book", name, price, qty),
    isbn_(isbn),
    author_(author)
{

}

Book::~Book()
{

}

std::string Book::getisbn() const
{
  return isbn_; 
}

std::string Book::getAuthor() const
{
  return author_; 
}

std::set<std::string> Book::keywords() const
{
  // function should return appropriate keywords that should be associated w book 
  // includes: everything in product name, words in author's name, isbn number
  // call the function already written in util 
  std::set<std::string> finalkeywords = parseStringToWords(name_);
  // set to return at end, can alreayd vegin it with one requirement
  std::set<std::string> nextkey = parseStringToWords(author_);
  finalkeywords.insert(nextkey.begin(), nextkey.end());
  // add the authors part in 
  finalkeywords.insert(isbn_);
  return finalkeywords;
}

std::string Book::displayString() const
{
  return name_ + "\nAuthor: " + author_ + " ISBN: " + isbn_ + "\n" + std::to_string(price_) + " " + std::to_string(qty_) + " left." + "\n"; 
}

void Book::dump(std::ostream& os) const 
{
  os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << isbn_ << "\n" << author_ << endl;
}