#include "CommunicationNetwork.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

CommunicationNetwork::CommunicationNetwork(){}
CommunicationNetwork::~CommunicationNetwork(){}

void CommunicationNetwork::addCity(string previousCity, string newCity){
    City *temp=new City;
    temp=head;
    while(temp->next!=NULL){
        if (temp->cityName==previousCity && temp->next==NULL){
            City *nCity=new City;
            nCity->cityName=newCity;
            nCity->message="";
            nCity->next=NULL;
            temp->next=nCity;
            head=tail;
            break;
        }
        else if (temp->cityName==previousCity){
            City *nCity=new City;
            nCity->cityName=newCity;
            nCity->message="";
            nCity->next=temp->next;
            temp->next=nCity;
            break;
        }
        temp=temp->next;
    }
}

void CommunicationNetwork::buildNetwork(){
    City *boston=new City("Boston",NULL,"");
    City *newyork=new City("New York",boston,"");
    City *washingtondc=new City("Washington, D.C.",newyork,"");
    City *atlanta=new City("Atlanta",washingtondc,"");
    City *chicago=new City("Chicago",atlanta,"");
    City *stlouis=new City("St. Louis",chicago,"");
    City *dallas=new City("Dalla",stlouis,"");
    City *denver=new City("Denver",dallas,"");
    City *phoenix=new City("Phoenix",denver,"");
    City *losangeles=new City("Los Angeles",phoenix,"");

    head=losangeles;
    tail=boston;
}
void CommunicationNetwork::transmitMsg(char	*filename){
    City *temp=new City;
    temp=head;
    ifstream input;
    input.open(filename);
    string line;
    while(getline(input,line)){
        istringstream lineStream(line);
        while(lineStream.good()){
            string word;
            lineStream >> word;
            temp=head;
            while(temp!=NULL){
                temp->message=word;
                cout<<temp->cityName<<" received "<<temp->message<<endl;
                temp=temp->next;
            }
        }
    }
    if (head == NULL){
		cout << "Empty list" << endl;
	}
}
void CommunicationNetwork::printNetwork(){
    City *temp=new City;
    temp=head;
    cout<<"===CURRENT PATH==="<<endl;
    while(temp != NULL){
        cout<<temp->cityName<<" -> ";
        temp=temp->next;
    }
    cout << "NULL" << endl;
    cout <<	"==================" << endl;
}
