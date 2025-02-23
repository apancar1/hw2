#include <sstream>
#include <iomanip>
#include "clothing.h"
#include "util.h"

using namespace std; 

Clothing::Clothing(const std::string name, double price, int qty, std::string size, std::string brand) :
    Product("clothing", name, price, qty),
    size_(size),
    brand_(brand)
{

}

std::string Clothing::getSize() const
{
  return size_; 
}

std::string Clothing::getBrand() const
{
  return brand_; 
}

Clothing::~Clothing()
{

}

std::set<std::string> Clothing::keywords() const
{
  std::set<std::string> finalkeywords = parseStringToWords(name_);
  std::set<std::string> nextkey = parseStringToWords(brand_);
  finalkeywords.insert(nextkey.begin(), nextkey.end());
  return finalkeywords; 
}

std::string Clothing::displayString() const
{
  return name_ + "\nSize: " + size_ + " Brand: " + brand_ + "\n" + std::to_string(price_) + " " + std::to_string(qty_) + " left." + "\n"; 
}

void Clothing::dump(std::ostream& os) const 
{
  os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << size_ << "\n" << brand_ << endl;
}