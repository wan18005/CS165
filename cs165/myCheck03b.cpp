/***********************************************************************
* Program:
*    Checkpoint 03b, Prepare          
*    Brother Comeau, CS165
* Author:
*    Yiqi Wang
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/**********************************************************************
 * Function: prompt user for the number input 
 * Purpose: after number is enter it then process it and return,
 * if it is unable to read clear the buffer and throw a string.
 ***********************************************************************/
int prompt()
{
   int number;
   cout << "Enter a number: ";
   cin >> number;
   if (cin.fail())
   {
      cin.clear();
      cin.ignore(256,'\n');
      throw string("Invalid input.");
   }
   return number;

}

/**********************************************************************
 * Function: Main
 * Purpose: 
 ***********************************************************************/
int main()
{
   bool T;   //set a bool for testing
   do  // do while loop
   {
      try
      {
         int number = prompt(); // call function
         cout << "The number is " << number << "." << endl;
         T = false; // we pass the test     
      }
      catch (const string Invalid)  // const for debugging 
      {
         cout << Invalid << endl;
         T = true;  // we fail
      }
   } 
   while (T);
   return 0; 
}
