#pragma once
#include <iostream>
#include "Flight.cpp"
using namespace std;
class EconomyClass : public Flight{
private:
	string snack;
public:
	EconomyClass() : Flight(), snack("Null") {}
	EconomyClass(int ticket_number, string name,double price, string snack) : Flight(ticket_number,name,price), snack(snack) {}
	~EconomyClass() {

	}
	void set_snack(string snack) {
		this->snack = snack;
	}
	string get_snack() {
		return snack;
	}
	void input() {
		Flight::input();
		cout << "Enter Snack : ";
		cin >> snack;
	}
	void output() {
		Flight::output();
		cout << snack << endl;
	}
};