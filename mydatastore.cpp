#include <sstream> 
#include <iomanip> 
#include "mydatastore.h"
#include "datastore.h"

using namespace std; 

MyDataStore::MyDataStore()
{

}

MyDataStore::~MyDataStore()
{
  //set<Product*>::iterator it1 = products_.begin(); 
  for (set<Product*>::iterator it = products_.begin(); it != products_.end(); ++it){
    delete *it; 
  }
  //map<string, User*>::iterator it2 = users_.begin(); 
  for (map<string, User*>::iterator it = users_.begin(); it != users_.end(); ++it){
    delete it->second;
    // deletes the user 
    //++it2;
  }
}

void MyDataStore::addProduct(Product* p)
{
 if ( p == nullptr){
	return; 
 }
 products_.insert(p);
 set<string> keywords = p->keywords(); 
 for (string word : keywords){
	keywordMap_[word].insert(p);
 } 
}

void MyDataStore::addUser(User* u)
{
  users_[convToLower(u->getName())] = u;
}

vector<Product*> MyDataStore::search(vector<string>& terms, int type)
{
  vector<Product*> results; 
	// set<Product*> result; 
  if (terms.empty()){
    return results; 
  }
	string cur = convToLower(terms[0]);
	set<Product*> prodset;
	if (keywordMap_.find(cur) != keywordMap_.end()){
		prodset = keywordMap_[cur];
	}
	else{
		return results; 
		// no products found 
	}
  for (size_t i = 1; i < terms.size(); i++){
		string cur = convToLower(terms[i]);
		if (keywordMap_.find(cur) != keywordMap_.end()){
			set<Product*> curset = keywordMap_[cur]; 
			if (type == 0){
				prodset = setIntersection(prodset, curset);
			}
			else if (type == 1){
				prodset = setUnion(prodset, curset);
			}
		}
		else{
			if (type == 1){
				continue; 
			}
			else{ 
				return results; 
			}
			//return results; 
			// no prods found 
		}
  }
	for (set<Product*>::iterator it = prodset.begin(); it != prodset.end(); ++it){
		results.push_back(*it); 
	}
	return results; 
}

void MyDataStore::dump(ostream& ofile)
{
  ofile << "<products>" << endl; 
  for (Product* product : products_){
    product->dump(ofile);
  }
  ofile << "</products>" << endl; 

  ofile << "<users>" << endl; 
  size_t numUsers = users_.size(); 
  map<string, User*>::iterator it3 = users_.begin(); 
  for (size_t k = 0; k < numUsers; k++){
    it3->second->dump(ofile);
    ++it3; 
  }
  ofile << "</users>" << endl; 
}

map<string,User*>& MyDataStore::getUsers()
{
  return users_;
}

vector<Product*> MyDataStore::getSearchResults() const
{
  return searchResults_; 
}