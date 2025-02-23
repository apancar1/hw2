#include <sstream> 
#include <iomanip> 
#include "movie.h"
#include "util.h"

using namespace std; 

Movie::Movie(const std::string name, double price, int qty, std::string genre, std::string rating) :
    Product("movie", name, price, qty),
    genre_(genre),
    rating_(rating)
{

}

Movie::~Movie()
{

}

std::string Movie::getGenre() const
{
  return genre_; 
}

std::string Movie::getRating() const
{
  return rating_;
}

std::set<std::string> Movie::keywords() const 
{
  std::set<std::string> firstkey = parseStringToWords(name_);
  std::set<std::string> nextkey = parseStringToWords(genre_); 
  std::set<std::string> finalkeywords = setUnion(firstkey, nextkey);
  return finalkeywords;
}

std::string Movie::displayString() const
{
  return name_ + "\nGenre: " + genre_ + " Rating: " + rating_ + "\n" + std::to_string(price_) + " " + std::to_string(qty_) + " left." + "\n"; 
}

void Movie::dump(std::ostream& os) const
{
  os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << genre_ << "\n" << rating_ << endl;
}