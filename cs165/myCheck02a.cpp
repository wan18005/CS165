/***********************************************************************
* Program:
*    Checkpoint 02a, Prepare          
*    Brother Comeau, CS165
* Author:
*    Yiqi Wang
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
using namespace std;

/***********************************************************************
* Defining a Structure 
* ***********************************************************************/
struct UserData
{
   char firstName[256];  // we have the first name
   char lastName[256];   // we have the last name
   int ID;               // and also the ID
};

/***********************************************************************
* Display function
* ***********************************************************************/
void display()
{

   UserData infor;  // call the sturcture as the infor

   cout << "Please enter your first name: ";
   cin >> infor.firstName;  // put first name inside in sturcture
   cout << "Please enter your last name: ";
   cin >> infor.lastName;    // put last name inside in sturcture
   cout << "Please enter your id number: ";
   cin >> infor.ID;      // put ID inside in sturcture
   cout << endl;
   cout << "Your information:" << endl;
   cout << infor.ID      // call the ID inside in sturcture
       << " - "
       << infor.firstName  // call first name inside in sturcture
       << " "
       << infor.lastName   // call last name inside in sturcture
       << endl;
}

/***********************************************************************
* Main function
* ***********************************************************************/
int main()
{
   display();
   return 0;
}