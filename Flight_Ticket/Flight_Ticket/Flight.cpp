#pragma once
#include <iostream>
using namespace std;
class Flight {
private:
	int ticket_number;
	string name;
	double price;
public:
	Flight() : ticket_number(0), name("Null"), price(0) {}
	Flight(int ticket_number, string name, double price) : ticket_number(ticket_number), name(name), price(price) {}
	~Flight() {

	}
	void set_ticket_number(int ticket_number) {
		
		/*if (ticket_number < 0) {
			throw"Invalid Number";
		}
		else {
			this->ticket_number = ticket_number;
		}*/
		this->ticket_number = ticket_number;
	}
	int get_ticket_number() {
		return ticket_number;
	}
	void set_name(string name) {
		this->name = name;
	}
	string get_name() {
		return name;
	}
	void set_price(double price) {
		if (price > 0) {
			this->price = price;
		}
	}
	double get_price() {
		return price;
	}
	virtual void input() {
		//try {
		//	cout << "Enter ticket_number :  ";
		//	cin >> ticket_number;
		//	set_ticket_number(ticket_number);
		//	cout << "Enter Name : ";
		//	cin >> name;
		//	cout << "Enter price : ";
		//	cin >> price;
		//	set_price(price);
		//}
		//catch(char* gen){  //gen = throw message;
		//	cout << gen;
		//}
		cout << "Enter ticket_number :  ";
		//validation
		while (!(cin >> ticket_number)) {
			cin.clear();
			cin.ignore(1000,
				'\n');
			cout << "Wrong Data Number Input, Try again : ";
		}
		cout << "Enter Name : ";
		cin >> name;
		cout << "Enter price : ";
		//validation
		while (!(cin >> price)) {
			cin.clear();
			cin.ignore(1000,
				'\n');
			cout << "Wrong Data Number Input, Try Again : ";
		}
	}
	virtual void output() {
		/*cout << "Ticket Number : " << ticket_number << endl;
		cout << "Name : " << name << endl;
		cout << "Price : " << price << endl;*/
		cout << "   "<<ticket_number  << "\t\t  " << name << "\t\t"<<"  " << price << "\t\t"<<"  ";
	}
};
