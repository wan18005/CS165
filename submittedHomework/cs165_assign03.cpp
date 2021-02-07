/***********************************************************************
* Program:
*    Assignment 03, DIGITAL FORENSICS WITH CORRUPT FILES        
*    Brother Comeau, CS165
* Author:
*    Yiqi Wang
* Summary: 
*    This is a program that scan through that log to identify users 
*     who accessed files in a particular window of time.
*
*    Estimated:  4 hrs   
*    Actual:     4 hrs
*      I changed my way of doing this from assignment 2
*      , this is way more easier
************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;
#define size 256

/**********************************************************************
 * structure for time stamp, file name and user name
 ***********************************************************************/
struct accessRecord
{
   string userName;
   string fileName;
   long long timeStamp;
};


/**********************************************************************
 * This function will get the name of the file
 ***********************************************************************/
void getFilename(char filename[])
{
   cout << "Enter the access record file: ";
   cin >> filename;
}

/**********************************************************************
 * This function will get the start time and end time
 ***********************************************************************/
void getTime(long& startTime,long& endTime)
{
   cout << "Enter the start time: ";
   cin >> startTime;
   cout << "Enter the end time: ";
   cin >> endTime;
}

/***********************************************************************
 * This function will fills in the parts of the passed file, given
 *  the data found in the provided string.
 ***********************************************************************/
void parseLine(string &fileName, accessRecord record[], int& i)
{

   stringstream buffer(fileName);
   bool Test = true;
   buffer >> record[i].fileName;
   try
   {
      if (buffer.fail())
      {
         Test = false;
         throw "Error parsing line: ";
      }
      buffer >> record[i].userName;
      if (buffer.fail())
      {
         Test = false;
         throw "Error parsing line: ";
      }
      buffer >> record[i].timeStamp;

      if (buffer.fail() || record[i].timeStamp < 1000000000
             || record[i].timeStamp > 10000000000)
      {
         Test = false;
         throw "Error parsing line: ";
      }
   }
   catch (const char * message)
   {
      cout << message << fileName << endl;
   }
   i++;

}

/**********************************************************************
 * This function will read the file
 ***********************************************************************/
void readFile(char filename[], int& i, accessRecord record[])
{
   string line;
   // read the file
   ifstream fin(filename);

   // check for error
   if (fin.fail())
   {
      cout << "Error opening file " << filename << endl;
      return;
   }
   i = 0;
   while (getline(fin, line))
   {
      parseLine(line, record, i);
   }

   fin.close();

}

/**********************************************************************
 * This function will display the data asked for
 ***********************************************************************/
void displayResults(int& i, long& start, long& end, accessRecord record[])
{

   cout << endl;
   cout << "The following records match your criteria:\n";
   cout << endl;

   cout << "      Timestamp                File                User\n";
   cout << "--------------- ------------------- -------------------\n";

   // display data that is asked for
   for (int j = 0; j < i; j++)
      if (record[j].timeStamp >= start && record[j].timeStamp <= end)
      {
         cout << setw(15) << record[j].timeStamp << setw(20)
              << record[j].fileName << setw(20) << record[j].userName << endl;
      }

   cout << "End of records\n";
}

/**********************************************************************
 * Main function
 ***********************************************************************/
int main()
{
   //declare variables
   char filename[size];
   long startTime;
   long endTime;
   int i;
   // Access comes from the struct
   accessRecord record[size]; 
   // call functions
   getFilename(filename);
   readFile(filename, i, record);
   cout << endl;
   getTime(startTime,endTime);
   displayResults(i, startTime, endTime, record);
   return 0;

}


