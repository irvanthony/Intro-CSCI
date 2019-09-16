#include "CommunicationNetwork.h"
#include "CommunicationNetwork.cpp"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]){
    char* filename=argv[1];
    //char filename[]="messageIn.txt";
    CommunicationNetwork commNet;
    string input;
    while(input!="5"){
        cout<<"======Main Menu======"<<endl;
        cout<<"1. Build Network"<<endl;
        cout<<"2. Print Network Path"<<endl;
        cout<<"3. Transmit Message Coast-To-Coast"<<endl;
        cout<<"4. Add City"<<endl;
        cout<<"5. Quit"<<endl;
        cin>>input;
        if (input=="1"){
            commNet.buildNetwork();
        }
        if (input=="2"){
            commNet.printNetwork();
        }
        if (input=="3"){
            commNet.transmitMsg(filename);
        }
        if (input=="4"){
            cout<<"Enter a city name: "<<endl;
            string cityName;
            cin>>cityName;
            cout<<"Enter a previous city name: "<<endl;
            string prevCity;
            cin>>prevCity;
            commNet.addCity(prevCity,cityName);
        }
        if (input=="5"){
        	cout << "Goodbye!" << endl;
        }
    }
    return 0;
}
