#include "customer.h"
#include <iostream>

using namespace std;

Customer::Customer()
{
  // cout << "You must enter a name\n";
  // delete object to clear up memory;
  

}

Customer::Customer(string n)
{
  name = n;
  address = "unknown";
  account_number = "unknown";

}


Customer::Customer(string n, string add, string acct)
{
  name = n;
  address = add;
  account_number = acct;

}


string Customer::display_short()const
{
  return "Customer Name: " + name + "\nAddress: " + address;
}



string Customer::display_all()const
{

  return name + ", " + address + ", " + account_number;
}



bool Customer::operator<(Customer right)const
{

return true;
}

string Customer::get_name()const { return name; }
// display customer info in format:
//Alice, 2 North Street, 234-567
