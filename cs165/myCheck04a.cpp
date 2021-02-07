/***********************************************************************
* Program:
*    Checkpoint 04a, Prepare          
*    Brother Comeau, CS165
* Author:
*    Yiqi Wang
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/




#include <iostream>
#include <string>
using namespace std;
/**********************************************************************
* Object Class
***********************************************************************/
class Book
{
   private:
      string title;
      string author;

   public:
      void prompt()
      {
         cout << "Title: ";
         getline(cin, title);
         cout << "Author: ";
         getline(cin, author);
      }

      void display() 
      {
         cout << "\"" + title + "\" by " + author << endl;
      }
};

/**********************************************************************
 * Main function
 ***********************************************************************/
int main()
{
   Book book;

   book.prompt();
   book.display();

   return 0;
}