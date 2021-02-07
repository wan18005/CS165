/***********************************************************************
* Program:
*    Test 4, copy string     
*    Brother Clements, CS124
* Author:
*    Yiqi Wang
* Summary: 
************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cassert>
using namespace std;






/**********************************************************************
* Main
***********************************************************************/
int main(int argc, char ** argv)
{
   string text;
   if (argc > 1)
      text = argv[1];
   else
   {
      text = getText();
   }
   display(text);
   return 0;
   

   switch (argc)
   {
      case 1:
         text = getText();
         break;
      case 2:
         text = argv[1];
         break;
      default:
         display(text);
         return 1;
   }


}

/**********************************************************************
* string
***********************************************************************/
string getText()
{
   string text;
   cout << "Please enter a string: ";
   cin >> text;
   return text;
}

/**********************************************************************
* display
***********************************************************************/
void display(string text)
{
   cout << "The string is: \"";
   cout << text;
   cout << "\"" << endl;
}