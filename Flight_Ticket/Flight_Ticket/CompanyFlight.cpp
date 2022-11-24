#pragma once

#include <iostream>
#include "Flight.cpp"
#include "CompanyDEO.cpp"
#include <fstream>

using namespace std;
class CompanyFlgiht : public CompanyDEO {
private:
	string name;
	Flight* flights[100];
	int count = 0;
public:
	CompanyFlgiht() : name("Null") {}
	CompanyFlgiht(string name) : name(name) {}
	~CompanyFlgiht() {

	}
	// Add Flight
	void addAllFlight(Flight* flight) {
		flights[count] = new Flight();
		flights[count] = flight;
		count++;
	}
	// View Flight
	void viewAllTicketFlight(){
		cout << "||====||====||====||====||====||====||====||====||====||";
		cout << "\n\n   Ticket_N0\t  Name\t\tPrice\t\tNeed" << endl;
		for (int i = 0; i < count; i++) {
			flights[i]->output();
		}
		cout << "\n||====||====||====||====||====||====||====||====||====||" << endl;
	}

	// get Flight by id
	int findFlightTicketByNumber(int search_number) {
		for (int i = 0; i < count; i++) {
			if (flights[i]->get_ticket_number() == search_number)
				return i;
		}
		return -1;
	}
	Flight* getFlightTicketByNumber(int search_number) {
		Flight* flight = nullptr;
		for (int i = 0; i < count; i++) {
			if (flights[i]->get_ticket_number() == search_number) {
				return flights[i];
			}
		}
		return flight;
	}
	// edit Flight by id
	///*void editFlightTicket(int flight_number) {
	//	int number;
	//	int found = findFlightTicketByNumber(flight_number);
	//	if (found != -1) {
	//		cout << "Enter New Flight Ticket : ";
	//		cin >> number;
	//		flights[found]->set_ticket_number(number);
	//		cout << "Flight Has Been Edit" << endl;
	//	}
	//	else {
	//		cout << "Not Found" << endl;
	//	}*/
	//}
	void deleteBankAccount() {
		/*int found = findFlightTicketByNumber(flight_number);
		if (found != -1) {
			for (int i = found; i < count; i++) {
				flights[i] = flights[i + 1];
			}
			count--;
			cout << "Flight Has Been Deleted" << endl;
		}
		else {
			cout << "Not found" << endl;
		}*/
		int op;
		int flight_number;
		enum op{BACK_TO_MENU,ID,NAME};
		do {
			cout << "	Delete By	" << endl;
			cout << "1. ID" << endl;
			cout << "2. Name " << endl;
			cout << "0. Back To Menu" << endl;
			cout << "Please Choose Option 0-2 : ";
			cin >> op;
			switch (op) {
			case ID: {
				char sure;
				cout << "Enter Flight Number To Delete : ";
				cin >> flight_number;
				int found = findFlightTicketByNumber(flight_number);
				if (found != -1) {
					cout << "||====||====||====||====||====||====||====||====||====||";
					cout << "\n\n   Ticket_N0\t  Name\t\tPrice\t\tNeed" << endl;
					flights[found]->output();
					cout << "\n||====||====||====||====||====||====||====||====||====||" << endl;
					cout << "Are You Sure Want To Delete Data ??? ( y or n ) : ";
					cin >> sure;
					if (sure == 'y') {
						for (int i = found; i < count; i++) {
							flights[i] = flights[i + 1];
						}
						count--;
						cout << "Flight Has Been Deleted" << endl;
						break;
					}
					else {
						break;
					}
					
				}
				else {
					cout << "Not found" << endl;
				}
				break;
			}
			case NAME:
				break;
			case BACK_TO_MENU:
				break;
			default:
				cout << "Invalid Number..." << endl;
			}
		} while (op != 0);
	}
	void sortFlightTicketByNumber() {
		int op=0;
		char sure;
		enum op{BACK_TO_MENU,DESCENDING,DECREASING};
		do {
			cout << "	Sort By	" << endl;
			cout << "1. Descending Order" << endl;
			cout << "2. Decreasing Order" << endl;
			cout << "0.Back To Menu" << endl;
			cout << "Please Choose Option 0-2 :";
			cin >> op;
			switch (op) {
			case DESCENDING: {
				cout << "Are You Sure Want To Sort Data ??? ( y or n ) : ";
				cin >> sure;
				if (sure == 'y') {
					for (int i = 0; i < count; i++) {
						for (int j = 0; j < count - i - 1; j++) {
							if (flights[j]->get_ticket_number() > flights[j + 1]->get_ticket_number()) {
								Flight* temp = flights[j];
								flights[j] = flights[j + 1];
								flights[j + 1] = temp;
							}
						}
						cout << "Sort Successful" << endl;;
						break;
					}
				}
				else {
					break;
				}
				break;
			}
			case DECREASING:
				break;
			case BACK_TO_MENU:
				break;
			default:
				cout << "Invalid Number..." << endl;
			}
		} while (op != 0);
	}

