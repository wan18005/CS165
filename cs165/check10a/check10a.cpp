/***********************************************************************
* Program:
*    Checkpoint 10a, Vectors
*    Brother Comeau, CS165
* Author:
*    Yiqi Wang
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
************************************************************************/
#include <vector>
#include <string>
#include <iostream>
using namespace std;



/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{  
// Create a vector of ints.
   vector <int> intVector;
//Prompt the user for ints until they enter 0, and store them in your vector.
   int input;
//Loop through all the numbers in the vector and display each one.
   do
   {
    cout << "Enter int: ";
    cin >> input;
    if(input != 0)
           intVector.push_back(input);
   
   }
   while(input !=0);
   cout << "Your list is:\n" ;
//When you loop through, make sure to use the size of your vector in your condition (not a separate integer from above).
   for (int i = 0 ; i < intVector.size(); i++)
   {
      cout << intVector[i] << endl;
   }
    cout << endl;
   
//Create a vector of strings.
   vector <string> stringVector;
//Prompt the user for strings until they enter "quit", and store them in your vector. 
   string inputString;
   do
   {
      cout << "Enter string: " ;
      cin >> inputString;
      if (inputString != "quit")
              stringVector.push_back(inputString);
   }
   while (inputString != "quit");
   cout << "Your list is:\n" ;
//Loop through all the strings in the vector and display each one.
   for (int i = 0 ; i < stringVector.size(); i++)
   {
      cout << stringVector[i] << endl;
   }
   

   return 0;
}


