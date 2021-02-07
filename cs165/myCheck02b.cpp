/***********************************************************************
* Program:
*    Checkpoint 02b, Complex Numbers
*    Brother Comeau, CS165
* Author:
*    Yiqi Wang
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
using namespace std;
/***********************************************************************
* // TODO: Define your Complex struct here 
* ***********************************************************************/
struct Complex
{
   double realNumber;
   double imaginaryNumber;
};

/***********************************************************************
* // TODO: Add your prompt function here
* ***********************************************************************/
Complex prompt()
{
   Complex input;
   cout << "Real: ";
   cin >> input.realNumber;
   cout << "Imaginary: ";
   cin >> input.imaginaryNumber;

   return input;
}



/***********************************************************************
* TODO: Add your display function here 
* ***********************************************************************/
void display(Complex input)
{
   cout << input.realNumber << " + " << input.imaginaryNumber << "i";

}

/**********************************************************************
 * Function: addComplex
 * Purpose: Adds two complex numbers together and returns the sum.
 ***********************************************************************/
Complex addComplex(const Complex &x, const Complex &y)
{
   // TODO: Fill in the body of the add function
   Complex total;
   total.imaginaryNumber = x.imaginaryNumber + y.imaginaryNumber;
   total.realNumber = x.realNumber + y.realNumber;

   return total;

}


/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   // Declare two Complex objects, c1 and c2
   Complex c1;
   Complex c2;

   // Call your prompt function twice to fill in c1, and c2 
   c1 = prompt();
   c2 = prompt();
   

   // Declare another Complex for the sum
   Complex sum;

   // Call the addComplex function, putting the result in sum;
   sum = addComplex(c1,c2);
   
   cout << "\nThe sum is: ";
   display(sum);
   cout << endl;
 
   return 0;
}