	void write_file()
	{
		Flight* flight;
		ofstream outFile;
		outFile.open("Flight.txt", ios::binary);
		for (int i = 0; i < count; i++) {
			flight = flights[i];
			outFile.write(reinterpret_cast<char*> (flight), sizeof(Flight));
		}
		outFile.close();
	}
	void read_file()
	{
		Flight flight;
		bool flag = false;
		ifstream inFile;
		inFile.open("Flight.txt", ios::binary);
		if (!inFile)
		{
			cout << "File could not be open !! Press any Key...";
			return;
		}

		while (inFile.read(reinterpret_cast<char*> (&flight), sizeof(Flight)))
		{
			flight.output();

		}
		inFile.close();
	}
	// edit Flight by id and name
	void editFlightTicket() {
		int op;
		int new_ticket_number;
		string new_name;
		double new_price = 0;

		enum op { BACK_TO_MENU, ID, NAME };
		cout << "===	Edit By   ===" << endl;
		cout << "1. ID" << endl;
		cout << "2. Name" << endl;
		cout << "0. Back To Menu" << endl;
		cout << "Please Choose Option (0-2) to Edit : ";
		cin >> op;
		do {
			switch (op)
			{
			case ID: {
				char sure;
				int opp = 0;
				enum opp { BACK_TO_MENU, ID, NAME, PRICE, ALL };
				int flight_number;
				cout << "Enter Number to Edit : ";
				cin >> flight_number;
				int found = findFlightTicketByNumber(flight_number);
				if (found == -1) {
					cout << "Search by Number Not Found " << endl;
					break;
				}
				else {
					do {
						cout << "	Your Date " << endl;
						flights[found]->output();
						cout << "\n\nWhat You Want To Edit ??? " << endl;
						cout << "1. ID" << endl;
						cout << "2. Name" << endl;
						cout << "3. Price" << endl;
						cout << "4. All" << endl;
						cout << "0. Back To Menu" << endl;
						cout << "Please Choose Option (0-4) : ";
						cin >> opp;
						switch (opp)
						{
						case opp::ID: {
							cout << "Enter New Flight Ticket : ";
							cin >> new_ticket_number;
							flights[found]->set_ticket_number(new_ticket_number);
							break;
						}
						case NAME: {
							cout << "Enter New Name : ";
							cin >> new_name;
							flights[found]->set_name(new_name);
							break;
						}
						case PRICE: {
							cout << "Enter New Price : ";
							cin >> new_price;
							flights[found]->set_price(new_price);
							break;
						}
						case ALL: {
							cout << "Enter New Flight Ticket : ";
							cin >> new_ticket_number;
							flights[found]->set_ticket_number(new_ticket_number);
							cout << "Enter New Name : ";
							cin >> new_name;
							flights[found]->set_name(new_name);
							cout << "Enter New Price : ";
							cin >> new_price;
							flights[found]->set_price(new_price);
							break;
						}
						case BACK_TO_MENU: {
							break;
						}
						default:
							cout << "Invalid number " << endl;
							break;
						}
						cout << "Are you sure want to edit (y or n)??? : ";
						cin >> sure;
					} while (sure != 'y');
				}
				break;
			}
			case NAME: {
				break;
			}
			case BACK_TO_MENU: {
				break;
			}
			default:
				cout << "Invalid Number " << endl;
			}
			break;
		} while (op != 0);
	}
	void searchFlightTicket() {
		int op;
		enum op { BACK_TO_MENU, ID, NAME };
		cout << "	=== Search By ===" << endl;
		cout << "1.  ID" << endl;
		cout << "2.  Name" << endl;
		cout << "0.  Back To Menu" << endl;
		cout << "Please Choose Option (0-2) : ";
		cin >> op;
		do {
			switch (op)
			{
			case op::ID: {
				int search_number;
				cout << "Enter Flight Number to Search : ";
				cin >> search_number;
				int found = findFlightTicketByNumber(search_number);
				if (found == -1) {
					cout << "Search Not Found" << endl;
					break;
				}
				else {
					cout << "Search Not Found" << endl;
					cout << "Search Successfull" << endl;
					cout << "Your Search Result " << endl;
					cout << "======================" << endl;
					flights[found]->output();
					break;
				}
				break;
			}
			case op::NAME: {
				break;
			}
			case op::BACK_TO_MENU: {
				break;
			}
			default:
				cout << "Invalid Number" << endl;
				break;
			}
		} while (op != 0);

	}
};
