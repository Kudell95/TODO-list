#ifndef JOB_H
#define JOB_H

#include <iostream>
#include "customer.h"
using namespace std;

class Job {
public:
  Job();
  Job(int p, string j, Customer c);
  int get_priority() const;
  string display() const;
  // display Job information in format
  //Gas leak in the kitchen
  //Customer name: Alice
  //Address: 2 North Street
  void assign(string n);  // Assign a Job handler

  string get_handler() const;

  
private:
  int priority;
  string job_details;
  Customer customer;  // customer who placed the order
  string handler;  // multiple word name of Job handler
};

#endif
