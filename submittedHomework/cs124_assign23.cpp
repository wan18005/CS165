#include <iostream>
#include <iomanip>
using namespace std;

int getNumber()
{
cout << "What multiples are we adding? ";
int number;
cin >> number;
return number;
}


int addMultiples(int multiple)
{
   int start = 0;
   int end = 100;

    for (int count = multiple; count < 100; count += multiple)
{
     start += count;
}

    return start;
}

void display(int multiple, int start)
{
 cout << "The sum of multiples of "
      << multiple
      << " less than 100 are: "
      << start
      << endl;
   return;
}


int main()
{
  int multiple = getNumber();
  int start = addMultiples(multiple);
  
  display(multiple,start);
  
  return 0;
}