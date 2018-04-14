#include <fstream>
#include <iostream>
#include <iomanip>
#include "graph.h"
#include <string>
#define MAX_SIZE 100
using namespace std;

int main()
{
	GRAPH* g = NULL;

	ifstream file;
	int stationNumber, departStation, arriveStation, departTime, arriveTime, travelTime;
	string stationName[MAX_SIZE];

	file.open("stations.dat");
	
	int stations = 0;
	
	while(file >> stationNumber){
		file >> stationName[stationNumber];
		stations++;
	}
	
	file.close();

	file.open("trains.dat");

	while(file >> departStation){
		file >> departStation;
		file >> departStation;
		file >> departStation;
	}

	file.close();

	file.open("trains.dat");

	if (!file.is_open())
	{
		cout << "Error: Failed to open input file\n";
		return 0;
	}
	file >> stations;
	g = new GRAPH(stations);

	while (file >> departStation)
	{                
		file >> arriveStation;
		file >> departTime;
		file >> arriveTime;
		int min1 = (arriveTime / 100) * 60 + (arriveTime % 100);
		int min2 = (departTime / 100) * 60 + (departTime % 100);
		travelTime = (min1 - min2);
		g->setEdge(departStation, arriveStation, travelTime, stationName, departTime, arriveTime);
	}
	file.close();

	bool done = false;
	bool found = false;
	int userNum, numberCin, departCin, arriveCin, user;
	string stationCin;	
	
	cout<<"\n\n=========================================================\n";
	cout<<"(kur)     TIS' THE TRAIN TRACKING exTRAVAGANCE\n";
	cout<<"=========================================================\n\n";

	while(!done){
	//ask user	
	cout<<"Choose an option below: (enter the corresponding number)\n";
	cout<<"(1) - print a complete train itinerary\n";
	cout<<"(2) - print a specific train's itinerary\n";
	cout<<"(3) - look up a station by number\n";
	cout<<"(4) - look up a station by name\n";
	cout<<"(5) - check if a(n) (in)direct route exists\n";
	cout<<"(6) - shortest path to/from source/destination\n";
	cout<<"(7) - exit\n";

	//user response
	cin >> userNum;
	cout<<endl;
		
		switch (userNum) 
		{
			case 1:
				g->printGraph();
				break;

			case 2:
				cout<<"Which train's itinerary are you printing?\n";
				cin>>numberCin;
				cout << endl << endl;
				g->printGraphParameter(numberCin);
				break;

			case 3:
				cout << "Enter Station ID\n";
				cin >> numberCin;
				cout << endl << "Station ID " << numberCin << " : " << stationName[numberCin] << endl << endl;
				break;

			case 4:
				cout << "Enter Station Name\n";
				cin >> stationCin;

				for(int i = 0; i <= stations; i++){
					if(stationCin.compare(stationName[i]) == 0){
						cout<<endl<<"Train ID " << i << " : " << stationName[i] << endl << endl;
						found = true;
					}
				}
				if(found == false){
					cout<<"Error: The station name you entered was not found.\n\n";
				}	
				break;

			case 5: 
				cout<<"Departure station number: ";
				cin>>departCin;
				cout<<"Arrival station number: ";
				cin>>arriveCin;
				cout<<"\nA ";
					if(g->isAdjacent(departCin,arriveCin)){
						cout<<"direct";
					}
					else{
						cout<<"non direct";
					}
				cout<< " route from "<<departCin<<" to "<<arriveCin;
					if(g->isReachable(departCin, arriveCin)){
						cout<<" does";
					}
					else{
						cout<<" does not";
					}
				cout<<" exist."<< endl << endl;
				break;

			case 6:
				cout<<"Departure station number: ";
				cin>>departCin;
				cout<<"Arrival station number: ";
				cin>>arriveCin;
				if(g->isReachable(departCin, arriveCin)){
					cout<<endl<<"Depart from "<<stationName[departCin]<<" to "<<stationName[arriveCin]<<" in ";
					g->dijkstra(departCin,arriveCin);
						if(g->isAdjacent(departCin, arriveCin)){
							cout<<" not including layovers.\n\n";
						}
						else{
							cout<<" including layovers.\n\n";
						}
					g->printGraphParameter(departCin);
					g->printGraphParameter(arriveCin);
				}
				else{
					cout << "No route exists.\n\n";
				}
				break;
			case 7:
				cout<<"	                 ''~``                         \n";
				cout<<"                        ( o o )                        \n";
				cout<<"+------------------.oooO--(_)--Oooo.------------------+\n";
				cout<<"|                       Goodbye                       |\n";
				cout<<"|                    .oooO                            |\n";
				cout<<"|                    (   )   Oooo.                    |\n";
				cout<<"+---------------------) (----(   )--------------------+\n";
				cout<<"                      (_)    ) /                       \n";
				cout<<"                             (_/                       \n";
				done = true;
				break;
			default:
				cout << "Error: Not a correct option. (numbers 1-7 are allowed)\n";
		}
	}

	
}
