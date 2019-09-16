#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

struct Car
{
	string model;
	string make;
	string year;
};

int main(int argc, char *argv[])
{
	fstream fp;
	string data;
	int num_lines = atoi(argv[2]);

	Car carss[num_lines];

	fp.open(argv[1]);

	if (fp.is_open())
	{
		for(int i = 0; i < num_lines; i++)
		{
			getline(fp, data);

			string parse;
			stringstream sp(data);

			sp >> parse;
			carss[i].make = parse;
			sp >> parse;
			carss[i].model = parse;
			sp >> parse;
			carss[i].year = parse;
		}
	}

	else
	{
		cout << "File not opened." << endl;
	}

	fp.close();


	for ( int i = 0; i < num_lines; i++)
	{
		cout << carss[i].make << ", " << carss[i].model << ", " << carss[i].year << endl;

	}





	return 0; 
}