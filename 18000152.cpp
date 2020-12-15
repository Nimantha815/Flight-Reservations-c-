#include<bits/stdc++.h>
#include<conio.h>
#include<string.h>
#include<sstream>
#define ROWS 64
#define TYPES 10
#define SEATS 6
#define FLIGHTS 20

using namespace std;

int numOfFlights;
int rowList[20];

class availableSeats
{
public:

    string rowNumber;
    string classType;
    string seats;

    avilableSeats()
    {
    }
};

class flight
{
public:

    string flight_Number;
    string date_Time;
    string departure_Airport;
    string arrival_Airport;
    availableSeats availableSeats[ROWS];

    flight()
    {
    }
};

flight fList[FLIGHTS];
string flights[FLIGHTS][ROWS];



void openFile()
{
    fstream file;
	file.open("Flights.txt");
	string line;
	int i=0,j=0,c=0;
	
	while(getline(file,line))
    {
		if(!line.empty())
    	{
    		flights[i][j]=line;
			j++;
		}
		else
		{
			j=0;
			i++;
		}
    }
    numOfFlights=i+1;
    
    int l,n,f,arr[i+1],r=0;
    for(l=0;l<i+1;l++)
   	{
   		n=0,f=0;
		fList[l].flight_Number=flights[l][n];
		fList[l].date_Time=flights[l][n+1];
		fList[l].departure_Airport=flights[l][n+2];
		fList[l].arrival_Airport=flights[l][n+3];

		n=4;
		
		while(!flights[l][n].empty())
		{
			int pos;
			pos=flights[l][n].find(" ");
			fList[l].availableSeats[f].rowNumber=flights[l][n].substr(0,pos);
			fList[l].availableSeats[f].classType=flights[l][n].substr(pos+1,1);
			fList[l].availableSeats[f].seats=flights[l][n].substr(pos+3);
			f++;
			n++;
		}
		rowList[r]=f;
		r++;
	}
}
int main()
{
	ofstream newfile("Update_file.txt");
    openFile();
    
    int ch;
    while(ch!=5)
    {
    	cout << "\t\t\t\t\t\t----------------------------\n" << endl;
    	cout << "\t\t\t\t\t\t---Virgin Airline Service---\n" << endl;
    	cout << "\t\t\t\t\t\t----------------------------\n" << endl;
    	cout << "\t\n" << endl;
    	cout << "1. ------Available Flights-------\n2. -------View A Flight-------\n3. -------View Available Seats-------\n4. -------Book A Seat-------\n5. -------Exit--------" << endl;
    	cout << "\nEnter Your Choice : ";
    	cin >> ch;
    	
    	switch(ch)
    	{
    		case 1 : //////////////////////////////////////////////////////////////////////////////////Display available function
			{
			cout << "\n\t---Available Flights---\n" << endl;
	
			int k,m,count=0;
	
			for(k=0;k<numOfFlights;k++)
			for(int g=0;g<rowList[k];g++)
				if(!fList[k].availableSeats[g].seats.empty())
					count++;

				if(count>0)
					{
						for(k=0;k<numOfFlights;k++)
						{
						cout << "Flight Number : " << fList[k].flight_Number <<endl;
						cout << "Departure Date & Time : " << fList[k].date_Time << endl;
						cout << "Departure Airport : " << fList[k].departure_Airport << endl;
						cout << "Arrival Airport : " << fList[k].arrival_Airport << endl;
						cout << "\tAvailable Seats With Their Rows & Classes" << endl;
		
						for(int g=0;g<rowList[k];g++)
							{
								if(!fList[k].availableSeats[g].seats.empty())
									{
										cout << fList[k].availableSeats[g].rowNumber << " " << fList[k].availableSeats[g].classType << " " << fList[k].availableSeats[g].seats << endl;
									}
							}
								cout << endl;
		
	}
	}
	}
						break;
			case 2 :///////////////////////////////////////////////////////////////////////////////////View Flight function
			 {
			string flightNumber,type,classTypes[TYPES];
			int seats[TYPES],count=0,j=0,k=0,x;
	
			cout << "\n\t---View Flights---\n" << endl;
			cout << "Enter The Flight Number : ";
			cin >> flightNumber;
	
			int e,a=0;
			for(e=0;e<numOfFlights;e++)
			if(fList[e].flight_Number==flightNumber)
			{
			a=1;
			break;
			}
	
			type=fList[e].availableSeats[0].classType;
			classTypes[k]=fList[e].availableSeats[0].classType;
			k++;
	
			if(a==1){
				for(int i=0;i<rowList[e];i++)
				if(fList[e].availableSeats[i].classType==type)
				count=count+fList[e].availableSeats[i].seats.length();
				else{
					seats[j]=count;
					j++;
					classTypes[k]=fList[e].availableSeats[i].classType;
					k++;
					type=fList[e].availableSeats[i].classType;
					count=fList[e].availableSeats[i].seats.length();
					}
				seats[j]=count;
		
				cout << "Flight Number : " << fList[e].flight_Number <<endl;
				cout << "Departure Date & Time : " << fList[e].date_Time << endl;
				cout << "Departure Airport : " << fList[e].departure_Airport << endl;
				cout << "Arrival Airport : " << fList[e].arrival_Airport << endl;
				cout << "\tNumber Of Seats Available In Each Class" << endl;
	
				for(int p=0;p<j+1;p++)
					cout << "Class " << classTypes[p] << " : " << seats[p] << endl;
	
					cout << "\tAvailable Seats With Their Rows & Classes" << endl;
	
					for(x=0;x<rowList[e];x++)
						if(!fList[e].availableSeats[x].seats.empty())
							cout << fList[e].availableSeats[x].rowNumber << " " << fList[e].availableSeats[x].classType << " " << fList[e].availableSeats[x].seats << endl;
	
					cout << endl;
					}
				else
					cout << "Sorry..The Flight You Looked For Is Not Available.\n" << endl;
		
				}
			break;
			
			case 3 : ///////////////////////////////////////////////////////////////////////Available seats function
			{
			string flightNumber;
			int numberOfSeats;
			cout << "\n\t---Available Seats---\n" << endl;
			cout << "Enter The Flight Number : ";
			cin >> flightNumber;
			int e,a=0,count=0;
			for(e=0;e<numOfFlights;e++)
				if(fList[e].flight_Number==flightNumber)
				{
					a=1;
					break;
				}
		
				if(a==1)
				{
				cout << "Enter The Number Of Seats You Want : ";
				cin >> numberOfSeats;
		
				for(int b=0;b<rowList[e];b++)
				{
					count=count+fList[e].availableSeats[b].seats.length();
				}
				if(count>=numberOfSeats)
				{
					cout << "Flight Number : " << fList[e].flight_Number <<endl;
					cout << "Date & Time : " << fList[e].date_Time << endl;
					cout << "Departure Airport : " << fList[e].departure_Airport << endl;
					cout << "Arrival Airport : " << fList[e].arrival_Airport << endl;
	
					cout << "\tAvailable Seats With Their Rows & Classes" << endl;
	
					for(int x=0;x<rowList[e];x++)
						 if(!fList[e].availableSeats[x].seats.empty())
							cout << fList[e].availableSeats[x].rowNumber << " " << fList[e].availableSeats[x].classType << " " << fList[e].availableSeats[x].seats << endl;
		
				cout << endl;
				}
				else
					cout << "Sorry..Requested Number Of Seats Are Not Available.\n" << endl;
				}
				else
					cout << "Sorry..The Flight You Looked For Is Not Available.\n" << endl;
				}
				break;
			case 4 : ////////////////////////////////////////////////////////////////////////////////////////Seat booking function
				{
				
				
				string flightNumb,row;
				char seat;
				cout << "\n\t---Seats Booking---\n" << endl;
				cout << "Enter The Flight Number That you want : ";
				cin >> flightNumb;
				cout << "Enter The Location Of Seat That You Prefer To Book : ";
				cin >> row >> seat;
	
				int a=0,b=0,c=0,e,w,y;
	
				for(e=0;e<numOfFlights;e++)
					if(fList[e].flight_Number==flightNumb)
					{
					a=1;
					break;
					}
			
				if(a==1)
					for(w=0;w<rowList[e];w++)
						if(fList[e].availableSeats[w].rowNumber==row)
						{
						b=1;
						break;
						}		

						if(a==1)
						if(b==1)
					for(y=0;y<6;y++)
						{
						if(fList[e].availableSeats[w].seats[y]==seat)
						{
							c=1;
							fList[e].availableSeats[w].seats.erase(y,1);
							break;
						}
						}
				
				if(a==1)
				if(b==1)
				if(c==1)
				cout << "Your Requested Seat Is Booked.\n" << endl;
			else
				cout << "Your Requested Seat Is Already Booked.\n" << endl;
			else
				cout << "Your Requested Row Is Already Full.\n" << endl;
			else
			cout << "The Flight You Looked For Is Not Available.\n" << endl;
		
			cout << endl; 
			}
			break;
			case 5:			///////////////////////////////////////////////////////////////////Exit function
			{
				int y=0;
				int z=0;
				for(int y=0;y<numOfFlights;y++){
					newfile<<fList[y].flight_Number<<endl;
					newfile<<fList[y].date_Time<<endl;
					newfile<<fList[y].departure_Airport<<endl;
					newfile<<fList[y].arrival_Airport<<endl;
					for(int z=0;z<20;z++){
						if(fList[y].availableSeats[z].rowNumber.empty()){
							newfile<<endl;
							break;
						}
						else{
							newfile<<fList[y].availableSeats[z].rowNumber<<" "<<fList[y].availableSeats[z].classType<<" "<<fList[y].availableSeats[z].seats<<endl;
						}
					}
				}
				break;
				
					cout<<"-----------EXIT----------"<<endl;
					return 0;
			}
				
			default: cout << "---------INVALID OPTION---------- \n" << endl;
		}
	}

    return 0;
}
