#pragma once
#include <iostream>
#include "Flight.cpp"
using namespace std;
class BusinessClass : public Flight {
private:
	string fruit;
public:
	BusinessClass() : Flight(), fruit("Null") {}
	BusinessClass(int ticket_number, string name,  double price, string snack) : Flight(ticket_number, name, price), fruit(fruit) {}
	~BusinessClass() {

	}
	void set_fruit(string fruit) {
		this->fruit = fruit;
	}
	string get_fruit() {
		return fruit;
	}
	void input() {
		Flight::input();
		cout << "Enter fruit : ";
		cin >> fruit;
	}
	void output() {
		Flight::output();
		cout << fruit << endl;
	}
};