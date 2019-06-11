#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
using namespace std;

class Customer {
public:
  Customer();
  Customer(string n);
  Customer(string n, string add, string acct);
  string display_short()const; // display customer info in format:
  //Customer name: Alice
  //Address: 2 North Street
  string display_all()const;
  // display customer info in format:
  //Alice, 2 North Street, 234-567
  bool operator<(Customer right)const;
  // compares Customer data member name
  string get_name()const;
private:
  string name;
  string address;
  string account_number;  // Multiple word name
};

#endif
