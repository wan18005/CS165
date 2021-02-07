/***********************************************************************
* Program:
* Assignment teach02
* Brother      , CS165
* Author:
* Elias Ramirez
*
* Instructions:
* As a team, create a struct for a scripture that contains a book, 
* chapter, and verse. Then, write a function to display a scripture, and
* one to prompt for a scripture.
************************************************************************/
#include <iomanip>
#include <iostream>
#include <string>

//1- Create a struct to hold a Scripture. It should have 3 members, a string 
//for the book name, an integer for the chapter, and an integer for the verse.
struct Scripture
{
	std::string bookName;
	int chapter;
	int verse;
};

//Stretch: 3- Create an additional struct called, Insight that has two elements,
// a Scripture (our struct from above), and a string message that contains 
//insight about that scripture. Add a promptInsight and displayInsight function
//that in turn call the functions from above.
struct Insight
{
	Scripture scripture;
	std::string message;
};

//prototyping
void displayScripture(Scripture * scripture);
Scripture promptScripture();
//Stretch Function
void promptScripture(Scripture scriptureArray[], int size);
void displayScriptureArray(Scripture scriptureArray[], int size);
void promptInsight(Insight * insight);
void displayInsight(Insight * insight);

/***********************************************************************
* MAIN:
************************************************************************/
int main()
{
	//2- In main, create a Scripture and assign it the values Alma 31:5. 
	//(Make sure it compiles)
	//Scripture scripture = {};
	//scripture.bookName = "Alma";
	//scripture.chapter = 31;
	//scripture.verse = 5;

	//6- Change main so that it calls promptScripture and then passes the
	//struct to displayScripture. Try different values and make sure they
	//display correctly
	//Scripture newScripture = promptScripture();
	//Scripture *pNewScripture;
	//pNewScripture = &newScripture;
	//displayScripture(pNewScripture);

	// 4-Pass your Alma 31:5 scripture to the display function, run the
	//program and make sure it appears correctly on the screen.
	//Scripture *pScripture;
	//pScripture = &scripture;
	//displayScripture(pScripture);
	
	//STRETCH: 2- Change your program so that it creates an array of 3 
	// scriptures.Then have it loop through and prompt the user for each 
	//of these scriptures, filling the array.Finally have it loop through 
	//and display each of these scriptures.
	Scripture scriptureArray[3] = {};
	promptScripture(scriptureArray, 3);
	displayScriptureArray(scriptureArray, 3);

	//STRETCH: 3- Add a promptInsight and displayInsight function that in 
	// turn call the functions from above.
	Insight insight = {};
	Insight * pInsight;
	pInsight = &insight;
	promptInsight(pInsight);
	displayInsight(pInsight);

	return 0;
}

/***********************************************************************
* displayScripture:
* 3- Write a function : "displayScripture" that displays a given 
* scripture in the form : book chapter : verse(e.g. "John 3:16").
************************************************************************/
void displayScripture(Scripture * scripture)
{
	std::cout << scripture->bookName << " " << scripture->chapter << ":"
		<< scripture->verse << std::endl;
}

/***********************************************************************
* displayScriptureArray:
* Stretch function
************************************************************************/
void displayScriptureArray(Scripture scriptureArray[], int size)
{
	//Finally have it loop through and display each of these scriptures.
	for (int i = 0; i < size; i++)
	{
		std::cout << scriptureArray[i].bookName << " " 
			<< scriptureArray[i].chapter << ":"
			<< scriptureArray[i].verse << std::endl;
	}
}

/***********************************************************************
* promptScripture:
* 5- Write a function: "promptScripture" that prompts the user for a 
* book, chapter, verse, and assigns it to a new scripture.
************************************************************************/
Scripture promptScripture()
{
	Scripture scripture = {};
	//std::cout << "Please enter a book from the scriptures: ";
	//std::cin >> scripture.bookName;
	//STRETCH 1- Change your program so that it handles books with spaces
	//in them (e.g., "1 Nephi"). 
	std::cout << "Please enter a book from the scriptures: ";
	std::getline(std::cin, scripture.bookName);
	
	
	std::cout << "Please enter the chapter: ";
	std::cin >> scripture.chapter;
	std::cout << "Please enter the verse: ";
	std::cin >> scripture.verse;

	return scripture;
}

/***********************************************************************
* STRETCH CHALLENGES:
* After completing the above steps.Make sure that everyone on the entire
* team is to this point and understands the material.Then, if you have 
* time, move onto the following stretch challenges.
************************************************************************/
void promptScripture(Scripture scriptureArray[], int size)
{
	//Have it loop through and prompt the user for each of these 
	// scriptures, filling the array. 
	for (int i = 0; i < size; i++)
	{
		std::cout << "Please enter a book from the scriptures: ";
		std::getline(std::cin, scriptureArray[i].bookName);
		std::cout << "Please enter the chapter: ";
		std::cin >> scriptureArray[i].chapter;
		std::cout << "Please enter the verse: ";
		std::cin >> scriptureArray[i].verse;
		std::cin.ignore();
	}
	
}

/***********************************************************************
* STRETCH CHALLENGE: promptInsight:
* Add a promptInsight and displayInsight function that in turn call the
* functions from above.
************************************************************************/
void promptInsight(Insight * insight)
{
	insight->scripture = promptScripture();
	std::cin.ignore();
	std::cout << "Please enter an insigh about the above scripture: ";
	std::getline(std::cin, insight->message);
}

/***********************************************************************
* STRETCH CHALLENGE: displayInsight:
* Add a promptInsight and displayInsight function that in turn call the
* functions from above.
************************************************************************/
void displayInsight(Insight * insight)
{
	displayScripture(&insight->scripture);
	std::cout << "Insight: " << insight->message << std::endl;

}