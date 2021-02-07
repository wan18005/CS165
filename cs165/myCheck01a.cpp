/***********************************************************************
* Program:
*    Checkpoint 01a, Prepare          (e.g. Checkpoint 01a, review)  
*    Brother Comeau, CS165
* Author:
*    Yiqi Wang
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   string name;
   float age;
   cout << "Hello CS 165 World!" << endl;
   cout << "Please enter your first name: ";
   cin >> name;
   cout << "Please enter your age: ";
   cin >> age;
   cout << "\n" << "Hello " << name << ", " 
      << "you are " << age << " years old." << endl;
   return 0;
   
}
