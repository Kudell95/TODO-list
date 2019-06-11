#include <iostream>
#include "customer.h"
#include "job.h"
#include <vector>


using namespace std;

void displayCustomers(vector<Customer> customerList)
{
  int customerListSize = customerList.size();
  cout << "\nCustomer List...\n"; //loop through all customers and display
  
  for(int i = 0; i < customerListSize; i++)
  {
    cout << customerList[i].display_all() << "\n";
  }
  cout << "\n";
  
}

void pendingJobs(vector<Job> jobList)
{
  int jobListSize = jobList.size();
  cout << "\nPending Jobs...\n"; 
  
  for(int i = 0; i < jobListSize; i++)
  {
    cout << "\n" << jobList[i].display() << "\n";
  }
  cout << "\n";
}

void displayJobByHandler(string handler, vector<Job> jobList)
{
  int jobListSize = jobList.size();
  bool hasJob = false;
  for (int i = 0; i < jobListSize; i++)
  {
    if(handler == jobList[i].get_handler())
    {
      hasJob = true;
      cout << jobList[i].display();
    }
  }
  if(!hasJob)
  {
    cout << handler << " has no jobs today!\n";
  }
  cout << "\n";
 
}

void deleteJob(string handler, vector<Job> &jobList)
{
  int jobListSize = jobList.size();
  int jobCount = 0;
  for(int i = 0; i < jobListSize; i++)
  {
      if(jobList[i].get_handler() == handler)
      {
        jobList.erase(jobList.begin() + i);
        jobCount++;
      }
  }
  cout << jobCount << " jobs deleted";
}

Customer findCustomerByName(vector<Customer> customerList, string cust_name)
{
  int customerListSize = customerList.size();
  for (int i = 0; i < customerListSize; i++)
  {
    if(cust_name == customerList[i].get_name())
    {
      return customerList[i];
    }
  }

  return Customer();
}


void sortJobList(vector<Job> &jobList, int n)
{

  if(n == 1) //if the recursion has reached the smallest item
  {
    return; //return function, ending recursion
  }
 
    for (int i=0; i < n-1; i++) // loop through all elements
    {
        if (jobList[i].get_priority() < jobList[i+1].get_priority()) //if priority of current element is > next element
        {
            swap(jobList[i], jobList[i+1]);
        }
    }
    sortJobList(jobList, n-1);
}




bool customerIsNull(Customer customer)
{
    if(customer.get_name().empty())
    {
      return true;
    }

  return false;
}


int main()
{
  bool menuFlag = true;
  

  int jobs = 0; //number of jobs for today
  
  Customer activeCustomer;

  vector<Customer> customers;
  vector<Job> jobList;

 

  cout << "loading Customers...\n\n";

  //hard coded customer information
  customers.push_back(Customer("D David", "1 West Street", "123-456"));
  customers.push_back(Customer("A Alice", "2 North Street", "234-567"));
  customers.push_back(Customer("C Carl", "3 East Street", "345-678"));
  customers.push_back(Customer("Z Zoro", "2 North Street", "456-789"));


  cout << "Number of jobs for today: ";
  cin >> jobs;
  cin.ignore();

  
  //job declaration -----------------------------------------------------------
  for (int i = 0; i < jobs; i++) 
  {
    
    string cust_name;
    string addr;
    string account_num;
    string job_deets;
    int job_priorty;
    

    cout << "\nJob " << i + 1 << ": \n";
    cout << "Customer Name: ";
    cin.clear(); //had trouble with a return character staying in the buffer during loop, this fixes it for the time being.
    getline(cin, cust_name);
    
   
    activeCustomer = findCustomerByName(customers, cust_name); //finds customer object from string entered
    // this presumes there are no spelling mistakes TODO: set to lowercase prevent duplicates

    if(customerIsNull(activeCustomer))
    {
      cout << "Customer Address: ";
      cin.clear();
      getline(cin, addr);

      cout << "Account Number: ";
      cin.clear();
      getline(cin, account_num);

      customers.push_back(Customer(cust_name,addr,account_num));
      activeCustomer = customers.back();

    }

    cout << "\nJob Details: ";
    cin.clear();
    getline(cin, job_deets);
    cout << "Job Priority: ";
    cin.clear();
    cin >> job_priorty;
    // cin.clear();
    cin.ignore();
    jobList.push_back(Job(job_priorty, job_deets, activeCustomer));
       
  }
  //------------------------------------------------------------------------



  cout << "\nSorting Job List...\n\n";
  sortJobList(jobList, jobList.size());
  int jobListSize = jobList.size();
  // pendingJobs(jobList);

//handler assignment-----------------------------------
  for(int i = 0; i < jobListSize; i++)
  {
    string handler;
    cout << jobList[i].display();
    cout << "\nJob Handled By: "; 
    getline(cin, handler);
    jobList[i].assign(handler);
    cout << "\n";
  }
//-----------------------------------------------------  

cout << "\nManaging Job Scheduler...\n";

while(true)
{
  int menuChoice = 0;
  cout << "Menu\nSelect 1 to view our customer list\nSelect 2 to view our pending jobs\n";
  cout << "Select 3 to search for the details of job handled by a proffesional\nSelect 4 to Delete a Job\n";
  cout << "Select 5 to exit the Job Scheduler\n";

  cin >> menuChoice;

  //menu interaction ---------------
  if(menuChoice == 1){
    displayCustomers(customers);
  }else if(menuChoice == 2){
    pendingJobs(jobList);
  }else if (menuChoice == 3){
    string job_handler;
    cout << "\nDisplay job handled by: ";
    cin.clear();
    cin.ignore();
    getline(cin, job_handler);
    displayJobByHandler(job_handler,jobList);  //this was going to be a switch statement
  }else if (menuChoice == 4){         //but ran into problems when using it in a while loop.
    string job_handler;
    cout << "\nDelete job handled by: ";
    cin.clear();
    cin.ignore();
    getline(cin, job_handler);
    deleteJob(job_handler,jobList);
  }else if (menuChoice == 5){
    return 0;
  }else{
    cout << "\nInvalid Menu Choice! Select another option\n";
  }
  // ---------------------------------
    if(!menuFlag){break;}
  cin.clear();
  cin.ignore();

  
}
  
return 0;
}


