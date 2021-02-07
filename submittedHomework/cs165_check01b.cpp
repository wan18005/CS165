/***********************************************************************
* Program:
*    Checkpoint 01b, Prepare            
*    Brother Comeau, CS165
* Author:
*    Yiqi Wang
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/
#include <iostream>
using namespace std;

/***********************************************************************
* get size function
* ***********************************************************************/
int getSize()
{
   int size;
   cout << "Enter the size of the list: ";
   cin >> size;
   return size;
}

/***********************************************************************
* get list function
* ***********************************************************************/
void getList(int list[], int count)
{
   for (int i = 0; i < count; i++)
   {
      cout << "Enter number for index " << i << ": ";
      cin >> list[i];
   }
}

/***********************************************************************
* display function
* ***********************************************************************/
void displayMultiples(int list[], int count)
{
   int multipleList[9];
   int counter = 0 ;
   for (int i = 0; i < count; i++)
   {  
      if (list[i] % 3 == 0)
      {
         multipleList[counter] = list[i];
         counter++;
      }
   }
   cout << "\nThe following are divisible by 3:\n";
   for (int j = 0 ; j < counter; j++)
   {
      cout << multipleList[j] << endl;
   }
}

/***********************************************************************
* main function
* ***********************************************************************/
int main()
{
   int count = getSize();
   int list[9];
   getList(list, count);
   displayMultiples(list, count);
   return 0;
}
