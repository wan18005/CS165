/***********************************************************************
* Program:
*    Assignment 01, GENETIC GENEALOGY          
*    Brother Comeau, CS165
* Author:
*    Yiqi Wang
* Summary: 
*    This is a program will find the whether your, 
*    DNA is matching with your relatives
*
*    Estimated:  4 hrs   
*    Actual:     4 hrs
*      It is kind of hard to remember how to do 
*      everything since I took cs 124 last year
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * Function: data input for Sequence
 * Purpose: DNA Sequence entry in as an array of size 10
 ***********************************************************************/
void inputDNA(char DNA[])  
{
   cout << "Enter your DNA sequence: ";
   cin >> DNA;
}

/**********************************************************************
 * Function: data input for potential relatives
 * Purpose: potential relatives enters in as integers 
 ***********************************************************************/
int inputRelatives()
{
   int relatives;  // call int for cin as (relatives) 
   cout << "Enter the number of potential relatives: ";
   cin >> relatives;
   cout << endl;
   return relatives;
}

/**********************************************************************
 * Function: Names for the relatives
 * Purpose: potential relatives enters in as integers 
 ***********************************************************************/
void NamesREL(char names[][256],int relatives)  
// character as double array 
{
   for (int i = 0; i < relatives; i++)  
   // for loop how many times cout goes
   {
      cout << "Please enter the name of relative #" << i + 1 << ": ";  
      // start from 1 other than 0
      cin >> names[i];  
   }
   cout << endl;
}

/**********************************************************************
 * Function: DNA enter for the relatives
 * Purpose: DNA sequence for the relatives
 ***********************************************************************/
void DNAREL(char relDNA[][10], int relatives, char names[][256])  
// bring in the relatives DNA, number of the relatives and their names 
{
   for (int i = 0 ; i < relatives; i++)   // go over the for loop
   {
      cout << "Please enter the DNA sequence for " << names[i] << ": ";   
      cin >> relDNA[i];
   // the DNA sequences from the first to the last relatives
   }
   cout << endl;
}

/**********************************************************************
 * Function: Main function
 * Purpose: Do the main things
 ***********************************************************************/
int main()
{
   char DNA[10];   // declare the DNA as a array of 10
   inputDNA(DNA);   // call the input DNA function
   int relatives; 
   relatives = inputRelatives();   
   // set relatives as the input relatives function
   char names[relatives][256]; 
   // declare name  [relatives]times  a size 256 max array
   char relDNA[relatives][10];
   // declare relatives DNA as [relatives] times a 10 array
   NamesREL(names,relatives);
   //call the function for relatives name
   DNAREL(relDNA,relatives,names);
   //call the function for the DNA for all the relatives
   
   int matching; 
   int percentage;
   for (int i = 0 ; i < relatives; i++)
   // for loop for the matching
   {
      matching = 0;
      // set matching  to zero
      cout << "Percent match for " << names[i] << ": ";
      // as usual go over how many relatives are input
      for (int j = 0; j < 10; j++)
      // another for loop this times only go over 10 times 
      //since we are comparing the 10 letter DNA Sequence
      {
         if (relDNA[i][j] == DNA[j])  
         // compare the Relative DNA with the original DNA 
         // if one letter match add one to matching 
            matching++;
         percentage = matching * 10;
         // the final percentage of matching is how many letter times 10
      }
      cout << percentage << "%\n";
      // cout the percentage 
   }
   return 0;
}                                                                     