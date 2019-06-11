#include "job.h"
#include <iostream>
using namespace std;


Job::Job()
{

}

Job::Job(int p, string j, Customer c)
{
  priority = p;
  customer = c;
  job_details = j;
}

string Job::display() const
{
  return job_details + "\n" + customer.display_short();
}

int Job::get_priority() const{  return priority; }

void Job::assign(string n){  handler = n; }

string Job::get_handler() const
{
  return handler;
}