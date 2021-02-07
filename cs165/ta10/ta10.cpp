#include <iostream>
#include <vector>
using namespace std;

void promptNumbers(vector<int> & numbers)
{
  int number;
  do
  {
   cout << "Enter a number :"
   cin >> number;
   
   
   if (number !=0)
   {
    numbers.push_back(number);
   }
  }
  while (number != 0);
}

void displayNumbers(vector<int> & numbers)
{
   cout << " The contents of the vector are :"
   for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
	{
		cout << *it << endl;
	}
}


void removeOdds(vector<int> & numbers)
{
	cout << "\nRemoving odd numbers...\n";

	vector<int>::iterator it = numbers.begin();

	while (it != numbers.end())
	{
		if (*it % 2 != 0)
		{
			// The number is not divisible by 2, so remove it
			it = numbers.erase(it);

			// This will automatically advance the iterator to the next spot,
			// so if this were in a for loop with "it++" at the end, we would
			// be in trouble.
		}
		else
		{
			// Nothing was erased, in this case, advance the iterator
			it++;
		}
	}
}

/**********************************************************
 * Function: main
 * Description: Calls the functions to prompt and display
 *  the vector of numbers.
 **********************************************************/
int main()
{
	vector<int> numbers;

	// First get the numbers from the user
	promptNumbers(numbers);

	// Display the contents of the list
	displayNumbers(numbers);

	// Remove any odd numbers
	removeOdds(numbers);

	// Display the cotents again
	displayNumbers(numbers);

	return 0;
}