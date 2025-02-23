#include "user.h"
using namespace std;

User::User() : name_("unknown"), balance_(0.0), type_(1)
{

}
User::User(std::string name, double balance, int type) :
    name_(name), balance_(balance), type_(type)
{

}

User::~User()
{

}


std::string User::getName() const
{
    return name_;
}

double User::getBalance() const
{
    return balance_;
}

vector<Product*>& User::getCart() 
{
	return cart_; 
}

void User::setBalance(double balance)
{
	balance_ = balance; 
}

void User::setCart(vector<Product*>& newCart){
	cart_ = newCart; 
}

void User::deductAmount(double amt)
{
    balance_ -= amt;
}

void User::dump(std::ostream& os)
{
    os << name_ << " "  << balance_ << " " << type_ << endl;
}