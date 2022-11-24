#pragma once

#include <iostream>
#include "CompanyFlight.cpp"
#include "Flight.cpp"
#include "EconomyClass.cpp"
#include "BusinessClass.cpp"
#include "FirstClass.cpp"
#include "CompanyDEO.cpp"
#include "User.cpp"
#include "UserManager.cpp"

using namespace std;
class RunApp {
public:
	void user() {
		char ch;
		int num = 0;
		int op = 0;
		UserManager userManager;
		do
		{
			cout << "\n\n==================================================" << endl;
			cout << "		Admin Menu" << endl;
			cout << "1. Add New User" << endl;
			cout << "2. View All User" << endl;
			cout << "3. Edit User" << endl;
			cout << "4. Delete User" << endl;
			cout << "0. Exit" << endl;
			cout << "Please Choose Option 0 - 4 :  ";
			cin >> ch;
			switch (ch)
			{
			case '1': {
				User user;
				user.inputUser();
				userManager.addUser(user);
				break;
			}
			case '2':
				userManager.viewUser();
				break;
			case '3': {
				string username;
				cout << "Enter username:";
				cin >> username;
				userManager.editUser(username);
				break;
			}
			case '4': {
				string username;
				cout << "Enter username:";
				cin >> username;
				userManager.deleteUser(username);
				break;
			}
			default:
				cout << "\a";
			}
			cin.ignore();
			cin.get();
		} while (ch != '0');
	}
	void app() {
		int count = 0;
		int menu_choice = 0;
		int search_number = 0;
		int index = 0;
		char question;
		enum menu_name { EXIT, ADD, VIEW, SEARCH, EDIT, DELETE, SORT, SAVE, LOAD };
		char type_choice;
		enum type_name { BACK_TO_MENU = '0', ECONOMY = '1', BUSINESS = '2', FIRST = '3' };
		CompanyFlgiht companyFlight("GEN");
		Flight* flight = nullptr;
		EconomyClass* economyClass = nullptr;
		BusinessClass* businessClass = nullptr;
		FirstClass* firstClass = nullptr;
		do {
			system("cls");
			cout << "\n============================" << endl;
			cout << "	   MENU   " << endl;
			cout << "1. Add Ticket " << endl;
			cout << "2. View Ticket " << endl;
			cout << "3. Search Ticket" << endl;
			cout << "4. Edit Ticket" << endl;
			cout << "5. Delete Ticket " << endl;
			cout << "6. Sort Ticket" << endl;
			cout << "7. Save Data Into File" << endl;
			cout << "8. Load Data Into File" << endl;
			cout << "0. Exit" << endl;
			cout << "============================" << endl;
			cout << "Please Choose Option 0 - 8 : ";
			cin >> menu_choice;
			system("cls");
			switch (menu_choice) {
			case menu_name::ADD:
				do {
					cout << "\n==========================" << endl;
					cout << "	TICKET_TYPE" << endl;
					cout << "1. Economy Class" << endl;
					cout << "2. Business Class " << endl;
					cout << "3. First Class " << endl;
					cout << "0. Back To MENU" << endl;
					cout << "==========================" << endl;
					cout << "What is your ticket type (0-3) ? : ";
					cin >> type_choice;
					switch (type_choice) {
					case type_name::ECONOMY: {
						economyClass = new EconomyClass();
						economyClass->input();
						companyFlight.addAllFlight(economyClass);
						break;
					}
					case type_name::BUSINESS: {
						businessClass = new BusinessClass();
						businessClass->input();
						companyFlight.addAllFlight(businessClass);
						break;
					}
					case type_name::FIRST: {
						firstClass = new FirstClass();
						firstClass->input();
						companyFlight.addAllFlight(firstClass);
						break;
					}
					case type_name::BACK_TO_MENU: {
						app();
						break;
					}
					default:
						cout << "Invalid Number..." << endl;
					}
					cout << "Do you want to continue ( Y or N ) ??? : ";
					cin >> question;
				} while (question != 'n');
				break;
			case menu_name::VIEW:
				companyFlight.viewAllTicketFlight();
				break;
			case menu_name::SEARCH:
				companyFlight.searchFlightTicket();
				break;
			case menu_name::EDIT:
				/*cout << "Enter Flight Number to Search : ";
				cin >> search_number;
				companyFlight.editFlightTicket(search_number);*/
				companyFlight.editFlightTicket();
				break;
			case menu_name::DELETE:
				/*cout << "Enter Flight Number to Search : ";
				cin >> search_number;
				companyFlight.deleteBankAccount(search_number);*/
				companyFlight.deleteBankAccount();
				break;

			case menu_name::SORT:
				companyFlight.sortFlightTicketByNumber();
				break;

			case menu_name::SAVE:
				companyFlight.write_file();
				cout << "Save Successful" << endl;
				break;
			case menu_name::LOAD:
				companyFlight.read_file();
				cout << "Load File Successful" << endl;
				break;

			case menu_name::EXIT:
				break;

			default:
				cout << "Invalid Number..." << endl;
			}
			cin.ignore();
			cin.get();
		} while (menu_choice != 0);
		
	}
};
