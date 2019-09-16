//Irvin Carbajal
//Assignment 3
//Rhonda H


#include <iostream> 
#include <fstream>
#include <sstream>


using namespace std;

struct city //creating the struct for a city.
{
	string cityName;
	string message;
	city *next;
	city()
	{

	};
	city(string initName, city *initNext, string initMessage)
	{
		//assigns the three properties when creating a new struct
		cityName = initName; 
		next = initNext;
		message = initMessage;
	}
};

city *buildNetwork() //builds network
{
	city *c1 = new city("Los Angeles", NULL, "Message");
	city *head = c1; //assigns the head of the list
	city *c2 = new city("Phoenix", NULL, "Message");
	c1 -> next = c2;//moves the NULL down to the end and links the nodes
	city *c3 = new city("Denver", NULL, "Message");
	c2 -> next = c3;
	city *c4 = new city("Dallas", NULL, "Message");
	c3 -> next = c4;
	city *c5 = new city("St. Louis", NULL, "Message");
	c4 -> next = c5;
	city *c6 = new city("Chicago", NULL, "Message");
	c5 -> next = c6;
	city *c7 = new city("Atlanta", NULL, "Message");
	c6 -> next = c7;
	city *c8 = new city("Washington, D.C.", NULL, "Message");
	c7 -> next = c8;
	city *c9 = new city("New York", NULL, "Message");
	c8 -> next = c9;
	city *c10 = new city("Boston", NULL, "Message");
	c9 -> next = c10;

    return head;
}

city *addCity(city *head, city *previous, string cityName) //adds city using head, previous city, and city name as parameters
{

   city* new_city = new city; //creates new city
   new_city -> cityName = cityName; //assings the city name to the city entered in parameter
   city* tmp = new city; //creates new new city to move head 
   tmp = head; 
   while(tmp != NULL && previous != tmp) //goes through the link until it gets to the last city
   {
   		tmp = tmp->next;  
   }
   if(previous == NULL) //used when the new city is being added as the head
   {
      new_city -> next = head;
      head = new_city;
   }
   if(tmp == NULL)
   {
       if(head == NULL)
       { 
           head = new_city;
           new_city -> next = NULL;
       }
       return head;
   }
   else
   {
       new_city -> next = tmp -> next; 
       tmp -> next = new_city;
   }

    return head;
}

void transmitMsg(city *head) //passes on a message across the city towers
{
   	city *transmit = new city;
   	//string filename = "messageln.txt"
   	city *prev = new city;
   	prev = head;
   	transmit = head;
   	ifstream myfile;
   	string line;

    if(head == NULL) //checks for empty list
    {
        cout << "EMPTY" << endl;
    }
   	
   	else 
   	{
   	    myfile.open("messageIn.txt");
   	    if(myfile.is_open())
   	    {
   		    //while(getline(myfile, line))
   		    //{
   		        getline(myfile, line);
   			    stringstream ss(line); //uses string stream to read entire line
   			    string pp;

   			    while(ss >> pp)
   			    {
   			        transmit = head;
   			        prev = head;
   				    while(transmit != NULL) //passes on the message until it gets to the end
   				    {
   					    transmit->message = pp;
   					    cout << transmit -> cityName << " received " << transmit-> message << endl; 
   					    prev = transmit;
   					    transmit = transmit->next;
   					    prev -> message = " ";
   					    
   				    }
                    //transmit->message = line;
   				          //cout << transmit -> cityName << " received " << transmit-> message << endl;
                        
                }
   		    //}
   	    }

   	    else
   	    {
   	    	cout << "File not opened." << endl;
   		}
   	}

}

void printPath(city *head) //prints the name of each city in the network
{
    city *temp = new city;
    temp = head;
    
    if(temp != NULL)
    {   
        cout << "===CURRENT PATH===" << endl;
        while(temp != NULL)
        {
            cout << temp->cityName << " -> ";
            temp = temp -> next;
        }
        cout << " NULL" << endl;
        cout << "==================" << endl;
    }
    
    else
    {
        cout << "EMPTY" << endl;
    }
}

city *search(string name, city *head) //searches for the previous to place new city
{
	city *current = head;
	while(current != NULL)
	{
		if (current -> cityName == name)
		{
			return current;
		}
		current = current -> next;
	}
	return NULL;
}

int main()
{
    city *head = new city;
    city *temp = new city;
    
	j: //used to go back to the menu after every fucntion
	cout << "======Main Menu======" << endl;
	cout << "1. Build Network" << endl;
	cout << "2. Print Network Path" << endl;
	cout << "3. Transmit Message Coast-To-Coast" << endl;
	cout << "4. Add City" << endl;
	cout << "5. Quit" << endl;

	int user;
	cin >> user;

	if(user == 1)
	{
		head = buildNetwork();
		goto j;
	}

	else if(user == 2)
	{
		printPath(head);
		goto j;

	}

	else if(user == 3)
	{
		transmitMsg(head);
		goto j;
	}

	else if(user == 4)
	{
		string cname;
		string pname;
		cout << "Enter a City name:" << endl;
		cin >> cname;
		cout << "Enter a previous City name:" << endl;
		cin >> pname;
		
		temp = search(pname, head); //finds previous city and assigns it to temp

		if(cname == "First")
		{
			addCity(head, NULL, cname);
		}

		else if (temp->next == NULL || pname == "")
		{
			//temp = search(pname, head);
			addCity(head, temp, cname);
		}

		else
		{
		    //temp = search(pname, head);
			addCity(head, temp, cname);
		}

		goto j;

	}

	else if(user == 5)
	{
	    cout << "Goodbye!" << endl;
	}
}
