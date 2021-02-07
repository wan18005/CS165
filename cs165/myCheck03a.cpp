/***********************************************************************
* Program:
*    Checkpoint 03a, Prepare          
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
 * Function: prompt user for the number 
 * Purpose: after number is enter it then process it showing string
 ***********************************************************************/
int prompt()
{
	int number = 0 ;
	cout << "Enter a number: ";
	cin >> number;

		if (number < 0)
	
			throw string("The number cannot be negative.");

		else if (number > 100)
		
			throw string("The number cannot be greater than 100.");


		else if (number % 2 != 0)

			throw string("The number cannot be odd.");


	return number;
}
/**********************************************************************
 * Function: Main
 * Purpose: to try the prompt until the sting message 
 * is different it catch that and show error
 ***********************************************************************/
int main()
{

	try
	{
		
		int number = prompt();
		cout << "The number is " << number << "."<<endl;

	}

	catch (const string message)
	{
		cout << "Error: " << message << endl;
	}

	return 0;
}