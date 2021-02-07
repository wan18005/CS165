
#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

//1- Begin with the file : / home / cs165new / ta03.cpp that has code 
//similar to what you wrote last week. It has a Scripture struct with 
//a book, chapter, and verse. It also has display function.

/***********************************************************************
 * Struct: Scripture
 * Description: Holds the reference to a scripture (book, chapter, verse
 ***********************************************************************/
	struct Scripture
{
	string book;
	int chapter;
	int startVerse;
	int endVerse;
};

/***********************************************************************
 * Function: promptFile()
 * 2 - Prompt the user for the name of a file.
 ***********************************************************************/
string promptFile()
{
	string file;
	cout << "Please enter the name of the file: ";
	cin >> file;
	return file;
}

/***********************************************************************
 * Function: ReadFile
 * 3 - Open the file, check for failures, and close it.
 * 4 - Read the file one line at a time, and store each line in a string.
 ***********************************************************************/
int readFile(string &file, string scriptureFile[])
{
	ifstream fin(file);
	if (fin.fail())
	{
		cout << "Error reading file.\n";
	}
	int i = 0 ;
	while (!fin.eof())
	{
		getline(fin, scriptureFile[i]);
		i++;
	}
	//close file
	fin.close();

	return i;
}


/***********************************************************************
* Function: parseStream
* 5 - Use a stringstream to parse the line into a book, chapter, verse.
*  Store it in a Scripture struct, and pass that struct to the display 
* function.
 ***********************************************************************/
void parseStream(string scriptureFile[], int size, Scripture scripture[])
{
	stringstream buffer;
	string holder;
	for (int i = 0; i < size; i++)
	{
		buffer << scriptureFile[i];
		if (buffer.fail())
		{
			cout << "Error parsing the string\n.";
		}
		buffer >> scripture[i].book;
		//STRECHT CHALLANGE #3: Change your code to handle book names that
		// begin with a number and have a space in the book name (e.g., .
		// "1 Nephi").
		if (scripture[i].book == "1" || scripture[i].book == "2" 
			|| scripture[i].book == "3" || scripture[i].book == "4")
		{
			holder = scripture[i].book;
			buffer >> scripture[i].book;
			scripture[i].book = holder + " " + scripture[i].book;
		}
		buffer >> scripture[i].chapter >> scripture[i].startVerse >> scripture[i].endVerse;
		buffer.clear();
	}
	
}

/***********************************************************************
* Function: Display
* 5C - The file format is : "Alma 1 2" for "Alma 1:2".
************************************************************************/
void display(int size, Scripture scripture[])
{
	for (int i = 0; i < size; i++)
	{
		//STRECHT CHALLANGE #1: Change your code so that in addition to
		//the above conditions, it can also handle the case of no verses
		//at all (e.g., "Alma 31").
		cout << scripture[i].book << " " << scripture[i].chapter;

		// Strecht Challange #1: Change your code to detect verse ranges
		//that are not correct, such as "20-15" and handle them 
		//appropriately.
		if(scripture[i].startVerse > scripture[i].endVerse && 
			scripture[i].endVerse != 0)
			cout << ":" << scripture[i].endVerse << "-" 
			<< scripture[i].startVerse << endl;
		else
		{
			if (scripture[i].startVerse)
			{
				cout << ":" << scripture[i].startVerse;
			}
			// 6- Now, modify your program so that it can handle scriptures
			//with a verse range(i.e., a start verse and an end verse).
			//7- Finally, modify your program so that it can handle 
			//scriptures with a single verse OR a verse range.
			if (scripture[i].endVerse)
			{
				cout << "-" << scripture[i].endVerse << endl;
			}
			else
				cout << endl;
		}
	}
}

/***********************************************************************
* MAIN:
************************************************************************/
int main()
{
	string file = promptFile();
	string scriptureFile[50] = {};
	int lines = readFile(file, scriptureFile);
	Scripture scripture[50] = {};
	parseStream(scriptureFile, lines, scripture);
	display(lines, scripture);
	return 0;
}
