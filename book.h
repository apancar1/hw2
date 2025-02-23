#ifndef BOOK_H
#define BOOK_H
#include "product.h"
// all necessary declarations all in product.h so it will be here too

class Book : public Product{
  public: 
    Book(const std::string name, double price, int qty, std::string isbn, std::string author);
    // this is a constructor for the class 
    ~Book(); 
    // destructor

    // copy over the rest of class from product.h (except isMatch)
    // add override at end 
    std::set<std::string> keywords() const;

    std::string displayString() const; 

    void dump(std::ostream& os) const; 

    // need to add accessors for new vars 
    std::string getisbn() const; 
    std::string getAuthor() const; 

  private: 
    // these are the new vars 
    std::string isbn_; 
    std::string author_; 
};

#endif