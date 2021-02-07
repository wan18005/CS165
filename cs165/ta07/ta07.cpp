#include <iostream>
using namespace std;

// Core requirements
float getValueFromPointer(float* thePointer)
{ 
   return *thePointer;
}
float* getMinValue(float* a, float* b)
{
     if (*a < *b)
     {
        return a;
     }
     else 
     {
        return b;
     }

}

// Stretch goals
void swapElements(float* theArray[], int a, int b)
{
     float *p1 = theArray[a];
     theArray[a] = theArray[b];
     theArray[b] = p1;



}

void sortArray(float* theArray[]);

int main()
{  
//Core Requirement 1: Dynamically allocate an array of floats to store
	// the hexcopter propeller speed. Also make sure to delete this array 
	// at the end of the program. This means you should:
	cout << "**********************************************************************************\n";
	cout << "* Core Requirement 1                                                             *\n";
	cout << "**********************************************************************************\n";
	// A - Prompt for the number of floats (see provided code).
	int arraySize;
	cout << "Enter the array size: ";
	cin >> arraySize;



	//Stretch 1 - A: Dynamically allocate an array of float pointers.
	 float **pointerArray = new float*[arraySize];
   float *pArray = new float[arraySize];
   float *pHolder;
   
  // Fill your array with float values
   for(int i = 0; i < arraySize; i++) 
   {
          cout << "Enter a float value: ";
          cin >> pArray[i];
          pHolder = &pArray[i];
          pointerArray[i] = pHolder;
   }

// Core Requirement 2

	cout << "**********************************************************************************\n";
	cout << "* Core Requirement 2 - Display Value from Pointer Function                       *\n";
	cout << "**********************************************************************************\n";
	for (int i=0 ; i < arraySize; i++)
	{
		float value = getValueFromPointer(pArray + i);
		cout << "The value of the element " << i << " is: ";
		cout << value << endl;
	}
	// Core Requirement 3

	cout << "**********************************************************************************\n";
	cout << "* Core Requirement 3 - Show Smallest Value from First and Last Element           *\n";
	cout << "**********************************************************************************\n";
	// Print the smaller of the first and last elements of the array
	float  *pointerToMin = getMinValue(&pArray[0], &pArray[arraySize - 1]);
	cout << "Smallest Number: " << *pointerToMin << endl;
   

// strect 1 
	cout << endl;
	cout << "**********************************************************************************\n";
	cout << "* Stretch Challenge 1 - Dinamic Allocation                                       *\n";
	cout << "**********************************************************************************\n";
	for (int i = 0; i < arraySize; i++)
	{
		float value = getValueFromPointer(pArray + i);
		cout << "Value of Original Array's Element " << i << " is: ";
		cout << value << endl;

		//Strecht 1 - C: Next, loop through the items in your pointer array, and use
		//the pointer to get the value and display it.
		cout << "Value for Pointer Array's Element " << i << " is: "
			<< *pointerArray[i] << " and the Address is: " << pointerArray[i] << endl;
	}
// strect 2
  cout << endl;
	cout << "**********************************************************************************\n";
	cout << "* Stretch Challange 2 - Swap values from First and Last Element                  *\n";
	cout << "**********************************************************************************\n";
	//Stretch 2 - Write a function to swap elements of the pointer array, swap the first
	// and last values, and display them. This means you need to do the following:
	swapElements(pointerArray, 0, (arraySize-1));
	for (int i = 0; i < arraySize; i++)
	{
		//Stretch 2 - C: Loop through the original array of values, display them, and ensure they 
		//               have not changed.
		float value = getValueFromPointer(pArray + i);
		cout << "The value of the original array element " << i << " is: ";
		cout << value << endl;

		//Stretch 2 - D: Loop through the array of pointers and use the pointers to display the values and ensure
		//				 that the first and last are in a different order.
		cout << "The value of the pointer array element " << i << " is: ";
		cout << *pointerArray[i] << endl;
	}
	// D - Delete the array at the end of main.
	delete[] pArray;
	delete[] pointerArray;
	return 0;
}



