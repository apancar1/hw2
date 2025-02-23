#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include "datastore.h"
#include "util.h"
#include "book.h"
#include "clothing.h"
#include "movie.h"
#include <map>

class MyDataStore : public DataStore{
  // class needs to support everything from parent: destructor, addProd, addUser, search, dump
  // other things: use set intersection and set union for search 
  // add, viewcart, buy cart 
  // want to store products and users in container objects in this class 
  // cart should be maintained in FIFO (do not have ability to remove from cart)
  // if product added in cart again, treat it separatly (dont make quantity 2)
  // each add command adds ONE product 
  // for add, if username or hit_result_index not provided/invalid --> print Invalid request 
  // viewing cart: 
  // prints products in username's cart at the time 
  // number the products! 
  // if username is invalid, print invalid username 
  // buy cart: 
  // loop through items in cart
  // if item in stock AND user has enough money --> remove from cart & reduce stock quantity by 1, deduct price from credit 
  // if not in stock OR user does not have enough money, leave it in cart and go to next item 
  // must iterate in order of the items being added 
  // if username is invalid, print Invalid username 
  // this file just takes care of the database 

  // do vector for products --> maintains order & can iterate 
  // do set for users --> avoids duplication & can use .find 
  public: 
    MyDataStore();
    ~MyDataStore() override; 

    void addProduct(Product* p) override; 

    void addUser(User* u) override; 

    std::vector<Product*> search(std::vector<std::string>& terms, int type) override; 

    void dump(std::ostream& ofile) override; 

    std::map<std::string, User*>& getUsers(); 

    std::vector<Product*> getSearchResults() const; 

  protected: 
    std::set<Product*> products_; 
    std::map<std::string, User*> users_; 
    std::vector<Product*> searchResults_; 
		std::map<std::string, std::set<Product*>> keywordMap_; 

};

#endif 