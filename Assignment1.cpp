//Irvin A Carbajal
//Assignment 1
//Rhonda Hoenigman


#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

struct item
{
	//giving the struct the three traits of item type, price, and whether it's wanted or for sale
	string type;
	int price;
	int demand;
};

void onSale(item items[], int list)
{	
	//loop for all unmatched items to be posted as "for sale" or "wanted"
	for(int i = 0; i < list; i++)
	{
		if (items[i].demand == 0) // 0 means it is for sale
		{
			cout << items[i].type << ", " << "for sale" << ", " << items[i].price << endl;
		}

		else if(items[i].demand == 1) // 1 means it is wanted
		{
			cout << items[i].type << ", " << "wanted" << ", " << items[i].price << endl;
		}

		else // do nothing if not 0 or 1
		{

		}
	}
}

int main(int argc, char *argv[]) //command line arguements (name of file)
{
	//set a max array size of 100 
	const int arrayMax = 100;
	item itms[arrayMax];

	//open file given in command line 
	ifstream fp;
	int i = 0;

	fp.open(argv[1]);
	if(fp.is_open())
	{
		string line;

		//while loop to read all lines of file
		while(getline(fp, line, '\n'))
		{
			string parse;
			stringstream ss(line); //stringsteam to split each line into type, whether its wanted or for sale, and the price.

			ss >> parse;

			if(parse == "chicken,") //since string stream splits at a spcae and not a delimeter, the ',' has to be included
			{
				itms[i].type = "chicken";
			}

			else if(parse == "microwave,")
			{
				itms[i].type = "microwave";
			}

			else if(parse == "truck,")
			{
				itms[i].type = "truck";
			}

			else if(parse == "dresser,")
			{
				itms[i].type = "dresser";
			}

			else if(parse == "bike,")
			{
				itms[i].type = "bike";
			}

			else
			{
				cout << "Type not found." << endl;
			}

			ss >> parse;

			if(parse == "for")
			{
				itms[i].demand = 0;
				ss >> parse; //extra parse since "for sale," has a space that string stream splits at
				ss >> parse;
				itms[i].price = stoi(parse.c_str()); // converting the last string into an integer for the price
			}

			else if (parse == "wanted,")
			{
				itms[i].demand = 1;
				ss >> parse;
				itms[i].price = stoi(parse.c_str()); // converting the last string into an integer for the price
			}

			else
			{
				cout << "Demand not found." << endl;
			}

			for(int j = 0; j < i; j++)
			{
				if(itms[i].type == itms[j].type) //checking if item types match
				{
					if(itms[i].demand != itms[j].demand) //making sure that two items that are both "for sale" or both "wanted" aren't matched
					{
						if(itms[i].demand == 0) //checking if its "for sale"
						{
							if (itms[i].price <= itms[j].price) //checking that price is less or equal to
							{
								cout << itms[i].type << " " << itms[i].price << endl;

								for(int l = j; l < i; l++)
								{
									itms[l] = itms[(l+1)]; // elimination of one element in array and shifting the values over by one
								}

								i -= 1;
								i -= 1;

								break;
							}
							else 
							{
								continue;
							}
						}

						else if(itms[i].demand == 1) 
						{
							if(itms[i].price >= itms[j].price) //checks that the price is greater or equal to tp satisfy the trade,
							{
								cout << itms[i].type << " " << itms[j].price << endl;

								for(int k = j; k < i; k++)
								{
									itms[k] = itms[(k+1)]; // elimination of one element in array and shifting the values over by one
								}

								i -= 1;
								i -= 1;

								break;
							}

							else
							{
								continue;
							}
						}

						else
						{
							cout << "Error" << endl;

						}
					}

					else
					{
						continue;
					}
				}

				else
				{
					continue;
				}
			}
			i++;
		}
	}

	else
	{
		cout << "File not opened." << endl; //just in case file doesn't open
	}

	fp.close();

	cout << "#" << endl;
	onSale(itms, i); //prints the unmatched items
	cout << "#" << endl;


}