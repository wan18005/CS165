/***********************************************************************
* Program:
*    Assignment 02, DIGITAL FORENSICS         
*    Brother Comeau, CS165
* Author:
*    Yiqi Wang
* Summary: 
*    This is a program that scan through that log to identify users 
*     who accessed files in a particular window of time.
*
*    Estimated:  10 hrs   
*    Actual:     15 hrs
*      It is kind of hard to use the string 
*      so I decided to do something like this 
************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#define size 256
#define Size 500
using namespace std;

/**********************************************************************
 * structure for time stamp, file name and user name
 ***********************************************************************/
struct AccessRecord
{
   long timeStamp;
   string fileName;
   string userName;
};

/**********************************************************************
 * structure for resource needed for this program
 ***********************************************************************/
struct Resource
{
   long startTime;
   long endTime;
   char accessFile[size];
   int fileLength;
   int content[Size];
   int Results;
};



/**********************************************************************
 * Prompts for enter file location
 ***********************************************************************/
void filePrompt(Resource &R)
{
   cout << "Enter the access record file: ";
   cin >> R.accessFile;
   cout << endl;
   return;
}

/**********************************************************************
 * Prompts for starting time and ending time
 ***********************************************************************/
void timePrompt(Resource &R)  // using the Resource as R
{
   cout << "Enter the start time: ";
   cin >> R.startTime;
   cout << "Enter the end time: ";
   cin >> R.endTime;
}

/**********************************************************************
 * Reads file function 
 ***********************************************************************/
int readFile(Resource &R, AccessRecord record[Size])
{
   int i = 0;  // set i as 0
   ifstream fin(R.accessFile);
   if (fin.fail()) // check to see if the file correctly opened
   {
      cout << "Unable to open: " << R.accessFile << endl;
      return 1;  // return false 
   }
   while (!fin.eof())
   {
      fin >> record[i].fileName;
      fin >> record[i].userName;
      fin >> record[i].timeStamp;
      i++;
      R.fileLength = i;
   }

   // close the file
   fin.close();
   return i;  
   // return for  in this case 0
}

/**********************************************************************
 * Searches file 
 ***********************************************************************/
void fileSearch(Resource &R, AccessRecord record[Size])
{
   int j = 0;  // set j as 0
   for (int i = 0; i < R.fileLength; i++)
   {
      if ( R.startTime 
         <= record[i].timeStamp && R.endTime 
         >= record[i].timeStamp)
      // in this range
      {
         R.content[j] = i;
         j++;
      }
   }
   R.Results = j;
}

/**********************************************************************
 * Displays results from search.
 ***********************************************************************/
void displayResults (Resource  R, AccessRecord record[Size])
{
   cout << "\nThe following records match your criteria:\n\n";
   cout << setw(15) << "Timestamp"
        << setw(20) << "File"
        << setw(20) << "User"
        << endl;
   cout << "--------------- ------------------- -------------------" << endl;

   for (int i = 0; i < R.Results; i++)
   {
      int I = R.content[i];
      cout << setw(15) << record[I].timeStamp
           << setw(20) << record[I].fileName
           << setw(20) << record[I].userName
           << endl;
   }

   cout << "End of records" << endl;
}

/**********************************************************************
 * Main function
 ***********************************************************************/
int main()
{
   Resource R; 
   // call structure
   AccessRecord record[Size];   
   // call structure
   //calling all the function 
   filePrompt(R);
   timePrompt(R);
   readFile(R, record);
   fileSearch(R, record);
   displayResults(R, record);

   return 0;
}