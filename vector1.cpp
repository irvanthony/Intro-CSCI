#include <iostream> 

//include vector class
#include <vector>

using namespace std;

struct adjacent
{
	vertex *v;
	int weight;
}

struct vertex
{
	string key;
	vector<adjacent> adj;
}

int main()
{
	//vector of type vertex, there are 5, they have no key values set
	vector<vertex> v3(5);
	//create an instance of adjacent
	adjacent a;
	a.v = &v3[1];
	a.weight = 50;
	v3[0].adj.push_back(a);



	//v of type of vector
	//<T> is the data tyoe stored in the vector
	//v is the vector of int
	vector<int> v;

	//add to v
	v.push_back(5); //appends a 5 to the v vector
	cout << v.size() << endl;

	//vector is a class
	//it has a constructor
	vector<int> v2(10);
	for(int i = 0; i < v2.size(); i++)
	{
		v2[i] = i;
	}

	cout << v2[5] << endl;

	vector<string> vString(2);
	//fill original vector elements
	vString[0] = "hello";
	vString[1] = "world";
	//add another element to the end of the vector
	vString.push_back("welcome");
	for(int i = 0; i < vString.size(); i++)
	{
		cout << vString[i] << endl;
	}

	//iterator
	vector<string>:: iterator it;
	for(it = vString.begin(); it != vString.end(); it++)
	{
		cout << *it << endl;
	}


}