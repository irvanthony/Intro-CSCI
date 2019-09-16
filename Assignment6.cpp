#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void displayMenu()
{
	cout << "======Main Menu======" << endl;
	cout << "1. Find a movie" << endl;
	cout << "2. Rent a movie" << endl;
	cout << "3. Print the inventory" << endl;
	cout << "4. Delete a movie" << endl;
	cout << "5. Count the movies" << endl;
	cout << "6. Quit" << endl;
}

int main()
{
	MovieTree mt;

	string stringInput;
	int intInput = 0;
	bool quit = false;

	ifstream inFile("Assignment6Movies.txt");
	if (inFile.fail()) //if file fails to open
	{ 
		cout << "File failed to open" << endl;
	}
	else //if file opens properly
	{ 
		string line;
		string word;

		while(getline(inFile,line))
		{
			stringstream ss(line);
			getline(ss, word, ',');
			int ranking = stoi(word);
			getline(ss, word, ',');
			string title = word;
			getline(ss, word, ',');
			int year = stoi(word);
			getline(ss, word, ',');
			int quantity = stoi(word);
			mt.addMovieNode(ranking, title, year, quantity);
		}

		while(quit == false)
		{
			displayMenu();
			getline(cin, stringInput);
			intInput = stoi(stringInput);

			if(intInput == 1) //find movie
			{
				cout << "Enter title:" << endl;
				getline(cin, stringInput);
				mt.findMovie(stringInput);
			}

			else if(intInput == 2) //rent movie
			{
				cout << "Enter title:" << endl;
				getline(cin, stringInput);
				mt.rentMovie(stringInput);
			}

			else if(intInput == 3) //print inventory
			{
				mt.printMovieInventory();
				//cout << "Movie: " << node->title << " " << node->quantity << endl;
			}

			else if(intInput == 4) //delete
			{
				cout << "Enter title:" << endl;
				getline(cin, stringInput);
				mt.deleteMovieNode(stringInput);
			}

			else if(intInput == 5) //count movies
			{
				cout << "Tree contains: " <<mt.countMovieNodes() << " movies." << endl;	
			}

			else if(intInput == 6) //quit
			{
				quit = true;
				cout << "Goodbye!" << endl;
			}

		}
		return 0;
	}
}